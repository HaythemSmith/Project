#include "Enemy.h"

Crocodile::Crocodile(int Y) {
	enemy_coord = new COORD[48];
	preV = new COORD[48];
	shape = new string[4];

	srand(time(NULL));
	short temp = rand() % (60 - 3 + 1) + 30;
	short i = 0;
	for (i; i < 22; i++) {
		enemy_coord[i] = { (short)(temp + i), (short)Y };
	}
	for (i; i < 44; i++) {
		enemy_coord[i] = { (short)(temp + i - 22), (short)(Y + 3)};
	}
	enemy_coord[i] = { (short)(temp), (short)(Y + 1) }; i++;
	enemy_coord[i] = { (short)(temp), (short)(Y + 2) }; i++;
	enemy_coord[i] = { (short)(temp + 21), (short)(Y + 1) }; i++;
	enemy_coord[i] = { (short)(temp + 21), (short)(Y + 2) }; i++;

	shape[0] = "     \xDC\xDC\xDC\xDC\xDC \xDC \xDC \xDC \xDC    ";
	shape[1] = "\xDC\xDC\xDC\xDC\xDB\xDB\xDC\xDB\xDB\xDB\xDB\xDF\xDB\xDF\xDB\xDF\xDB\xDF\xDB\xDB  ";
	shape[2] = "\xDF\xDC\xDF\xDC\xDF\xDC\xDB\xDB\xDB\xDB\xDC\xDB\xDC\xDB\xDC\xDB\xDC\xDB\xDB\xDB\xDC ";
	shape[3] = "\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDF\xDF\xDF\xDF\xDB\xDB\xDF  \xDF\xDB\xDB\xDC";

}

void Crocodile::Copy() {
	for (int i = 0; i < 48; i++) {
		preV[i] = enemy_coord[i];
	}
}

void Crocodile::Draw() {
	GotoXY(enemy_coord[0].X, enemy_coord[0].Y);
	cout << shape[0];
	GotoXY(enemy_coord[44].X, enemy_coord[44].Y);
	cout << shape[1];
	GotoXY(enemy_coord[45].X, enemy_coord[45].Y);
	cout << shape[2];
	GotoXY(enemy_coord[22].X, enemy_coord[22].Y);
	cout << shape[3];
}

void Crocodile::Delete() {
	GotoXY(preV[21].X, preV[21].Y);
	cout << " ";
	GotoXY(preV[46].X, preV[46].Y);
	cout << " ";
	GotoXY(preV[47].X, preV[47].Y);
	cout << " ";
	GotoXY(preV[43].X, preV[43].Y);
	cout << " ";

}

void Crocodile::moveLeft() {
	Copy();
	for (int i = 0; i < 48; i++) {
		enemy_coord[i].X--;
	}
}

Lion::Lion(int Y) {
	enemy_coord = new COORD[47];
	preV = new COORD[47];
	shape = new string[4];

	srand(time(NULL));
	short temp = rand() % (60 - 3 + 1) + 30;
	short i = 0;
	for (i; i < 4; i++) {
		enemy_coord[i] = { (short)(temp + i), (short)Y };
	}
	for (i; i < 11; i++) {
		enemy_coord[i] = { (short)(temp + i - 11), (short)(Y + 1) };
	}
	enemy_coord[i] = { (short)(temp + 4), (short)(Y + 1) }; 
	i++;
	enemy_coord[i] = { (short)(temp - 7), (short)(Y + 2) };
	i++;
	enemy_coord[i] = { (short)(temp - 6), (short)(Y + 2) };
	i++;
	enemy_coord[i] = { (short)(temp + 5), (short)(Y + 2) };
	i++;
	for (i; i < 24; i++) {
		enemy_coord[i] = { (short)(temp + i - 20), (short)(Y + 3) };
	}
	shape[0] = "▓▓▓▓";
	shape[1] = "╔═▒▒▒▒▓▄░░▄▓";
	shape[2] = "▀ ▒▒▒▓▓▒──▒▓▓";
	shape[3] = "▒▌▒▐ ▓▓▓▓";
	_setmode(_fileno(stdout), _O_U8TEXT);
	GotoXY(enemy_coord[0].X, enemy_coord[0].Y);
	wcout << L"▓▓▓▓";
	GotoXY(enemy_coord[4].X, enemy_coord[4].Y);
	wcout << L"╔═▒▒▒▒▓▄░░▄▓";
	GotoXY(enemy_coord[12].X, enemy_coord[12].Y);
	wcout << L"▀ ▒▒▒▓▓▒──▒▓▓";
	GotoXY(enemy_coord[15].X, enemy_coord[15].Y);
	wcout << L"▒▌▒▐ ▓▓▓▓";
	_setmode(_fileno(stdout), _O_TEXT);
}