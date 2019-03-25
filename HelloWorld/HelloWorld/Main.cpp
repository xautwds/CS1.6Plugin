#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <thread>
#include <wingdi.h>

//#pragma comment(linker, "/subsystem:/'windows/' /entry:/'mainCRTStartup/'" )

DWORD GetProcessID(wchar_t *FileName)
{
    HANDLE hProcess;
    PROCESSENTRY32 pe;
    BOOL bRet;
    //进行进程快照
    hProcess = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    pe.dwSize = sizeof(PROCESSENTRY32W);
    //开始进程查找
    bRet = ::Process32First(hProcess, &pe);
    //循环比较，得出ProcessID
    while (bRet)
    {
        if (wcscmp(FileName, pe.szExeFile) == 0)
            return pe.th32ProcessID;
        else
            bRet = ::Process32Next(hProcess, &pe);
    }
    return 0;
}

//无限金钱
bool WINAPI Money(HANDLE handle)
{
    DWORD Buffer = 0;
    DWORD My_New = 16000;

    while (1)
    {
        ReadProcessMemory(handle, LPVOID(0x025069BC), &Buffer, sizeof(DWORD), NULL);
        DWORD Base = Buffer + (0x7C);
        ReadProcessMemory(handle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        Base = Buffer + (0x1CC);
        ReadProcessMemory(handle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(handle, LPVOID(Buffer), &My_New, sizeof(DWORD), NULL);

        WriteProcessMemory(handle, LPVOID(0x01400000 + (0x61B9FC)), &My_New, sizeof(DWORD), NULL);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return true;
}

//无限子弹
bool WINAPI Bullet(HANDLE handle)
{
    DWORD Buffer = 0;
    DWORD My_New = 30;

    while (1)
    {
        ReadProcessMemory(handle, LPVOID(0x025069BC), &Buffer, sizeof(DWORD), NULL);
        DWORD Base = Buffer + (0x7C);
        ReadProcessMemory(handle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        Base = Buffer + (0x5EC);
        ReadProcessMemory(handle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(handle, LPVOID(Buffer + (0xCC)), &My_New, sizeof(DWORD), NULL);
    }
    return true;
}

//锁血,目前无法找到对应的内存
bool WINAPI LockBlood(HANDLE handle)
{
    DWORD Buffer = 0;
    DWORD My_New = 1120403456;

    while (1) {
        ReadProcessMemory(handle, LPVOID(0x025069BC), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(handle, LPVOID(Buffer + (0x1E0)), &My_New, sizeof(DWORD), NULL);
    }
    return false;
}

//穿墙
bool WINAPI ThroughWall(HANDLE handle) {
    std::cout << "wall" << std::endl;
    DWORD Buffer = 0;
    DWORD My_New = 3;

    ReadProcessMemory(handle, LPVOID(0x025069BC), &Buffer, sizeof(DWORD), NULL);
    WriteProcessMemory(handle, LPVOID(Buffer + (0X2C4)), &My_New, sizeof(DWORD), NULL);
    return false;
}

//飞天
DWORD WINAPI Fly(HANDLE handle)
{
    DWORD Buffer = 0;

    DWORD My_New = 1132068864;
    while (1) {
        ReadProcessMemory(handle, LPVOID(0x025069BC), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(handle, LPVOID(Buffer + (0X1FC)), &My_New, sizeof(DWORD), NULL);
    }
    return 0L;
}

//遁地
DWORD WINAPI Down(HANDLE handle)
{
    DWORD Buffer = 0;
    DWORD My_New = 3279552512;

    while (1) {
        ReadProcessMemory(handle, LPVOID(0x025069BC), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(handle, LPVOID(Buffer + (0X1FC)), &My_New, sizeof(DWORD), NULL);
    }
    return 0L;
}

//无后座力
DWORD WINAPI Recoil(HANDLE handle)
{
    DWORD Buffer = 0;
    DWORD My_New1 = 0;
    DWORD My_New2 = 30;

    while (1) {
        ReadProcessMemory(handle, LPVOID(0x025069BC), &Buffer, sizeof(DWORD), NULL);
        DWORD Base = Buffer + (0x7C);
        ReadProcessMemory(handle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        Base = Buffer + (0x5EC);
        ReadProcessMemory(handle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(handle, LPVOID(Buffer + (0x100)), &My_New1, sizeof(DWORD), NULL);

        ReadProcessMemory(handle, LPVOID(0x025069BC), &Buffer, sizeof(DWORD), NULL);
        Base = Buffer + (0x7C);
        ReadProcessMemory(handle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        Base = Buffer + (0x5EC);
        ReadProcessMemory(handle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(handle, LPVOID(Buffer + (0xEC)), &My_New2, sizeof(DWORD), NULL);
    }
    return 0L;
}

//DWORD WINAPI SetCross(LPVOID lpParam) {
//    while (true)
//    {
//        int crosssize = 23;
//        int crossweight = 1.1;
//
//        HWND hwnd = ::FindWindow(NULL, L"Counter-Strike");
//        if (::IsWindow(hwnd))
//        {
//            HDC hdc = ::GetDC(hwnd);	//游戏窗口
//            CDC cdc;
//            CDC dlgcdc;
//            cdc.Attach(hdc);
//
//            HPEN hpen = ::CreatePen(PS_SOLID, crossweight, RGB(red, green, blue));
//            HPEN hpenold = (HPEN)cdc.SelectObject(hpen);
//            RECT rect;
//            int width, height;
//
//            ::GetClientRect(hwnd, &rect);
//            width = rect.right - rect.left;
//            height = rect.bottom - rect.top;
//
//            cdc.MoveTo(width / 2 - crosssize, height / 2);
//            cdc.LineTo(width / 2 - 6, height / 2);
//            cdc.MoveTo(width / 2 + 6, height / 2);
//            cdc.LineTo(width / 2 + crosssize, height / 2);
//            cdc.MoveTo(width / 2, height / 2 - crosssize);
//            cdc.LineTo(width / 2, height / 2 - 6);
//            cdc.MoveTo(width / 2, height / 2 + 6);
//            cdc.LineTo(width / 2, height / 2 + crosssize);
//            CBrush brush, *oldbrush;
//            oldbrush = cdc.SelectObject(&brush);
//            cdc.Ellipse(width / 2 - 1, height / 2 - 1, width / 2 + 1, height / 2 + 1);
//            cdc.SelectObject(oldbrush);
//
//
//            width = 55;
//            height = 75;
//            dlgcdc.MoveTo(width / 2 - crosssize, height / 2);
//            dlgcdc.LineTo(width / 2 - 6, height / 2);
//            dlgcdc.MoveTo(width / 2 + 6, height / 2);
//            dlgcdc.LineTo(width / 2 + crosssize, height / 2);
//            dlgcdc.MoveTo(width / 2, height / 2 - crosssize);
//            dlgcdc.LineTo(width / 2, height / 2 - 6);
//            dlgcdc.MoveTo(width / 2, height / 2 + 6);
//            dlgcdc.LineTo(width / 2, height / 2 + crosssize);
//
//            CBrush dlgbrush, *olddlgbrush;
//            olddlgbrush = dlgcdc.SelectObject(&dlgbrush);
//            dlgcdc.Ellipse(width / 2 - 1, height / 2 - 1, width / 2 + 1, height / 2 + 1);
//            dlgcdc.SelectObject(olddlgbrush);
//
//
//            cdc.SelectObject(hpenold);
//            ::DeleteObject(hpen);
//            ::ReleaseDC(hwnd, hdc);
//            cdc.DeleteDC();
//            dlgcdc.DeleteDC();
//        }
//    }
//    return 0L;
//}

int main()
{

    HANDLE csHandle = OpenProcess(PROCESS_ALL_ACCESS, 1, GetProcessID(L"cstrike.exe"));
    
    if (csHandle == 0)
    {
        std::cout << GetLastError() << std::endl;
    }
    else
    {
        std::cout << csHandle << std::endl;
    }

    std::thread thread1(std::bind(&Recoil, csHandle));
    std::thread thread2(std::bind(&Bullet, csHandle));
    std::thread thread3(std::bind(&ThroughWall, csHandle));
    if (thread1.joinable())
    {
        thread1.join();
    }

    return 0;
}   