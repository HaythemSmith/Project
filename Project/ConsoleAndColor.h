#pragma once
// Kính thước màn hình console
#define WIDTH 1470 //1320
#define HEIGHT 700
#define X_CENTER WIDTH / 16 + 2
#define Y_CENTER HEIGHT / 32
//ASCII
#define ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <fcntl.h>
#include <io.h>

using namespace std;

void FixConsoleWindow();
void setConsoleSize();
void GotoXY(int x, int y);
void ShowConsoleCursor(bool showFlag);
void TextColor(int x);
void setBackgroundColor(WORD color);



void cls();