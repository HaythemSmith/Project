#pragma once
#include "ConsoleAndColor.h"
class Map
{
private:
	COORD height[94];
	COORD weight[198];
	COORD corner[4];
public:
	void Draw();
};

