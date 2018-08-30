int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);



/*
Take Only Valid Input W,A,S,D,w,a,s,d . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
*/
char takeInput()
{
	/*
	Take input and return it ,Use fflush if scanf is being used .
	Does this function need fflush ? Whats fflush ? Post your observations in the forum ,if fflush is present/not present.
	*/
	char c;
	do{
		fflush(stdin);
		scanf("%c", &c);
	} while (!(c != 'w' || c != 'W' || c != 'a' || c != 'A' || c != 's' || c != 'S' || c != 'd' || c !='D'));
	return c;
}
/*
Return 1 for Valid Input ie if w,a,s,d,W,A,S,D are entered .
Return 0 for all other inputs
*/
int isValidInput(char letter){
	if (letter == 'w' || letter == 'W' || letter == 'a' || letter == 'A' || letter == 's' || letter == 'S' || letter == 'd' || letter == 'D')
		return 1;
	else
		return 0;
}
/*
Process the Given Input .Ie Decide whether to move Left , Right , Up ,or Down based on W,A,S,D,w,a,s,d.
Call goLeft Function if A or a are entered.,similarly do for all valid inputs .
Output :
Returns 1 : If Input is Valid and Move is also Valid .
Returns 0 : If Input if Valid and Move is Invalid .
Returns 0: If Input is invalid ,like other letters are entered or sent through takeInput.
*/
int processInput(Board *board, char inputChar)
{

	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right
	*/
	int ret=0;
	int c;
	bool flag = false;
	if (inputChar == 'w' || inputChar == 'W')
	{
		ret = goUp(board);
		flag = true;
	}
	else if (inputChar == 'd' || inputChar == 'D')
	{
		ret = goRight(board);
		flag = true;
	}
	else if (inputChar == 's' || inputChar == 'S')
	{
		ret = goDown(board);
		flag = true;
	}
	else if (inputChar == 'a' || inputChar == 'A')
	{
		ret = goLeft(board);
		flag = true;
	}
	if (ret == 1 && flag == true)
		return 1;
	else
		return 0;
}

/*
This Method is invoked when a character is taken as input ie User has played his ValidMove ,and you need to proccess that Move .
Steps to be Done :
1)Call ProcessInput
2)Call modifyMoveCountBasedOnProccessInput and also pass Step 1s output
3)Call clearAndRedrawScreen
4)Call printUser
*/
void playMove(Board *board, User *user, char choice){
	int pio = processInput(board, choice);
	modifyMoveCountBasedOnProccessInput(user, pio);
	clearAndRedrawScreen(board);
	printUser(user);
}

/*
Move the 0 Tile one position to the left .
Return 1 if the move is possible, 0 other wise .
*/
int goLeft(Board *board)
{
	int i = 0, j = 0;
	int r, c;
	r = board->rows;
	c = board->cols;
	bool flag = false;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (board->table[i][j] == 0 && j != c - 1)
			{
				if (flag == true)
					break;
				swap(board, i, j, i, j + 1);
				flag = true;
			}
		}
	}
	if (flag == true)
		return 1;
	else
		return 0;
}

/*
Move the 0 Tile one position to the Right.
Return 1 if the move is possible, 0 other wise .
*/
int goRight(Board *board)
{
	int i = 0, j = 0;
	int r, c;
	r = board->rows;
	c = board->cols;
	bool flag = false;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (board->table[i][j] == 0 && j != 0)
			{
				if (flag == true)
					break;
				swap(board, i, j, i, j - 1);
				flag = true;
			}
		}
	}
	if (flag == true)
		return 1;
	else
		return 0;
}

/*
Move the 0 Tile one position to the UP .
Return 1 if the move is possible, 0 other wise .
*/
int goUp(Board *board){
	int i = 0, j = 0;
	int r, c;
	r = board->rows;
	c = board->cols;
	int flag = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (board->table[i][j] == 0 && i != c - 1)
			{
				if (flag == true)
					break;
				swap(board, i, j, i + 1, j);
				flag = 1;
			}
		}
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}

/*
Move the 0 Tile one position to the Down .
Return 1 if the move is possible, 0 other wise .
*/
int goDown(Board *board){
	int i = 0, j = 0;
	int r, c;
	r = board->rows;
	c = board->cols;
	int flag = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (board->table[i][j] == 0 && i != 0)
			{
				if (flag == true)
					break;
				swap(board, i, j, i - 1, j);
				flag = 1;
			}
		}
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}


/*
You can use this Helper SWAP Function which can remove lots of extra Code from above functions .
*/
void swap(Board *board, int x1, int y1, int x2, int y2)
{
	int temp = board->table[x1][y1];
	board->table[x1][y1] = board->table[x2][y2];
	board->table[x2][y2] = temp;
	board->emptyTileRow = x2;
	board->emptyTileCol = y2;
}
