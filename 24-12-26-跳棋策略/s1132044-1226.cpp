#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;
struct myPoint
{
	int x;
	int y;
};
struct myCircle
{
	struct myPoint p;
	int r;
	int color;
	COLORREF pencolor;
	WCHAR str[6];
};
const int  Cn = 61 + 25 * 6;
struct myGame
{
	myCircle A[Cn] = { 0 };
	int Ac[Cn][8] = { 0 };
	int start[3][8] = { {17,81,80,79,78,85,84,83},{11,134,133,132,131,130,129,128},{58,178,185,184,183,182,181,180} };
	int dest[3][8] = { {156,155,43,159,160,157,158,154},{209,208,49,204,205,210,203,207},{103,110,2,106,107,104,105,109} };
};
void readBoard(myGame& g)
{
	std::ifstream file;
	file.open("board.bin", std::ios::binary);
	file.read((char*)(&g), sizeof(myGame));
	file.close();
}
bool nextstepblock(int nextstep, vector<int> redBlue, vector<int> green)
{
	for (int i = 0; i < redBlue.size(); i++)
		if (nextstep == redBlue[i])return true;
	for (int i = 0; i < green.size(); i++)
		if (nextstep == green[i])return true;
	return false;
}
bool next2stepblock(int next2step, vector<int> redBlue, vector<int> green)
{
	for (int i = 0; i < redBlue.size(); i++)
		if (next2step == redBlue[i])return true;
	for (int i = 0; i < green.size(); i++)
		if (next2step == green[i])return true;
	return false;
}
bool check18(vector<int>redBlue)
{
	for (int i = 0; i < redBlue.size(); i++)
		if (redBlue[i] == 18)return true;
	return false;
}
int main()
{
	struct myGame g;
	readBoard(g);
	int pieces[3][8];
	int end[8] = { 209,208,49,204,205,210,203,207 };
	int i, j, e, c;
	vector<int> redBlue = { 66,67,81,83,92,93,107,109,137,138,154,160,163,164,180,178 };
	vector<int> green;
	vector<int> currentlog;
	ifstream piecefile;
	piecefile.open("play.txt");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 8; j++)
			piecefile >> pieces[i][j];
	piecefile.close();
	for (i = 0; i < 3; i++)
		for (j = 0; j < 8; j++)
			if (i == 1)green.push_back(pieces[i][j]);
			else redBlue.push_back(pieces[i][j]);
	ofstream file;
	file.open("s1132044.txt");
	int way = 5;
	int current = pieces[1][0];
	int nextstep = g.Ac[current][way] - 1;
	int next2step = g.Ac[nextstep][way] - 1;
	int countstep = 0, temp = 0, jumped2step = 0, changeway = 0, change = 0;
	if (check18(redBlue) == false)
	{
		i = 7;
		c = 0;
	}
	else
	{
		i = 0;
		c = 1;
	}
	while (i >= -1)
	{
		way = 5;
		current = pieces[1][i];
		nextstep = g.Ac[current][way] - 1;
		next2step = g.Ac[nextstep][way] - 1;
		green[i] = current;
		while (current != end[i])
		{
			if (way == 2)
			{
				way = 1;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
				changeway = 1;
			}
			if (changeway == 0)
			{
				way = 5;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			temp = current;
			jumped2step = 0;
			if (current <= 60 || (current >= 111 && current <= 134))
			{
				if (current != 18)
					for (e = 1; e <= 2; e++)
					{
						if (e == 1)way = 5;
						if (e == 2)way = 1;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						if (nextstepblock(nextstep, redBlue, green) == true && next2stepblock(next2step, redBlue, green) == false)
						{
							break;
						}
					}
			}
			if ((current == 128) || (current == 129) || (current == 130) || (current == 131) || (current == 132) || (current == 133) || (current == 134))
			{
				way = 1;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][2] - 1;
			}
			if ((current == 121) || (current == 122) || (current == 123) || (current == 124) || (current == 125) || (current == 126))
			{
				way = 2;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][1] - 1;
			}
			if ((current == 0) || (current == 1) || (current == 2) || (current == 3) || (current == 54) || (current == 55) || (current == 56) || (current == 57) || (current == 58) || (current == 59))
			{
				way = 1;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if ((current == 60) || (current == 207))
			{
				way = 3;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (current == 34)
			{
				way = 4;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if ((current == 4) || (current == 10) || (current == 17) || (current == 25) || (current == 26) || (current == 35) || (current == 42) || (current == 43) || (current == 49) || (current == 50) || (current == 119))
			{
				way = 5;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (current > 185 && current < 195)
			{
				if (i == 3 || i == 4 || i == 5 || i == 6)
				{
					way = 2;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][way] - 1;
				}
				if (i == 0 || i == 1 || i == 7)
				{
					way = 3;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][way] - 1;
				}
			}
			if (current == 55 && i == 2)
			{
				way = 3;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (current == 42 && i == 2)
			{
				way = 4;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (i == 0 && current == 193)
			{
				way = 5;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (i == 1 && current == 192)
			{
				way = 5;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (i == 2 && current == 191)
			{
				way = 4;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (i == 3 && current == 189)
			{
				way = 4;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (i == 4 && current == 190)
			{
				way = 4;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (i == 5 && current == 187)
			{
				way = 4;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (i == 6 && current == 188)
			{
				way = 4;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (i == 7 && current == 191)
			{
				way = 5;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
			}
			if (current <= 60 || (current >= 111 && current <= 134))
				while (nextstepblock(nextstep, redBlue, green) == true && next2stepblock(next2step, redBlue, green) == false)
				{
					if (current == 190 || current == 191 || current == 42 || current == 49 || current == 55)break;
					if (current == 33 && way == 1)
					{
						way = 5;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						break;
					}
					if (current == 54 && way == 5)
					{
						way = 1;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						break;
					}
					if (next2step == 164 || next2step == 163 || next2step == 178 || next2step == 180)
					{
						way = 1;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						break;
					}
					if (next2step == 66 || next2step == 67 || next2step == 81 || next2step == 83)
					{
						way = 5;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						break;
					}
					if (next2step == 92 || next2step == 93 || next2step == 107 || next2step == 109)
					{
						way = 1;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						break;
					}
					if (nextstepblock(nextstep, redBlue, green) == true && next2stepblock(next2step, redBlue, green) == false)
					{
						current = next2step;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
					}
					if ((current == 128) || (current == 129) || (current == 130) || (current == 131) || (current == 132) || (current == 133) || (current == 134))
					{
						way = 1;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][2] - 1;
					}
					if ((current == 121) || (current == 122) || (current == 123) || (current == 124) || (current == 125) || (current == 126))
					{
						way = 2;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][1] - 1;
					}
					if ((current == 5) || (current == 18))
					{
						way = 5;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
					}
					currentlog.push_back(current);
					countstep++;
					jumped2step = 1;
					if (current <= 55)
					{
						way = 5;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						if (way == 5 && nextstepblock(nextstep, redBlue, green) == false)
						{
							way = 1;
							nextstep = g.Ac[current][way] - 1;
							next2step = g.Ac[nextstep][way] - 1;
						}
					}
					else if (current >= 56 && current <= 60)
					{
						way = 1;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						if (way == 1 && nextstepblock(nextstep, redBlue, green) == false)
						{
							way = 3;
							nextstep = g.Ac[current][way] - 1;
							next2step = g.Ac[nextstep][way] - 1;
						}
					}
					else if (current == 4 || current == 10 || current == 17 || current == 25)
					{
						way = 5;
						nextstep = g.Ac[current][way] - 1;
						next2step = g.Ac[nextstep][way] - 1;
						if (way == 5 && nextstepblock(nextstep, redBlue, green) == false)
						{
							way = 0;
							nextstep = g.Ac[current][way] - 1;
							next2step = g.Ac[nextstep][way] - 1;
						}
						if (way == 0 && nextstepblock(nextstep, redBlue, green) == false)
						{
							way = 4;
							nextstep = g.Ac[current][way] - 1;
							next2step = g.Ac[nextstep][way] - 1;
						}
					}
				}
			if (current <= 55 && current != 34 && current != 54)
			{
				way = 5;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
				if (way == 5 && nextstepblock(nextstep, redBlue, green) == true)
				{
					way = 1;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][way] - 1;
				}
				if (way == 1 && nextstepblock(nextstep, redBlue, green) == true)
				{
					way = 3;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][way] - 1;
				}
				if (way == 3 && nextstepblock(nextstep, redBlue, green) == true)
				{
					way = 2;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][way] - 1;
				}
			}
			else if (current >= 56 && current < 60 && current != 34 && current == 54)
			{
				way = 1;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
				if (way == 1 && nextstepblock(nextstep, redBlue, green) == true)
				{
					way = 3;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][way] - 1;
				}
				if (way == 3 && nextstepblock(nextstep, redBlue, green) == true)
				{
					way = 2;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][way] - 1;
				}
			}
			if (nextstepblock(nextstep, redBlue, green) == false && jumped2step == 0)
			{
				current = nextstep;
				nextstep = g.Ac[current][way] - 1;
				next2step = g.Ac[nextstep][way] - 1;
				if ((current == 128) || (current == 129) || (current == 130) || (current == 131) || (current == 132) || (current == 133) || (current == 134))
				{
					way = 1;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][2] - 1;
				}
				if ((current == 121) || (current == 122) || (current == 123) || (current == 124) || (current == 125) || (current == 126))
				{
					way = 2;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][1] - 1;
				}
				if ((current == 5) || (current == 18))
				{
					way = 5;
					nextstep = g.Ac[current][way] - 1;
					next2step = g.Ac[nextstep][way] - 1;
				}
				currentlog.push_back(current);
				countstep++;
				file << pieces[1][i];
				file << " " << countstep;
				file << " " << temp;
				for (j = 0; j < currentlog.size(); j++)
					file << " " << currentlog[j];
				currentlog.clear();
				countstep = 0;
				temp = 0;
				changeway = 0;
				file << endl;
			}
			if (jumped2step == 1)
			{
				file << pieces[1][i];
				file << " " << countstep;
				file << " " << temp;
				for (j = 0; j < currentlog.size(); j++)
					file << " " << currentlog[j];
				currentlog.clear();
				countstep = 0;
				temp = 0;
				jumped2step = 0;
				changeway = 0;
				file << endl;
			}
		}
		green[i] = current;
		pieces[1][i] = current;
		if (c == 0)
		{
			if (i == 2 && change == 1)break;
			if (i == 3 && change == 0)
			{
				i = 2;
				change = 1;
			}
			if (i == 0)i = 3;
		}
		else
		{
			if (i == 2 && change == 1)break;
			if (i == 0)
			{
				i = 2;
				change = 1;
			}
			if (i == 1)i = 8;
		}
		i--;
	}
	file.close();
}