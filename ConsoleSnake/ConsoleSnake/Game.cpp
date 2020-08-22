#include "Game.h"

void Game::StartGame()
{
	 



	//const int NotUsed = system("color 20");

	gotoxy(StartX, StartY);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4|FOREGROUND_INTENSITY);
	std::cout << HeadIcon;
	//std::cout << L'♥';
	
	FrontStyle::CountLogo(MapWidth, snake);

	
	CreateFood();



	while (!GameIsOver)
	{
		SetMap(MapWidth, MapHeight);
		if (foodIsEaten)
			CreateFood();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
		gotoxy(foodX, foodY);
		std::cout << foodIcon;

		int code;
		if (_kbhit())
		{
			if (_getch() == 224)
			{
				code = _getch();

				switch (code)
				{
				case 75:
					if (dir != Right || snake.SnakePosition.size() == 1)
						SetDirection(Left);
					break;
				case 77:
					if (dir != Left || snake.SnakePosition.size() == 1)
						SetDirection(Right);
					break;
				case 72:
					if (dir != Down || snake.SnakePosition.size() == 1)
						SetDirection(Up);
					break;
				case 80:
					if (dir != Up || snake.SnakePosition.size() == 1)
						SetDirection(Down);
					break;

				default:
					break;
				}
			}
		}

		if (dir != Stop)
		{
			Element el = snake.SnakePosition[0];
			switch (dir)
			{
			case Up:
				MoveSnake(el.X, el.Y - 1);
				break;
			case Down:
				MoveSnake(el.X, el.Y + 1);
				break;
			case Left:
				MoveSnake(el.X - 1, el.Y);
				break;
			case Right:
				MoveSnake(el.X + 1, el.Y);
				break;
			default:
				break;
			}

			Sleep(Speed);
		}

	}

	EndGame();
}

void Game::EndGame()
{
	system("cls");
	Beep(1000, 80);
	FrontStyle::EndLogo(snake);
}

void Game::SetGameSettings(bool _MoveOverBoard, int Width, int Height)
{
	MoveOverBorder = _MoveOverBoard;

	StartX = Width / 2;
	StartY = Height / 2;

	snake.SnakePosition[0].X = StartX;
	snake.SnakePosition[0].Y = StartY;

	MapHeight = Height;
	MapWidth = Width;
	FrontStyle::StartLogo();

	SetMap(Width, Height);
}

void Game::SetDirection(Direction _dir)
{
	dir = _dir;
}

void Game::SetMap(int W, int H)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  6 | FOREGROUND_INTENSITY);


	/*
		Верхние и нижние рамки
		0--------------------W




		H---------------------
	*/
	for (int x = 0; x < W; x++)
	{

		//Верхняя границы
		gotoxy(x, 0);
		std::cout << MapBorderIcon;

		//Нижняя граница
		gotoxy(x, H - 1);
		std::cout << MapBorderIcon;
	}


	/*
	Бокововые границы
		|		|
		|		|
		|		|
		|		|
		|		|
	*/

	for (int y = 0; y < H; y++)
	{
		//Левая границы
		gotoxy(0, y);
		std::cout << MapBorderIcon;

		//Правая граница
		gotoxy(W - 1, y);
		std::cout << MapBorderIcon;

	}

}

void Game::Move(Element& el, int x, int y)
{
	//Установить в новую позицию
	gotoxy(x, y);
	std::cout << el.Icon;

	//Стереть старую
	gotoxy(el.X, el.Y);
	std::cout << " ";

	//Записать новые координаты
	el.X = x;
	el.Y = y;

}

void Game::MoveSnake(int x, int y)
{
	int CurrentX, CurrentY;

	int X = x, Y = y;

	int OldX = snake.SnakePosition[0].X;
	int OldY = snake.SnakePosition[0].Y;

	//Если съеден корм
	if (x == foodX && y == foodY)
	{
		foodIsEaten = true;
		IncreaseSnake();
	}


	//Если достигнута граница карты
	if (x == 0 || x == MapWidth - 1 || y == 0 || y == MapHeight - 1)
	{
		if (MoveOverBorder)
		{
			if (x == 0) X = MapWidth - 2;

			if (x == MapWidth - 1) X = 1;

			if (y == 0) Y = MapHeight - 2;

			if (y == MapHeight - 1) Y = 1;
		}
		else
		{
			GameIsOver = true;
		}

	}

	//Если сьел хвост
	if (snake.SnakePosition.size() >= 4)
	{
		for (int i = 1; i < snake.SnakePosition.size(); i++)
		{
			if (
				snake.SnakePosition[0].X == snake.SnakePosition[i].X
				&&
				snake.SnakePosition[0].Y == snake.SnakePosition[i].Y
				)
			{
				EatenByItsSelf();
				GameIsOver = true;
				return;
			}
		}
	}

	//Двигаем голову
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
	Move(snake.SnakePosition[0], X, Y);
	if (snake.SnakePosition.size() == 1)
		return;


	//Двигаем хвост
	for (int i = 1; i < snake.SnakePosition.size(); i++)
	{
		CurrentX = snake.SnakePosition[i].X;
		CurrentY = snake.SnakePosition[i].Y;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
		Move(snake.SnakePosition[i], OldX, OldY);

		OldX = CurrentX;
		OldY = CurrentY;
	}



}

int x[] = { 1 };
int y[] = { 1 };
std::vector<int> X{ 1,2,34 };

void Game::CreateFood()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
	foodIsEaten = false;

	bool IsFree = false;
	int x, y;
	//Генерируем случайные координаты для корма
	//Генерериуем пока не поймем, что клетка свободна
#pragma region MyRegion


	//while (!IsFree)
	//{
	//	x = rand() % (MapWidth - 1);
	//	y = rand() % (MapHeight - 1);

	//	int count = 0;

	//	if (x == 0) x++;
	//	if (y == 0) y++;

	//	for (auto el : snake.SnakePosition)
	//	{
	//		//Нашли занятый блок - прерываем цикл
	//		if (el.X == x && el.Y == y)
	//			break;

	//		if (el.X != x && el.Y != y)
	//			count++;
	//	}

	//	if (count == snake.SnakePosition.size())
	//		IsFree = true;
	//}
#pragma endregion

	struct Point
	{
	public:
		int x;
		int y;
	};
	std::vector<Point> FreeCells;

	//Генерировать свободные ячейки
	for (x = 1; x < MapWidth - 1; x++)
		for (y = 1; y < MapHeight - 1; y++)
		{
			IsFree = true;

			for (auto el : snake.SnakePosition)
			{
				if (el.X == x && el.Y == y)
				{
					IsFree = false;
					break;
				}
			}

			if (IsFree)
				FreeCells.push_back(Point{ x, y });
		}

	int randCell = rand() % FreeCells.size();
	x = FreeCells[randCell].x;
	y = FreeCells[randCell].y;


	foodX = x;
	foodY = y;
	gotoxy(x, y);
	std::cout << foodIcon;

}

void Game::IncreaseSnake()
{
	Beep(600, 80);

	int x = snake.SnakePosition[snake.SnakePosition.size() - 1].X;
	int y = snake.SnakePosition[snake.SnakePosition.size() - 1].Y;

	switch (dir)
	{
	case Up:
		y++;
		break;
	case Down:
		y--;
		break;
	case Left:
		x++;
		break;
	case Right:
		x--;
		break;
	default:
		break;
	}

	/*if (y != MapHeight - 1 && y != 0 && x != 0 && x != MapWidth - 1)
	{
		snake.SnakePosition.push_back(Element{ TailIcon, x, y });
		gotoxy(x, y);
		std::cout << TailIcon;
	}*/

	snake.SnakePosition.push_back(Element{ TailIcon, x, y });
	gotoxy(x, y);
	std::cout << TailIcon;
	FrontStyle::CountLogo(MapWidth, snake);


}

void Game::EatenByItsSelf()
{
}
