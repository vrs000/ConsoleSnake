#include "Snake.h"

Snake::Snake(char Head, char Tail, int StartX, int StartY)
{
	HeadIcon = Head;
	TailIcon = Tail;

	SnakePosition.push_back(Element{HeadIcon, StartX, StartY });
}
