#pragma once
#include "Snake.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>

class FrontStyle
{
private:
	static int count;
public:
	static void StartLogo();
	static void EndLogo(Snake& snake);
	void SetSettingsLogo();
	static void CountLogo(const int& MapWidth,  Snake& snake);

	/*

	color HeadColor;
	color TailColor;
	color ArenaColor;

	*/
};

