#pragma once
#include "ConsoleAndColor.h"

extern COORD selection[2];

class Menu
{
private:
	int choices;
	int x;
	int y;
public:
	void text(string name, int color, int x, int y);//in text
	void box(int color, int width, int height, int x, int y);
	void boxloading(int color, int width, int height, int x, int y);
	void BigText(string filename, int color, int x, int y);
	void clear(string& s, string t, int x, int y);
	void option();
	int startmenu();
};
