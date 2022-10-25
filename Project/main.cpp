#include "ConsoleAndColor.h"
#include "Human.h"
#include "Map.h"
#include "Enemy.h"
#include "GAME.h"
#include <thread>
#include "menu.h"
#include "Sound.h"

void foo(Crocodile a) {
	while (1) {
		a.Delete();
		a.Draw();
		a.moveLeft();
		Sleep(1000);
	}
}


int main() 
{
	ShowConsoleCursor(false);
	setConsoleSize();
	FixConsoleWindow();
	Menu menu;

	bool isPlay = PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC);

	//vao phan cai dat bat/tat nhac
	/*isPlay = Config_OnOff_Music("menu.wav");
	if (isPlay == true)
		PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC);*/

	/*mỗi lần m muốn thêm nhạc vào phần nào thì làm như thế này
	if (isPlay==true) {
		PlaySound(TEXT("oof.wav"), NULL, SND_ASYNC);
	}
	sfx ở phần nào thì t có gửi note cho m đó*/

	char a;
	switch (menu.startmenu()) {
	case 1:
		goto GAME;
	case 2:
	case 3:
		system("cls");
		isPlay = Config_OnOff_Music(isPlay, "menu.wav");
	case 4:
	case 5:;
	}
GAME:
	//bat nhac hay ko
	if (isPlay == true) {
		PlaySound(TEXT("game.wav"), NULL, SND_ASYNC);
	}


	return 0;
}