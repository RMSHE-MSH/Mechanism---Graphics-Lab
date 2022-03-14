#include "Menu.h"
Graphic_Template GT2;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

string Menu::FixedLink_button(int X, int Y, int length, int x, int y) {
	BeginBatchDraw();
	if (x > X && x<X + length && y>Y && y < Y + length) {
		setfillcolor(RGB(89, 98, 113)); setlinecolor(RGB(255, 255, 255)); setfillstyle(BS_SOLID);
		fillrectangle(X, Y, X + length, Y + length);
		rectangle(X, Y, X + length, Y + length);
		outtextxy(X + length / 4, Y + length / 2.6, "机架");
		if (KEY_DOWN(VK_LBUTTON)) { return "1"; }
	} else {
		setlinecolor(RGB(10, 89, 247)); setfillcolor(RGB(59, 68, 83)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1); setfillstyle(BS_SOLID);
		fillrectangle(X, Y, X + length, Y + length);
		GT2.Fixed_Link(X + length / 2, Y + length / 4, 30);
	}
	EndBatchDraw();
	return "0";
}

string Menu::GuideRail_button(int X, int Y, int length, int x, int y) {
	BeginBatchDraw();
	if (x > X && x<X + length && y>Y && y < Y + length) {
		setfillcolor(RGB(89, 98, 113)); setlinecolor(RGB(255, 255, 255)); setfillstyle(BS_SOLID);
		fillrectangle(X, Y, X + length, Y + length);
		rectangle(X, Y, X + length, Y + length);
		outtextxy(X + length / 4, Y + length / 4.2, "固定"); outtextxy(X + length / 4, Y + length / 1.8, "导轨");
		if (KEY_DOWN(VK_LBUTTON)) { return "2"; }
	} else {
		setlinecolor(RGB(10, 89, 247)); setfillcolor(RGB(59, 68, 83)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1); setfillstyle(BS_SOLID);
		fillrectangle(X, Y, X + length, Y + length);
		GT2.GuideRail_ICO(X + length / 6, Y + length / 2, 40);
	}
	EndBatchDraw();

	return "0";
}

string Menu::Rod_button(int X, int Y, int length, int x, int y) {
	BeginBatchDraw();
	if (x > X && x<X + length && y>Y && y < Y + length) {
		setfillcolor(RGB(89, 98, 113)); setlinecolor(RGB(255, 255, 255)); setfillstyle(BS_SOLID);
		fillrectangle(X, Y, X + length, Y + length);
		rectangle(X, Y, X + length, Y + length);
		outtextxy(X + length / 2.6, Y + length / 2.6, "杆");
		if (KEY_DOWN(VK_LBUTTON)) { return "2"; }
	} else {
		setlinecolor(RGB(10, 89, 247)); setfillcolor(RGB(59, 68, 83)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1); setfillstyle(BS_SOLID);
		fillrectangle(X, Y, X + length, Y + length);
		GT2.Rod_ICO(X + length / 4, Y + length / 4, 30);
	}
	EndBatchDraw();
	return "0";
}

string Menu::PairsLink_button(int X, int Y, int length, int x, int y) {
	BeginBatchDraw();
	if (x > X && x<X + length && y>Y && y < Y + length) {
		setfillcolor(RGB(89, 98, 113)); setlinecolor(RGB(255, 255, 255)); setfillstyle(BS_SOLID);
		fillrectangle(X, Y, X + length, Y + length);
		rectangle(X, Y, X + length, Y + length);
		outtextxy(X + length / 4, Y + length / 4.2, "多副"); outtextxy(X + length / 4, Y + length / 1.8, "构件");
		if (KEY_DOWN(VK_LBUTTON)) { return "4"; }
	} else {
		setlinecolor(RGB(10, 89, 247)); setfillcolor(RGB(59, 68, 83)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1); setfillstyle(BS_SOLID);
		fillrectangle(X, Y, X + length, Y + length);
		GT2.Rod_ICO(X + length / 4, Y + length / 4, 30);
	}
	EndBatchDraw();
	return "0";
}