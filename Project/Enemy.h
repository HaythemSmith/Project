#pragma once
#include "ConsoleAndColor.h"
class Enemy
{
protected:
	COORD *preV;
	COORD *enemy_coord;
	string *shape;
public:
	virtual void Draw() {}
	virtual void Delete() {}
	virtual void moveLeft() {}
	virtual void Copy() {}
};

class Crocodile : public Enemy {
public:
	Crocodile(int y);
	void Draw();
	void Delete();
	void moveLeft();
	void Copy();
};

class Lion : public Enemy {
public:
	Lion(int Y);
	/*~Lion();
	void Draw();
	void Delete();
	void moveLeft();
	void Copy();*/
};