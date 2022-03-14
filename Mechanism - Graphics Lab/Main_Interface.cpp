#include "Universal.h"
#include "Window.h"
#include "Graphic_Template.h"
#include "Menu.h"
Window Win;
Graphic_Template GT;
ExMessage m; ExMessage adsorp; bool MOUSE_Message_Enable = 1;
string input = "";
Menu Mn;

#define Win_Width 1300
#define Win_High 800

#define RigidLinkNum 1000
#define adssen 40//adsorption sensitivity(吸附灵敏度);

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

void Show_Menu() {
	while (1) {
		m = getmessage(EM_MOUSE);
		BeginBatchDraw();
		if (Mn.FixedLink_button(0, 0, 60, m.x, m.y) != "0") { input = "1"; break; }
		if (Mn.GuideRail_button(61, 0, 60, m.x, m.y) != "0") { input = "2"; break; }
		if (Mn.Rod_button(122, 0, 60, m.x, m.y) != "0") { input = "3"; break; }
		if (Mn.PairsLink_button(183, 0, 60, m.x, m.y) != "0") { input = "4"; break; }
		EndBatchDraw();
	}
	Win.SetMouse(Win_Width, Win_High);
	Sleep(200);
}
void Draw_Menu(int x, int y) {
	BeginBatchDraw();
	Mn.FixedLink_button(0, 0, 60, x, y);
	Mn.GuideRail_button(61, 0, 60, x, y);
	Mn.Rod_button(122, 0, 60, x, y);
	Mn.PairsLink_button(183, 0, 60, x, y);
	EndBatchDraw();
}

int ObjNum = 0; int Point_Cache[RigidLinkNum][2] = { {NULL},{NULL} };

int RodNum = 0; int Rod_Cache[RigidLinkNum][4] = { {NULL},{NULL},{NULL},{NULL} };

int GuideRailNum = 0; int GuideRail_Cache[RigidLinkNum][4] = { {NULL},{NULL},{NULL},{NULL} };

int PointNum = 0; int PairsLinkNum = 0; float ***PairsLink_Cache;

void Graph_Cache(int x, int y) {
	BeginBatchDraw();
	for (int i = 0; i < PairsLinkNum; ++i) { GT.PairsLink(PairsLink_Cache[i], -1, 8); }
	for (int i = 0; i < RodNum; ++i) { GT.Rod(Rod_Cache[i][0], Rod_Cache[i][1], Rod_Cache[i][2], Rod_Cache[i][3]); }
	for (int i = 0; i < GuideRailNum; ++i) { GT.Guide_Rail(GuideRail_Cache[i][0], GuideRail_Cache[i][1], GuideRail_Cache[i][2], GuideRail_Cache[i][3]); }
	for (int i = 0; i < ObjNum; ++i) { GT.Fixed_Link(Point_Cache[i][0], Point_Cache[i][1], 20); }

	/*Mn.FixedLink_button(0, 0, 60, x, y);
	Mn.GuideRail_button(61, 0, 60, x, y);
	Mn.Rod_button(122, 0, 60, x, y);*/
	EndBatchDraw();
}

int Draw_Fixed_Link() {
	m = getmessage(EM_MOUSE);
	BeginBatchDraw();

	clearrectangle(0, 61, Win_Width, Win_High);
	Graph_Cache(m.x, m.y);
	if (MOUSE_Message_Enable == 1) { GT.Fixed_Link(m.x, m.y, 20); } else { GT.Fixed_Link(adsorp.x, adsorp.y, 20); }

	if (KEY_DOWN(VK_LBUTTON)) {
		if (MOUSE_Message_Enable == 1) {
			Point_Cache[ObjNum][0] = m.x; Point_Cache[ObjNum][1] = m.y;
		} else {
			Point_Cache[ObjNum][0] = adsorp.x; Point_Cache[ObjNum][1] = adsorp.y;
		}
		Graph_Cache(m.x, m.x); ++ObjNum; EndBatchDraw(); return 1;
	}
	if (KEY_DOWN(VK_RBUTTON)) { clearrectangle(0, 61, Win_Width, Win_High); Graph_Cache(m.x, m.y); EndBatchDraw(); return 1; }
	EndBatchDraw();
	return 0;
}

int Draw_Rod() {
	m = getmessage(EM_MOUSE);
	BeginBatchDraw();

	clearrectangle(0, 61, Win_Width, Win_High);
	Graph_Cache(m.x, m.y); GT.cursor(m.x, m.y);

	EndBatchDraw();

	if (KEY_DOWN(VK_LBUTTON)) {
		Sleep(60);
		while (1) {
			ExMessage m1; m1 = getmessage(EM_MOUSE);
			BeginBatchDraw(); clearrectangle(0, 61, Win_Width, Win_High); Graph_Cache(m.x, m.y); GT.Rod(m.x, m.y, m1.x, m1.y);  EndBatchDraw();
			if (KEY_DOWN(VK_LBUTTON)) {
				Rod_Cache[RodNum][0] = m.x; Rod_Cache[RodNum][1] = m.y; Rod_Cache[RodNum][2] = m1.x; Rod_Cache[RodNum][3] = m1.y;
				++RodNum;  return 1;
			}
			if (KEY_DOWN(VK_RBUTTON)) { Sleep(100); return 0; }
		}
	}
	return 0;
}

int Draw_Guide_Rail() {
	m = getmessage(EM_MOUSE);

	BeginBatchDraw();
	clearrectangle(0, 61, Win_Width, Win_High);
	Graph_Cache(m.x, m.y); GT.cursor(m.x, m.y);

	EndBatchDraw();

	if (KEY_DOWN(VK_LBUTTON)) {
		Sleep(60);
		while (1) {
			ExMessage m1; m1 = getmessage(EM_MOUSE);
			BeginBatchDraw(); clearrectangle(0, 61, Win_Width, Win_High); Graph_Cache(m.x, m.y); GT.Guide_Rail(m.x, m.y, m1.x, m1.y);  EndBatchDraw();
			if (KEY_DOWN(VK_LBUTTON)) {
				GuideRail_Cache[GuideRailNum][0] = m.x; GuideRail_Cache[GuideRailNum][1] = m.y; GuideRail_Cache[GuideRailNum][2] = m1.x; GuideRail_Cache[GuideRailNum][3] = m1.y;
				++GuideRailNum; return 1;
			}
			if (KEY_DOWN(VK_RBUTTON)) { Sleep(100); return 0; }
		}
	}
	return 0;
}

int Draw_PairsLink() {
	m = getmessage(EM_MOUSE);
	float **M = nullptr;
	M = (float **)malloc(sizeof(float *) * 3);//分配指针数组，计算行的大小
	for (int i = 0; i < 3; i++) {
		M[i] = (float *)malloc(sizeof(float) * (2));//分配每个指针所指向的数组，再计算列
	}

	BeginBatchDraw();

	clearrectangle(0, 61, Win_Width, Win_High);
	Graph_Cache(m.x, m.y); GT.cursor(m.x, m.y);

	EndBatchDraw();

	PointNum = 0; M[0][0] = m.x; M[0][1] = m.y;
	if (KEY_DOWN(VK_LBUTTON)) {
		Sleep(60); ++PointNum;
		while (1) {
			ExMessage m1; m1 = getmessage(EM_MOUSE);

			if (PointNum == 1) { M[1][0] = m1.x; M[1][1] = m1.y; }
			if (PointNum == 2) { M[2][0] = m1.x; M[2][1] = (float)(M[1][1] - M[0][1]) / (M[1][0] - M[0][0]) * (m1.x - M[1][0]) + M[1][1]; }

			BeginBatchDraw(); clearrectangle(0, 61, Win_Width, Win_High);
			GT.cursor(m1.x, m1.y); Graph_Cache(m.x, m.y);
			GT.PairsLink(M, PointNum, 8);

			EndBatchDraw();

			if (KEY_DOWN(VK_LBUTTON)) {
				PairsLink_Cache[PairsLinkNum][0][0] = M[0][0]; PairsLink_Cache[PairsLinkNum][0][1] = M[0][1];
				PairsLink_Cache[PairsLinkNum][1][0] = M[1][0]; PairsLink_Cache[PairsLinkNum][1][1] = M[1][1];
				PairsLink_Cache[PairsLinkNum][2][0] = M[2][0]; PairsLink_Cache[PairsLinkNum][2][1] = M[2][1];
				++PointNum;
			}
			if (PointNum >= 3) { ++PairsLinkNum; break; }
			if (KEY_DOWN(VK_RBUTTON)) { Sleep(100); return 1; }
		}
	}
	return 0;
}

int main() {
	Win.Initialize_Window(Win_Width, Win_High, EW_SHOWCONSOLE);
	Win.SetWindowTilte("Mechanism - Graphics Lab"); Draw_Menu(Win_Width, Win_High);
	outtextxy(2, Win_High - 16, "Mechanism - Graphics Lab Powered by RMSHE [Mark0.Alpha.2022.3.13] OpenSource");
	//Win.MoveWindow(0, 0);

	PairsLink_Cache = (float ***)malloc(sizeof(float *) * RigidLinkNum);
	for (int i = 0; i < RigidLinkNum; i++) {
		PairsLink_Cache[i] = (float **)malloc(sizeof(float) * (3));
		for (int j = 0; j < 3; j++) {
			PairsLink_Cache[i][j] = (float *)malloc(sizeof(float) * (2));
		}
	}

	while (true) {
		//cout << "1.机架	2.杆" << endl; cin >> input; system("cls");

		Show_Menu();

		while (true) {
			if (input == "1")if (Draw_Fixed_Link() == 1)break;
			if (input == "2")if (Draw_Guide_Rail() == 1)break;
			if (input == "3")if (Draw_Rod() == 1)break;
			if (input == "4")if (Draw_PairsLink() == 1)break;

			if (KEY_DOWN(VK_RBUTTON)) { BeginBatchDraw(); cleardevice(); Graph_Cache(m.x, m.y); EndBatchDraw(); break; }
		}
	}

	system("pause");
}