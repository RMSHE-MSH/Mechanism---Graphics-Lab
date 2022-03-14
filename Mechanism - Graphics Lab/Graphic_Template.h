#pragma once
#include "Universal.h"
#include "Window.h"
class Graphic_Template {
public:
	void cursor(int x, int y);
	int Fixed_Link(int x, int y, int asp);

	int Guide_Rail(int x, int y, int x1, int y1);
	void GuideRail_ICO(int x, int y, int asp);

	int Rod_ICO(int x, int y, int asp);
	int Rod(int x, int y, int x1, int y1);

	int PairsLink(float **M, int Num, int r);

	int Slider();
};
