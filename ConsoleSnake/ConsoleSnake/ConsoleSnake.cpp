#include <iostream>
#include "Game.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>

int main()
{
	 

	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = false;
	CCI.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);

	Game game;
	game.SetGameSettings(true, 20, 20);
	game.StartGame();



	_getch();

	return 0;
}
