#include "Map.h"

void Map::Draw() {
	//doc trai
	int i = 0;
	for (i; i < 47; i++) {
		height[i] = { 0, (short)(i + 1) };
		GotoXY(0, (short)(i + 1));
		cout << char(179);
	}
	//doc phai
	for (i; i < 94; i++) {
		height[i] = { 100, (short)(i - 46)};
		GotoXY(100, (short)(i - 46));
		cout << char(179);
	}
	//ngang tren
	i = 0;
	for (i; i < 99; i++) {
		weight[i] = { 1 , 0 };
		GotoXY((short)(i+1), 0);
		cout << char(196);
	}
	for (i; i < 198; i++) {
		weight[i] = { 1 , 48 };
		GotoXY((short)(i - 98), 48);
		cout << char(196);
	}
	//in goc
	corner[0] = { 0,0 };
	GotoXY(0, 0);
	cout << char(218);

	corner[1] = { 100,0 };
	GotoXY(100, 0);
	cout << char(191);

	corner[2] = { 0,48 };
	GotoXY(0, 48);
	cout << char(192);

	corner[3] = { 100,48 };
	GotoXY(100, 48);
	cout << char(217);

	for (i = 1; i < 100; i++) {
		GotoXY(i, 42);
		cout << char(196);
	}
}