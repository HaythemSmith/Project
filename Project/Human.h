#pragma once
#include "ConsoleAndColor.h"
#include <string>
#include <iostream>

using namespace std;

class Human
{
private:
	string *shape;
	COORD *preV;
	COORD *human_coord;
public:
	Human();
	~Human();
	void Draw();
	void Input();
	void Delete();
	void Copy();
};
