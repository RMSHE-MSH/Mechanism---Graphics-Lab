#include "Window.h"

//��ʼ�� EasyX Graphics Library ����;
void Window::Initialize_Window(int Width, int Height, int Flag) {
	Handle = ::initgraph(Width, Height, Flag);
	setorigin(0, 0);
	setbkcolor(RGB(33, 40, 48));
	cleardevice();
	setaspectratio(1, 1);
	::setbkmode(TRANSPARENT);
}

void Window::Reset_Window(int Width, int Height, COLORREF Window_Color) {
	Resize(NULL, Width, Height);
	setbkcolor(Window_Color);
	cleardevice();
}

void Window::SetWindowTilte(const string &Title) { ::SetWindowText(Handle, Title.c_str()); }

void Window::MoveWindow(int X, int Y) { ::MoveWindow(Handle, X, Y, GetWidth(), GetHeight(), 0); }

//��ȡ�������Ļ���������;
void Window::GetScreenMouse() { GetCursorPos(&m_Mouse_Screen); }
//��ȡ����ڴ��ڵ���������Ϣ;
void Window::GetWindowMouse() { m_Mouse_Window = getmessage(EM_MOUSE | EM_KEY); }

void Window::SetMouse(int Width, int Height) {
	POINT pt{ 0,0 };
	RECT rc;
	::GetWindowRect(Handle, &rc);
	pt.x = rc.left + Width / 2;
	pt.y = rc.top + Height / 2;
	::SetCursorPos(pt.x, pt.y);
}

int Window::GetWidth() { return ::getwidth(); }
int Window::GetHeight() { return ::getheight(); }

void Window::GetWindowRect() { ::GetWindowRect(Handle, &Rect); }