#pragma once
#include "resource.h"
#include <math.h>
#include <fstream>
#define PI 3.14159
int pair[][2] = { {74,10},{ 75,25 },{82,17} ,{100,1},{101,3},{108,2},{120,5},{127,18},{135,11},{145,50},{146,35 },{153,43},{171,59},{172,57},{179,58},{198,42},{199,55},{206,49} };
struct myPoint
{
	int x;
	int y;
};
//-----------------------------------
struct myCircle
{
	struct myPoint p;
	int r;
	int color;
	COLORREF pencolor;
	WCHAR str[6];
};
const int Cn = 61 + 25 * 6;
struct myGame
{
	myCircle A[Cn] = { 0 };
	int Ac[Cn][8] = { 0 };
};
//-------------------------------------
void drawCircle(HDC& hdc, struct myCircle& c)
{
	HBRUSH br = CreateSolidBrush(c.color);
	HGDIOBJ oldbrush = SelectObject(hdc, br);
	HGDIOBJ pen = CreatePen(PS_SOLID, 1, c.pencolor);
	HGDIOBJ oldPen = SelectObject(hdc, pen);
	Ellipse(hdc, c.p.x - c.r, c.p.y - c.r, c.p.x + c.r, c.p.y + c.r);
	DeleteObject(SelectObject(hdc, oldPen));
	DeleteObject(SelectObject(hdc, oldbrush));
#ifdef _DEBUG
	HFONT hFont = CreateFont(12, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 2, 0, L"SYSTEM_FIXED_FONT");
	HFONT hFontOriginal = (HFONT)SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, c.p.x - c.r + 5, c.p.y - c.r + 2, c.str, wcslen(c.str));
	DeleteObject(SelectObject(hdc, hFontOriginal));
#endif
}
bool inSide(myCircle& c, myPoint& p)
{
	return ((c.p.x - p.x) * (c.p.x - p.x) + (c.p.y - p.y) * (c.p.y - p.y)) < c.r * c.r;
}
//--------------------------------------
void init(struct myGame& g, int X0 = 400, int Y0 = 300, int d = 30, int r = 10)
{
	double theta = PI / 3;
	int P0x = X0 - 4 * d;
	int P0y = Y0 + 4 * d * sin(theta);
	int i;
	int s;
	int n;
	int j;
	int x0;
	int y0;
	int left = 0;
	int right = 0;
	int index = 0;
	for (i = 0; i < 9; i++)
	{
		s = abs(i - 4);
		n = 9 - s;
		x0 = P0x + s * d / 2;
		y0 = P0y - i * d * sin(theta);
		right = right + n;
		for (j = 0; j < n; j++)
		{
			g.A[index].p.x = x0 + d * j;
			g.A[index].p.y = y0;
			g.A[index].r = 10;
			g.A[index].color = RGB(255, 255, 255);
			wsprintf(g.A[index].str, L"%d", index);
			if (index > left) g.Ac[index][0] = index;
			if (index < right - 1) g.Ac[index][1] = index + 2;
			if (!(index <= 4 or (index == left and index <= 26)))
			{
				if (index <= 34)     g.Ac[index][2] = index - n + 1;
				else g.Ac[index][2] = index - n;
			}
			if (!(index <= 4 or (index == right and index >= 26)))
			{
				if (index <= 34) g.Ac[index][3] = index - n + 1 + 1;
				else g.Ac[index][3] = index - n + 1;
			}
			if (!(index >= 56 or (index == left and index >= 26)))
			{
				if (index >= 26) g.Ac[index][4] = index + n;
				else g.Ac[index][4] = index + n + 1;
			}
			if (!(index >= 56 or (index == right - 1 and index >= 34)))
			{
				if (index >= 26) g.Ac[index][5] = index + n + 1;
				else  g.Ac[index][5] = index + n + 1 + 1;
			}
			index++;
		}
		left = left + n;
	}
	//-----------------------------------------
	int R1 = d + 5;
	int R2 = d * 1 / sin(PI / 8);
	int R = R2 * cos(PI / 8) + 4 * d * sin(theta);
	theta = PI / 3;
	double theta0 = PI / 6;
	double theta2[6] = { PI / 24 ,PI / 8 , -PI / 24, PI / 24,PI / 8, -PI / 24 };
	for (i = 0; i < 6; i++)
	{
		x0 = X0 + R * cos(theta * i + theta0);
		y0 = Y0 + R * sin(theta * i + theta0);
		g.A[index].p.x = x0;
		g.A[index].p.y = y0;
		g.A[index].r = r;
		g.A[index].color = RGB(255, 255, 255);
		wsprintf(g.A[index].str, L"%d", index);
		int center = index;
		index++;
		double theta1 = PI / 4;
		for (j = 0; j < 8; j++)
		{
			g.A[index].p.x = x0 + R1 * cos(theta1 * j + theta2[i]);
			g.A[index].p.y = y0 + R1 * sin(theta1 * j + theta2[i]);
			g.A[index].r = r;
			g.A[index].color = RGB(255, 255, 255);
			wsprintf(g.A[index].str, L"%d", index);
			index++;
			g.Ac[center][j] = index;
			g.Ac[index - 1][0] = center + 1;
		}
		for (j = 0; j < 8; j++)
		{
			g.Ac[center + 1 + j][1] = center + 2 + (j + 1) % 8;
			g.Ac[center + 1 + j][2] = center + 2 + (j + 7) % 8;
			g.Ac[center + 1 + j][3] = center + j + 8 + 1 + 1;
			g.Ac[center + 1 + j][4] = center + j + 15 + 2;
			if (j == 0)
				g.Ac[center + 1 + j][5] = center + j + 24 + 1;
			else
				g.Ac[center + 1 + j][5] = center + j + 16 + 1;
		}
		int start = index;
		for (j = 0; j < 8; j++)
		{
			g.A[index].p.x = x0 + R2 * cos(theta1 * j + theta2[i]);
			g.A[index].p.y = y0 + R2 * sin(theta1 * j + theta2[i]);
			g.A[index].r = r;
			g.A[index].color = RGB(255, 255, 255);
			wsprintf(g.A[index].str, L"%d", index);
			g.Ac[index][0] = index - 8 + 1;
			index++;
		}
		for (j = 0; j < 8; j++)
		{
			g.Ac[start + j][1] = start + j + 7 + 1;
			g.Ac[start + j][2] = start + j + 8 + 1;
		}
		for (j = 0; j < 8; j++)
		{
			g.A[index].p.x = (g.A[start + j].p.x + g.A[start + (j + 1) % 8].p.x) / 2;
			g.A[index].p.y = (g.A[start + j].p.y + g.A[start + (j + 1) % 8].p.y) / 2;
			g.A[index].r = r;
			g.A[index].color = RGB(255, 255, 255);
			wsprintf(g.A[index].str, L"%d", index);
			if (j < 7)
			{
				g.Ac[index][0] = index - 15 + 1;
				g.Ac[index][1] = index - 16 + 1;
				g.Ac[index - 15][4] = index + 1;
				g.Ac[index - 16][4] = index + 1;
				g.Ac[index][2] = index - 7 + 1;
				g.Ac[index][3] = index - 8 + 1;
				g.Ac[index - 7][5] = index + 1;
				g.Ac[index - 8][5] = index + 1;
			}
			else
			{
				g.Ac[index][0] = index - 23 + 1;
				g.Ac[index][1] = index - 16 + 1;
				g.Ac[index - 23][4] = index + 1;
				g.Ac[index - 16][4] = index + 1;
				g.Ac[index][2] = index - 15 + 1;
				g.Ac[index][3] = index - 8 + 1;
				g.Ac[index - 15][5] = index + 1;
				g.Ac[index - 8][5] = index + 1;
			}
			index++;
		}
	}
	//--------------------------------------------
	for (i = 61; i < 207; i++)
		for (j = 0; j < 8; j++)
			for (int k = 0; k < 9; k++)
			{
				if (g.Ac[i][j] == pair[k][0]) g.Ac[i][j] == pair[k][1];
			}
	g.Ac[10][1] = 67;
	g.Ac[10][3] = 82;
	g.Ac[17][1] = 68;
	g.Ac[17][3] = 67;
	g.Ac[25][1] = 84;
	g.Ac[25][3] = 68;
	g.Ac[1][2] = 108;
	g.Ac[1][3] = 93;
	g.Ac[2][2] = 93;
	g.Ac[2][3] = 94;
	g.Ac[3][2] = 110;
	g.Ac[3][3] = 94;
	g.Ac[18][0] = 135;
	g.Ac[18][2] = 120;
	g.Ac[11][0] = 120;
	g.Ac[11][2] = 113;
	g.Ac[5][0] = 113;
	g.Ac[5][2] = 129;
	g.Ac[35][0] = 155;
	g.Ac[35][4] = 139;
	g.Ac[43][0] = 138;
	g.Ac[43][4] = 139;
	g.Ac[50][0] = 161;
	g.Ac[50][4] = 138;
}
void draw(HDC& hdc, struct myGame& g)
{
	int check = 0;
	int k = 0;
	for (int i = 0; i < Cn; i++)
	{
		if (pair[k][0] == i) { k++; continue; }
		for (int j = 0; j < 8; j++)
		{
			if (g.Ac[i][j] > 0)
			{
				MoveToEx(hdc, g.A[i].p.x, g.A[i].p.y, 0);
				LineTo(hdc, g.A[g.Ac[i][j] - 1].p.x, g.A[g.Ac[i][j] - 1].p.y);
			}
		}
	}
	k = 0;
	for (int i = 0; i < Cn; i++)
	{
		if (i != pair[k][0])
		{
			drawCircle(hdc, g.A[i]);
		}
		else
			k++;
	}
}
void saveBoard(myGame& g)
{
	std::ofstream file;
	file.open("board.bin", std::ios::binary);
	file.write((char*)(&g), sizeof(myGame));
	file.close();
}
void readBoard(myGame& g)
{
	std::ifstream file;
	file.open("board.bin", std::ios::binary);
	file.read((char*)(&g), sizeof(myGame));
	file.close();
}
//================================================
int chase[3][8][2] = {
{ {17,0},{81,0},{80,0},{79,0},{78,0},{85,0},{84,0},{83,0} },
{ {11,0},{134,0},{133,0},{132,0},{131,0},{130,0},{129,0},{128,0} },
{ {58,0},{178,0},{185,0},{184,0},{183,0},{182,0},{181,0},{180,0} }
};
struct myCircle chaseCircle[3][8] = { 0 };
void initChase(struct myGame& g)
{
	int i;
	int j;
	COLORREF color[] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255) };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chaseCircle[i][j] = g.A[chase[i][j][0]];
			chaseCircle[i][j].color = color[i];
		}
	}
}
void updateChase(struct myGame& g)
{
	int i;
	int j;
	COLORREF color[] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255) };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chaseCircle[i][j] = g.A[chase[i][j][0]];
			chaseCircle[i][j].color = color[i];
		}
	}
}
void drawChase(HDC hdc, struct myCircle chase[3][8])
{
	int i;
	int j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 8; j++)
			drawCircle(hdc, chase[i][j]);
}