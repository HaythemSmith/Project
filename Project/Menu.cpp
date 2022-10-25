#include "menu.h"
COORD selection[2] = { {54,20},{76,20} };

void Menu::text(string name, int color, int x, int y)
{
	GotoXY(x, y);
	TextColor(color);
	cout << name;
}
void Menu::box(int color, int width, int height, int x, int y)
{
	TextColor(color);
	for (int i = 0; i < height; i++)
	{
		GotoXY(x, y + i);
		for (int j = 0; j < width; j++)
		{
			cout << " ";
		}
	}
	TextColor(240);
}
void Menu::boxloading(int color, int width, int height, int x, int y)
{
	int n = 0;
	for (int i = 0; i < height; i++)
	{
		GotoXY(x, y + i);
		for (int j = 0; j < width; j++)
		{
			TextColor(color);
			Sleep(30);
			cout << " ";
			n++;
			text(to_string(n) + "%", 240, x, y + 1);
			GotoXY(x + j, y);
		}
	}
	TextColor(240);
}
void Menu::clear(string& s, string t, int x, int y)
{
	for (int i = 0; i < s.size() + t.size(); i++)
	{
		text(" ", 240, x + i, y);
	}
}

void Menu::option()
{
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(87))
	{
		int temp;
		temp = selection[0].Y - 2;
		if (temp <= 19)
			return;
		GotoXY(selection[0].X, selection[0].Y);
		cout << " ";
		GotoXY(selection[1].X, selection[1].Y);
		cout << " ";
		selection[0].Y -= 2;
		selection[1].Y -= 2;
		GotoXY(selection[0].X, selection[0].Y);
		cout << "[";
		GotoXY(selection[1].X, selection[1].Y);
		cout << "]";
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(83))
	{
		int temp;
		temp = selection[0].Y + 2;
		if (temp > 28)
			return;
		GotoXY(selection[0].X, selection[0].Y);
		cout << " ";
		GotoXY(selection[1].X, selection[1].Y);
		cout << " ";
		selection[0].Y += 2;
		selection[1].Y += 2;
		GotoXY(selection[0].X, selection[0].Y);
		cout << "[";
		GotoXY(selection[1].X, selection[1].Y);
		cout << "]";
	}
	_getch();
}
int Menu::startmenu()
{

	box(112, 36, 17, 48, 15);

	text("*********** MENU ***********", 117, 52, 18);
	text("   1. START GAME   ", 124, 56, 20);
	text("   2. LOAD GAME    ", 124, 56, 22);
	text("   3. SETTING     ", 124, 56, 24);
	text("   4. HELP      ", 124, 56, 26);
	text("   E. EXIT GAME   ", 124, 56, 28);
	GotoXY(54, 20);
	cout << "[";
	GotoXY(76, 20);
	cout << "]";
	while (1) {

		option();
		if (GetAsyncKeyState(VK_RETURN)) {
			if (selection[0].Y == 20) {
				return 1;
			}
			if (selection[0].Y == 22) {
				return 2;
			}
			if (selection[0].Y == 24) {
				return 3;
			}
			if (selection[0].Y == 26) {
				return 4;
			}
			if (selection[0].Y == 28) {
				return 5;
			}
		}
		Sleep(100);
	}
	/*while (1)
	{
		int h;
		if (_kbhit())
		{
			h = _getch();
			if (h == 13)
			{
				break;
			}
			if (h == 80)
			{
				if (op1 < 8)
				{
					op2 = op1;
					op1++;
					option(op1, op2);
				}
			}
			if (h = 72)
			{
				if (op1 > 1)
				{
					op2 = op1;
					op1--;
					option(op1, op2);
				}
			}
		}
	}
	if (op1 == 1)
	{
		system("cls");
		TextColor(10);
	}
	if (op1 == 2)
	{

	}
	if (op1 == 3)
	{

	}
	if (op1 == 4)
	{

	}*/

	TextColor(240);
}
