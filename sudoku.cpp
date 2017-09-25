// sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include"stdlib.h"
void swapint(int fir, int sec);
void perm(int arr[], int begin, int end);
void swap(int betsudoku[], int i1, int i2, int i3, int i4, int i5, int i6);
int* transform(int firstline[], int modelsudoku[]);
int oralsudoku[82]=
{
	2,5,8,6,1,9,3,4,7,
	6,3,7,2,5,4,9,8,1,
	9,4,1,3,7,8,5,2,6,
	3,7,5,8,2,1,6,9,4,
	8,6,2,4,9,5,7,1,3,
	4,1,9,7,6,3,8,5,2,
	5,9,4,1,3,6,2,7,8,
	1,2,6,9,8,7,4,3,5,
	7,8,3,5,4,2,1,6,9
};
//int permnum = 0;
int linenum[9][9] =
{
	0,9,18,27,36,45,54,63,72,
	1,10,19,28,37,46,55,64,73,
	2,11,20,29,38,47,56,65,74,
	3,12,21,30,39,48,57,66,75,
	4,13,22,31,40,49,58,67,76,
	5,14,23,32,41,50,59,68,77,
	6,15,24,33,42,51,60,69,78,
	7,16,25,34,43,52,61,70,79,
	8,17,26,35,44,53,62,71,80
};
int queuenum[9][9] =
{
	0,1,2,3,4,5,6,7,8,
	9,10,11,12,13,14,15,16,17,
	18,19,20,21,22,23,24,25,26,
	27,28,29,30,31,32,33,34,35,
	36,37,38,39,40,41,42,43,44,
	45,46,47,48,49,50,51,52,53,
	54,55,56,57,58,59,60,61,62,
	63,64,65,66,67,68,69,70,71,
	72,73,74,75,76,77,78,79,80
};

int oralline[9] = { 7,8,9,1,2,3,4,5,6 };

int main()
{
	int* sudokuout = (int * )malloc(sizeof(int)*81) ;
	sudokuout = transform(oralline, oralsudoku);
	int i = 0;
	int j = 0;
	/*for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%d,", sudokuout[9 * i + j]);
		}
		printf("\n");

	}*/


	int sudokunum =1000000;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;
	int i5 = 0;
	int i6 = 0;
	int nownum = 0;
	for (nownum = 0; nownum < sudokunum; )
	{
		if (i1 == 3)
		{
			perm(oralline,1,8);
			sudokuout = transform(oralline, oralsudoku);
		}
		for (i1 = 0; i1 <= 2; i1++)
		{
			for (i2 = 0; i2 <= 6; i2++)
			{
				for (i3 = 0; i3 <= 6; i3++)
				{
					for (i4 = 0; i4 <= 2; i4++)
					{
						for (i5 = 0; i5 <= 6; i5++)
						{
							for (i6 = 0; i6 <= 2; i6++)
							{
								swap(sudokuout, i1, i2, i3, i4, i5, i6);
								for (i = 0; i < 9; i++)
								{
									for (j = 0; j < 9; j++)
									{
										printf("%d,", sudokuout[9*i+j]);
									}
									printf("\n");

								}
								printf("\n");
								printf("%d\n",nownum);
								nownum++;
								if (nownum >= sudokunum)
								{
									return 0;
								}
								
							}
						}
					}
				}
			}
		}
	}
	
    return 0;
}

void swapint(int fir, int sec)
{
	int temp = fir;
	fir = sec;
	sec = temp;
}

void perm(int arr[], int begin, int end) {
	if (end == begin) {        
		
		
		
		return;
	}
	else {
		int j = 0;
		for ( j = begin; j <= end; j++) {
			swapint(begin, j);      
			perm(arr, begin + 1, end);   
			swapint(begin, j);      
		}
	}
}



void swap(int betsudoku[], int i1, int i2, int i3, int i4, int i5, int i6)
{
	int temp = 0;
	int i = 0;
	if (i1 == 1)
	{
		for (i = 0; i < 9; i++)
		{
			 temp = 0;
			temp= betsudoku[linenum[1][i]];
			betsudoku[linenum[1][i]]= betsudoku[linenum[2][i]];
			betsudoku[linenum[2][i]]= temp;
		}
	}
	else if (i1 == 2)
	{
		for (i = 0; i < 9; i++)
		{
			 temp = 0;
			temp = betsudoku[linenum[1][i]];
			betsudoku[linenum[1][i]] = betsudoku[linenum[2][i]];
			betsudoku[linenum[2][i]] = temp;
		}
	}
	else
	{
		;
	}

	if (i2 % 2 == 1)
	{
		for (i = 0; i < 9; i++)
		{
			temp = betsudoku[linenum[3][i]];
			betsudoku[linenum[3][i]] = betsudoku[linenum[4][i]];
			betsudoku[linenum[4][i]] = temp;
		}
	}
	else if (i2 % 2 == 0 && i2 != 0)
	{
		for (i = 0; i < 9; i++)
		{
			temp = betsudoku[linenum[4][i]];
			betsudoku[linenum[4][i]] = betsudoku[linenum[5][i]];
			betsudoku[linenum[5][i]] = temp;
		}
	}
	else
	{
		;
	}

	if (i3 % 2 == 1)
	{
		for (i = 0; i < 9; i++)
		{
			temp = betsudoku[linenum[6][i]];
			betsudoku[linenum[6][i]] = betsudoku[linenum[7][i]];
			betsudoku[linenum[7][i]] = temp;
		}
	}
	else if (i2 % 2 == 0 && i2 != 0)
	{
		for (i = 0; i < 9; i++)
		{
			temp = betsudoku[linenum[7][i]];
			betsudoku[linenum[7][i]] = betsudoku[linenum[8][i]];
			betsudoku[linenum[8][i]] = temp;
		}
	}
	else
	{
		;
	}

	if (i4 == 1)
	{
		temp = betsudoku[queuenum[1][i]];
		betsudoku[queuenum[1][i]] = betsudoku[queuenum[2][i]];
		betsudoku[queuenum[2][i]] = temp;
	}
	else if (i4 == 2)
	{
		temp = betsudoku[queuenum[1][i]];
		betsudoku[queuenum[1][i]] = betsudoku[queuenum[2][i]];
		betsudoku[queuenum[2][i]] = temp;
	}
	else
	{
		;
	}

	if (i5 % 2 == 1)
	{
		for (i = 0; i < 9; i++)
		{
			temp = betsudoku[queuenum[3][i]];
			betsudoku[queuenum[3][i]] = betsudoku[queuenum[4][i]];
			betsudoku[queuenum[4][i]] = temp;
		}
	}
	else if (i5 % 2 == 0 && i5 != 0)
	{
		for (i = 0; i < 9; i++)
		{
			temp = betsudoku[queuenum[4][i]];
			betsudoku[queuenum[4][i]] = betsudoku[queuenum[5][i]];
			betsudoku[queuenum[5][i]] = temp;
		}
	}
	else
	{
		;
	}

	if (i6 % 2 == 1)
	{
		for (i = 0; i < 9; i++)
		{
			temp = betsudoku[queuenum[6][i]];
			betsudoku[queuenum[6][i]] = betsudoku[queuenum[7][i]];
			betsudoku[queuenum[7][i]] = temp;
		}
	}
	else if (i6 % 2 == 0 && i6 != 0)
	{
		for (i = 0; i < 9; i++)
		{
			temp = betsudoku[queuenum[7][i]];
			betsudoku[queuenum[7][i]] = betsudoku[queuenum[8][i]];
			betsudoku[queuenum[8][i]] = temp;
		}
	}
	else
	{
		;
	}



}
 

int* transform(int firstline[],int modelsudoku[] )
{
	int  *temp = (int*)malloc(sizeof(int)*81) ;
	
	int i = 0;
	int j = 0;
	int k = 0;
	for (k = 0; k < 9; k++)
	{
		temp[k] = firstline[k];
	}
	for (i = 9; i < 81; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (modelsudoku[i] == modelsudoku[j])
			{
				temp[i] = temp[j];
			}
		}
		
	}
	int m = 0;
	
	return temp;
}