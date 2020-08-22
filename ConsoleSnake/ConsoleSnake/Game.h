#pragma once
#include "Direction.h"
#include "Snake.h"
#include "Food.h"
#include "FrontStyle.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>



class Game
{
private:
	bool GameIsOver = false;
	bool MoveOverBorder = true;
	bool foodIsEaten;

	//Размеры карты
	int MapHeight;
	int MapWidth;

	//Задержка перемещения в мс
	int Speed = 200;

	//Начальная позиция при старте
	int StartX = 5;
	int StartY = 5;

	/*====ICONS====*/
	
	//Иконка корма
	char foodIcon = 'o';
	 
	int foodX;
	int foodY;

	//Иконки головы и хвоста соответсвенно
	char HeadIcon = '@';
	char TailIcon = 'O';

	//Иконка границы карты
	char MapBorderIcon = '#';
	//char MapBorderIcon = '.';



	//Направление движения
	Direction dir = Stop;

	//Змейка
	Snake snake = Snake(HeadIcon, TailIcon, StartX, StartY);

public:
	//Главный цикл
	void StartGame();

	//Закончить игру ???
	void EndGame();

	//Установка настроек игры
	void SetGameSettings(bool _MoveOverBoard, int Width, int Height);

	//Установка направления движения головы
	void SetDirection(Direction _dir);

private:
	//Установить курсор в позицию (x, y)
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}


	//Установить и отрисовать
	//размеры карты размером W x H
	void SetMap(int W, int H);

	//Переместить один элемент в позицию (x, y)
	void Move(Element& el, int x, int y);

	//Переместить голову змеи в позицию (x, y)
	//а также туловище за ней
	void MoveSnake(int x, int y);

	//Создать корм на карте
	void CreateFood();

	//Увеличить змею при поедании корма
	void IncreaseSnake();

	//Если съедина само собой
	void EatenByItsSelf();

};

