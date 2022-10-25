#include "Human.h"

Human::Human() { //x = 50, y = 43
	human_coord = new COORD[12];
	preV = new COORD[12];
	short i = 0;
	for (i; i < 4; i++) {
		human_coord[i] = { short(i + 50), 43 };
	}
	for (i; i < 8; i++) {
		human_coord[i] = { short(i + 46), 44 };
	}
	for (i; i < 12; i++) {
		human_coord[i] = { short(i + 42), 45 };
	}
	shape = new string[3];
	shape[0] = " \xDC\xDC\xDC";
	shape[1] = "\xDB\xDB\xDB\xDC";
	shape[2] = " \xDB\xDF\xDB";
}
Human::~Human() {
	delete[]human_coord;
	delete[]preV;
	delete[]shape;
}
void Human::Copy(){
	for (int i = 0; i < 12; i++) {
		preV[i] = human_coord[i];
	}
}
void Human::Draw() {
	GotoXY(human_coord[0].X, human_coord[0].Y);
	cout << shape[0];
	GotoXY(human_coord[4].X, human_coord[4].Y);
	cout << shape[1];
	GotoXY(human_coord[8].X, human_coord[8].Y);
	cout << shape[2];
}
void Human::Delete() {
	for (int i = 0; i < 12; i++) {
		int temp = preV[i].X;
		temp = human_coord[i].X;
		temp = preV[i].Y;
		temp = human_coord[i].Y;
		if ((preV[i].X != human_coord[i].X) || (preV[i].Y != human_coord[i].Y)) {
			GotoXY(preV[i].X, preV[i].Y);
			cout << " ";
		}
	}
}
void Human::Input() {
	Copy();
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(87)) {
		for (int i = 0; i < 12; i++) {
			human_coord[i].Y--;
		}
		Delete();
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(83)) {
		for (int i = 0; i < 12; i++) {
			human_coord[i].Y++;
		}
		Delete();
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(65)) {
		for (int i = 0; i < 12; i++) {
			human_coord[i].X--;
		}
		Delete();
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(68)) {
		for (int i = 0; i < 12; i++) {
			human_coord[i].X++;
		}
		Delete();
	}
}