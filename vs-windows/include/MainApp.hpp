#include <afxwin.h>

class MyApp : public CWinApp
{

public:
    virtual BOOL InitInstance();
};

class MyFrame : public CFrameWnd
{ //窗口框架类

public:
    MyFrame();

    //声明宏 提示消息映射机制

    DECLARE_MESSAGE_MAP();

    afx_msg void OnLButtonDown(UINT, CPoint);

    afx_msg void OnChar(UINT, UINT, UINT);

    afx_msg void OnPaint();
};
