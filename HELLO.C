
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
int moves[9];
void welcome();
void displayBoard(int hy0, int hx1);
void tutorial();
void gameCPU();
int choose();
int random();
void updateMove(int move, int index);
void drawCross(int position);
int main()
{
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	// WELCOME HOME SCREEN
	welcome();

	//CIRCLE
	//	setcolor(LIGHTGREEN);
	//	circle(112, 88, 7);

	//cross
	//	setcolor(LIGHTRED);
	//line(105, 125, 120, 110);
	//line(105, 110, 120, 125);
	getch();
	return 0;
}
void welcome()
{
	int opt;
	printf("\n\n\n**************************** WELCOME TO TIC TAC TOE****************************\n");
	//	displayBoard(170,100);
	printf("\n\t\t\tDeveloped by Group H using C\n\n");
	tutorial();
	printf("\n\n\n\tEnter");
	printf("\t0: Play with Computer\n");
	printf("\t\t1: Local Multiplayer\n\n\t\t");
	scanf("%d", &opt);
	if (opt == 0)
		gameCPU();
	else if (opt == 1)
		printf("Local");
}
void displayBoard(int hy0, int hx0)
{
	// HORIZONTAL LINES
	int hy1 = hy0 + 30;
	int hx1 = hx0 + 75;
	//line(100, 170, 200, 170);
	line(hx0, hy0, hx1, hy0);
	//line(100, 200, 200, 200);
	line(hx0, hy1, hx1, hy1);

	// VERTICAL LINES
	//line(125, 150, 125, 220);
	line(hx0 + 25, hy0 - 20, hx0 + 25, hy1 + 20);
	//line(150, 150, 150, 220);
	line(hx0 + 50, hy0 - 20, hx0 + 50, hy1 + 20);
}
void tutorial()
{
	int i;
	displayBoard(230, 300);
	printf("\n Controls: Type your entry according to the index when its your turn\n\n\n");
	printf("\t\t\t\tIndex");
	for (i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			printf("\n\n\t\t\t");
		printf("%d  ", i);
		if (i == 5)
			printf(" =>");
	}
}
int choose()
{
	int option;
	printf("\n\tEnter:\t0 : To Play as X\n\t\t1 : To Play as O\n");
	scanf("%d", &option);
	return option;
}
void gameCPU()
{
	int user, state = 0;
	user = choose();
	printf("\t\tGAME STARTED\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	getch();
	displayBoard(280, 200);
}
int random()
{
	int num;
	srand(time(NULL));
	num = (rand() % 9);
	return num;
}
void updateMove(int move, int index)
{
	moves[index] = move;
}
void drawCross(int position)
{
	setcolor(LIGHTRED);
	line(105, 125, 120, 110);
	line(105, 110, 120, 125);
}