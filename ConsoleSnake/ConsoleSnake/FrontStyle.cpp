#include "FrontStyle.h"




void FrontStyle::StartLogo()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::string Logo[] =
	{
	" CCCCC   OOO   N     N   SSSS   OOO   L      EEEEE ",
	"C       O   O  N N   N  S      O   O  L      E     ",
	"C       O   O  N  N  N  SSSS   O   O  L      EEEEE ",
	"C       O   O  N   N N      S  O   O  L      E     ",
	" CCCCC   OOO   N    NN  SSSS    OOO   LLLLL  EEEEE ",
	"                                                   ",
	"       SSSSS  N     N      A      K  K  EEEEE     ",
	"       S      N N   N     A A     K K   E         ",
	"       SSSSS  N  N  N    AAAAA    KK    EEEEE     ",
	"           S  N   N N   A     A   K K   E         ",
	"       SSSSS  N    NN  A       A  K  K  EEEEE      "
	};

	for (auto i : Logo)
	{
		std::cout << i << std::endl;
		Sleep(100);

	}

	_getch();
	system("cls");

}

void FrontStyle::EndLogo(Snake& snake)
{
	std::string Logo[] =
	{
	"    GGGGGG     A      M         M  EEEEE ",
	"   G          A A     M M     M M  E     ",
	"   G  GGG    AAAAA    M  M   M  M  EEEEE ",
	"   G     G  A     A   M   M M   M  E     ",
	"    GGGGG  A       A  M    M    M  EEEEE ",
	" ",
	"       OOOO   V       V  EEEEE  RRRRR       ",
	"      O    O   V     V   E      R    R      ",
	"      O    O    V   V    EEEEE  RRRRR       ",
	"      O    O     V V     E      R R         ",
	"       OOOO       V      EEEEE  R   R       ",
	" ",
	" ",
	"               Your count is",
	};
	Logo[13] += " " + std::to_string(snake.SnakePosition.size() - 1);
	for (size_t i = 0; i < 14; i++)
	{
		std::cout << Logo[i] << std::endl;
		Sleep(100);
	}
	_getch();
}

void FrontStyle::CountLogo(const int& MapWidth, Snake& snake)
{
	std::string count = "Count: ";
	count += std::to_string(snake.SnakePosition.size() - 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ (short)MapWidth + 1, 2 });
	std::cout << count;
}
