#include "Graphic_Template.h"

void Graphic_Template::cursor(int x, int y) {
	setlinecolor(RGB(255, 255, 255)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1);
	BeginBatchDraw(); line(x + 36, y, x - 36, y); line(x, y + 36, x, y - 36); EndBatchDraw();
}

int Graphic_Template::Fixed_Link(int x, int y, int asp) {
	setfillcolor(RGB(33, 40, 48)); setlinecolor(RGB(190, 183, 255)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1);
	int pts[] = { x,y,x + (asp / 2),y + asp,x - (asp / 2),y + asp };
	fillpolygon((POINT *)pts, 3);
	fillcircle(x, y, asp / 5);
	line(x + (asp / 2) + 6, y + asp, x - (asp / 2) - 6, y + asp);

	setfillstyle(BS_HATCHED, HS_BDIAGONAL); setfillcolor(RGB(190, 183, 255));
	solidrectangle(x + (asp / 2), y + asp, x - (asp / 2), y + asp + 8);

	return 1;
}

int Graphic_Template::Guide_Rail(int x, int y, int x1, int y1) {
	setfillcolor(RGB(33, 40, 48)); setlinecolor(RGB(190, 183, 255)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1);
	BeginBatchDraw(); line(x, y, x1, y1); EndBatchDraw();

	return 2;
}

void Graphic_Template::GuideRail_ICO(int x, int y, int asp) {
	setfillcolor(RGB(33, 40, 48)); setlinecolor(RGB(190, 183, 255)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1);
	BeginBatchDraw(); line(x, y, x + asp, y); line(x + asp - 2, y, x + asp - 8, y + 6); line(x + asp - 6, y, x + asp - 12, y + 6); line(x + asp - 10, y, x + asp - 16, y + 6); EndBatchDraw();
}

int Graphic_Template::Rod_ICO(int x, int y, int asp) {
	setfillcolor(RGB(33, 40, 48)); setlinecolor(RGB(255, 255, 255)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1);
	BeginBatchDraw(); line(x, y, x + asp, y + asp); fillcircle(x, y, 4); fillcircle(x + asp, y + asp, 4); EndBatchDraw();
	return 0;
}

int Graphic_Template::Rod(int x, int y, int x1, int y1) {
	setfillcolor(RGB(33, 40, 48)); setlinecolor(RGB(255, 255, 255)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1);
	BeginBatchDraw(); line(x, y, x1, y1); fillcircle(x, y, 4);  fillcircle(x1, y1, 4); EndBatchDraw();

	return 3;
}

int Graphic_Template::PairsLink(float **M, int Num, int r) {
	setfillcolor(RGB(220, 220, 170)); setlinecolor(RGB(220, 220, 170)); setlinestyle(PS_SOLID || PS_ENDCAP_ROUND, 1); setfillstyle(BS_HATCHED, HS_BDIAGONAL);
	BeginBatchDraw();

	if (Num == -1) {
		line(M[0][0], M[0][1], M[1][0], M[1][1]);
		line(M[1][0], M[1][1], M[2][0], M[2][1]);
	}

	if (Num >= 1)line(M[0][0], M[0][1], M[1][0], M[1][1]);
	if (Num == 2)line(M[1][0], M[1][1], M[2][0], M[2][1]);

	float angle = atan((M[0][1] - M[1][1]) / (M[0][0] - M[1][0]));
	//cout << angle << endl;
	arc(M[1][0] + r, M[1][1] + r, M[1][0] - r, M[1][1] - r, -angle, 3.14 - angle);
	clearcircle(M[1][0], M[1][1], r - 1); //cursor(M[1][0], M[1][1]);

	//setlinecolor(RGB(255, 255, 255)); line(M[1][0] - 100, M[1][1], M[1][0] + 100, M[1][1]); line(M[1][0], M[1][1] + 100, M[1][0], M[1][1] - 100);

	/*if (Num >= 3) {
		float K1 = (static_cast<float>(points[0].y) - points[1].y) / (points[0].x - points[1].x);
		float K2 = (static_cast<float>(points[2].y) - points[1].y) / (points[2].x - points[1].x);

		POINT recPoint[2]{ NULL };
		for (float i = 0; i < 6.28; i += 0.1) {
			float x = r * cos(i) + points[1].x; float y = r * sin(i) + points[1].y;

			int y1 = K1 * (x - points[1].x) + points[1].y;
			int y2 = K2 * (x - points[1].x) + points[1].y;

			//putpixel((int)x, y1, RGB(255, 255, 255));
			//putpixel((int)x, y2, RGB(255, 255, 255));

			int P1 = (int)sqrt(pow(y1 - points[1].y, 2) + pow(x - points[1].x, 2));
			int P2 = (int)sqrt(pow(y2 - points[1].y, 2) + pow(x - points[1].x, 2));

			if (P1 <= r + 2 && P1 >= r - 2) { circle(x, y1, 6); recPoint[0] = { NULL }; recPoint[0] = { (long)x,y1 }; }
			if (P2 <= r + 2 && P2 >= r - 2) { circle(x, y2, 6); recPoint[1] = { NULL }; recPoint[1] = { (long)x,y2 }; }
			//putpixel((int)x, y, RGB(220, 220, 170));
		}
	}*/

	EndBatchDraw();
	return 4;
}