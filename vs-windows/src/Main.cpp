#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam); //回调函数

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nShowCmd)
{
    WNDCLASS wndcls;                                            //实例化
    wndcls.cbClsExtra = 0;                                      //额外的类的附加字节数
    wndcls.cbWndExtra = 0;                                      //窗口额外的附加字节数
    wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //背景颜色，GetStockObject()函数的返回值是一个HGDIOBJ格式的，强制转换成HBRUSH格式的赋值
    wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);               //光标的类型
    wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);                   //图标
    wndcls.hInstance = hInstance;                               //应用程序的实例号
    wndcls.lpfnWndProc = WinSunProc;                            //窗口过程函数
    wndcls.lpszClassName = "Main";                              //类名
    wndcls.lpszMenuName = NULL;                                 //菜单名
    wndcls.style = CS_HREDRAW | CS_VREDRAW;                     //水平重画和垂直重画

    RegisterClass(&wndcls); //注册窗口类

    HWND hwnd;                                                                                                       //实例化一个句柄
    hwnd = CreateWindow("Main", "Hello World", WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL); //建立一个窗口

    ShowWindow(hwnd, SW_SHOWNORMAL); //显示窗口
    UpdateWindow(hwnd);              //更新窗口

    MSG msg;                             //消息机制
    while (GetMessage(&msg, NULL, 0, 0)) //消息循环
    {
        TranslateMessage(&msg); //将传来的消息翻译
        DispatchMessage(&msg);  //
    }
    return 0;
}

LRESULT CALLBACK WinSunProc(HWND hwnd,
                            UINT uMsg,
                            WPARAM wParam,
                            LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CHAR:
        char szChar[20];
        sprintf_s(szChar, "Keycode is %d", (UINT32)wParam); //sprintf_s和sprintf的区别
        MessageBox(hwnd, szChar, "Keycode", 0);
        break;
    case WM_LBUTTONDOWN:
        MessageBox(hwnd, "Mouse Clicked", "Message Box", 0);
        HDC hdc;
        hdc = GetDC(hwnd);
        TextOut(hdc, 0, 50, "mouse", (int)strlen("mouse"));
        ReleaseDC(hwnd, hdc);
        break;
    case WM_PAINT:
        HDC hDC;
        PAINTSTRUCT ps;
        hDC = BeginPaint(hwnd, &ps);
        TextOut(hDC, 0, 0, "All dark", (int)strlen("All dark"));
        EndPaint(hwnd, &ps);
        break;
    case WM_CLOSE:
        if (IDYES == MessageBox(hwnd, "Really close?", "Hello World", MB_YESNO))
        {
            DestroyWindow(hwnd); //销毁窗口
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
