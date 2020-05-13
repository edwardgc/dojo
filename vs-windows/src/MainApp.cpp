#include <MainApp.hpp>

MyApp app;

BOOL MyApp::InitInstance()
{

    //创建窗口

    MyFrame *frame = new MyFrame;

    //显示和更新

    frame->ShowWindow(SW_SHOWNORMAL);

    frame->UpdateWindow();

    m_pMainWnd = frame; //保存指向应用程序的主窗口的指针

    return TRUE; //返回正常初始化
}

//分界宏

BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)

ON_WM_LBUTTONDOWN() //鼠标左键按下

ON_WM_CHAR()

ON_WM_PAINT()

END_MESSAGE_MAP()

MyFrame::MyFrame()

{

    Create(NULL, TEXT("windows"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point)

{

    //TCHAR buf[1024];

    //wsprintf(buf, TEXT("x = %d,y = %d"), point.x, point.y);

    //MessageBox(buf);

    CString str;

    str.Format(TEXT("x = % d, y = % d"), point.x, point.y);

    MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT)

{

    CString str;

    str.Format(TEXT("按下了 % c键"), key);

    MessageBox(str);
}

void MyFrame::OnPaint()

{

    CPaintDC dc(this);

    dc.TextOut(100, 100, TEXT("Hello World"));

    dc.Ellipse(10, 10, 100, 100);
}
