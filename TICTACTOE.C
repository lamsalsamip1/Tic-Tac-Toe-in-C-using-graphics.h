
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
int moves[9], user[9], cpu[9];
void welcome();
void displayBoard(int hy0, int hx1);
void tutorial();
void gameCPU();
int randomMove();
void drawCross(int position);
void drawCircle(int position);
int getInput();
int checkStatus(int player);
void gameBoard();
void addEntry(int move, int player);
int checkSpace(int move);
int validInput(int move);
void clearSpace();
void gameOver(int player);
int checkResult(int arr[9]);
int diagonalCheck(int arr[9]);
int HorizontalCheck(int arr[9]);
int VerticalCheck(int arr[9]);

int main()
{
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	// WELCOME HOME SCREEN
	welcome();
	getch();
	return 0;
}
void welcome()
{
	//WELCOME SCREEN
	printf("\n\n\n**************************** WELCOME TO TIC TAC TOE****************************\n");
	printf("\n\t\t\tDeveloped by Samip Lamsal using C\n\n");
	tutorial();
	printf("\n\n\n\t\t\tEnter any key to start the game");
	getch();
	gameCPU();
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
void gameBoard()
{
	// HORIZONTAL LINES
	line(250, 220, 400, 220);
	//line(hx0, hy0, hx1, hy0);
	line(250, 280, 400, 280);
	//line(hx0, hy1, hx1, hy1);

	// VERTICAL LINES
	line(300, 180, 300, 320);

	line(350, 180, 350, 320);
}
// WELCOME SCREEN TUTORIAL DISPLAY
void tutorial()
{
	int i;
	displayBoard(230, 300);
	printf("\n Controls: Type your entry according to the index when its your turn\n\n\n");
	printf("\t\t\t\tIndex");
	// SHOWING THE INDEX
	for (i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			printf("\n\n\t\t\t");
		printf("%d  ", i);
		if (i == 5)
			printf(" =>");
	}
}
// GAME LOGIC
void gameCPU()
{
	int input, bot, i = 0;

	// CLEAR SCREEN FOR GAME TO START
	clrscr();
	cleardevice();

	/// GAME SCREEN
	printf("\n*********************************GAME STARTED***********************************\n");

	//DISPLAY GAME BOARD
	gameBoard();

	// CLEAR ARRAYS TO STORE USER AND CPU MOVES
	clearSpace();

	// GAME LOGIC
	while (1)
	{

		// USER LOGIC

		input = getInput();

		// GET INPUT UNTIL IT IS VALID
		while (!checkSpace(input) || !(validInput(input)))
		{
			if (!checkSpace(input))
				printf("Space occupied\n");
			else
				printf("Not valid input\n");
			input = getInput();
		}

		// ADD MOVE ENTRY TO THE ARRAYS
		addEntry(input, 0);
		i++;

		// DRAW THE CROSS
		drawCross(input);

		// CHECK IF USER HAS WON THE GAME
		if (checkStatus(0) == 1)
		{
			gameOver(0);
			break;
		}

		// CHECK IF THE GAME HAS BECOME DRAW
		else if (checkStatus(0) == 2)
		{
			gameOver(2);
			break;
		}

		// COMPUTER LOGIC
		bot = randomMove();

		// GENERATE RANDOM MOVE UNTIL IT IS VALID
		while (!(checkSpace(bot)))
		{
			bot = randomMove();
		}
		// ALSO PRINT WHAT WAS GENERATED
		printf("\t\t\t\t\t\t\tCPU entered %d\n", bot);

		// ADD THE MOVE TO THE ARRAYS
		addEntry(bot, 1);
		i++;

		// DRAW THE CIRCLE
		drawCircle(bot);

		// CHECK IF THE COMPUTER HAS WON THE GAME
		if (checkStatus(1) == 1)
		{
			gameOver(1);
			break;
		}
	}
	// END OF GAME
	printf("\n\n\n*********************************GAME END**********************************");
}
// GENERATE RANDOM MOVE FOR CPU
int randomMove()
{
	int num;
	srand(time(NULL));
	num = (rand() % 9);
	return num;
}
// DRAW CROSS FROM INPUT VALUE
void drawCross(int position)
{
	int x1, y1, x2, y2;
	setcolor(LIGHTRED);
	// DETETERMINE COORDINATES USING INPUT
	if (position >= 0 && position < 3)
	{
		y1 = 190;
	}
	else if (position >= 3 && position < 6)
	{
		y1 = 240;
	}
	else if (position >= 6 && position < 9)
	{
		y1 = 290;
	}
	y2 = y1 + 20;
	if (position % 3 == 0)
		x1 = 260;
	else if (position % 3 == 1)
		x1 = 315;
	else if (position % 3 == 2)
		x1 = 370;
	x2 = x1 + 20;
	// DRAW THE LINES
	line(x1, y1, x2, y2);
	line(x2, y1, x1, y2);
}

// DRAW CIRCLE USING INPUT
void drawCircle(int position)
{
	int h, k, r = 12;
	setcolor(LIGHTGREEN);
	//DETERMINE COORDINATES USING INPUT
	if (position >= 0 && position < 3)
	{
		k = 200;
	}
	else if (position >= 3 && position < 6)
	{
		k = 250;
	}
	else if (position >= 6 && position < 9)
	{
		k = 300;
	}
	if (position % 3 == 0)
		h = 275;
	else if (position % 3 == 1)
		h = 325;
	else if (position % 3 == 2)
		h = 375;

	// DRAW THE CIRCLE
	circle(h, k, r);
}
// GET USER INPUT
int getInput()
{
	int input;
	printf("\tEnter your input ");
	scanf("%d", &input);
	return input;
}
// ADD THE ENTIRES TO THE ARRAYS
void addEntry(int move, int player)
{
	// ADD TO ALL MOVES ARRAY
	moves[move] = 1;

	// CHECK WHERE THE MOVE CAME FROM
	if (player == 0)
	{
		// ADD TO USER ARRAY
		user[move] = 1;
	}

	else if (player == 1)
	{
		//ADD TO COMPUTER ARRAY
		cpu[move] = 1;
	}
}
// CHECK IF THE INPUT POSITION IS OCCUPIED OR NOT
int checkSpace(int move)
{
	if (moves[move] == 1)
		return 0;
	else
		return 1;
}
// CHECK IF INPUT IS IN RANGE (0-9)
int validInput(int move)
{
	if (move >= 0 && move < 9)
		return 1;
	else
		return 0;
}
// RESET THE ARRAYS TO A SPECIFIC VALUE IN THE BEGINNING TO AVOID ERRORS
void clearSpace()
{
	int i;
	for (i = 0; i < 9; i++)
	{
		moves[i] = 20;
	}
	for (i = 0; i < 9; i++)
	{
		user[i] = 20;
		cpu[i] = 20;
	}
}
// CHECK FOR A WINNER
int checkResult(int arr[9])
{
	if (diagonalCheck(arr) || horizontalCheck(arr) || verticalCheck(arr))
		return 1;
	else
		return 0;
}
// CHECK CURRENT STATUS OF GAME
int checkStatus(int player)
{
	int result, i, c = 0;
	// CHECK WHO MADE THE LAST MOVE AND PASS THAT ARRAY
	if (player == 0)
	{

		result = checkResult(user);
	}
	else if (player == 1)
	{

		result = checkResult(cpu);
	}
	if (result == 1)
		return 1;
	// CHECK IF ALL THE MOVES ARE ALREADY DONE.
	for (i = 0; i < 9; i++)
	{
		if (moves[i] == 1)
			c++;
	}
	// IF SO THEN GAME IS DRAW
	if (c == 9)
	{
		return 2;
	}
	return 0;
}
// DISPLAY MESSAGE AFTER GAME IS OVER DEPENDING ON WINNER
void gameOver(int player)
{
	if (player == 0)
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t     CONGRATULATIONS YOU WON !");
	else if (player == 1)
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tThe Computer won . Better luck next time !");
	else if (player == 2)
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tThe game has ended DRAW !");
}
// CHECK DIAGONALLY IF ANYONE HAS WON THE GAME
int diagonalCheck(int arr[9])
{
	if (arr[0] == 1 && arr[4] == 1 && arr[8] == 1)
		return 1;
	else if (arr[2] == 1 && arr[4] == 1 && arr[6] == 1)
		return 1;
	else
		return 0;
}
//CHECK HORIZONTALLY IF ANYONE HAS WON THE GAME
int horizontalCheck(int arr[9])
{
	if (arr[0] == 1 && arr[1] == 1 && arr[2] == 1)
		return 1;
	else if (arr[3] == 1 && arr[4] == 1 && arr[5] == 1)
		return 1;
	else if (arr[6] == 1 && arr[7] == 1 && arr[8] == 1)
		return 1;
	else
		return 0;
}
// CHECK VERTICALLY IF ANYONE HAS WON THE GAME
int verticalCheck(int arr[9])
{
	if (arr[0] == 1 && arr[3] == 1 && arr[6] == 1)
		return 1;
	else if (arr[1] == 1 && arr[4] == 1 && arr[7] == 1)
		return 1;
	else if (arr[2] == 1 && arr[5] == 1 && arr[8] == 1)
		return 1;
	else
		return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
