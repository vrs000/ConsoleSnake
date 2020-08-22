#pragma once
#include "Element.h"
#include <vector>


class Snake
{
private:
	char HeadIcon;
	char TailIcon;

public:
	std::vector<Element> SnakePosition;

	Snake(char Head, char Tail, int StartX, int StartY);

};

