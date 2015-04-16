/* SPOJ ABCPATH 
Algorithm : Depth First Search */  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[] = {-1,0,1,-1,0,1,-1,1};
int dy[] = {1,1,1,-1,-1,-1,0,0};
int dp[55][55];
int maximumpathvalue = 0;
char inputarray[55][55] ; 
void maxpathcalculator(int row, int column, int maxrows, int maxcolumns, int maxpath)
{
	if(maxpath > maximumpathvalue)
		maximumpathvalue = maxpath; 
	
	for(int i=0; i<= 7; i++)
		{
			int a = row+dx[i];
			int b = column + dy[i];
			if((a >=0) && (a < maxrows) && (b >=0) && (b < maxcolumns))
				if((dp[a][b] != -1) && (inputarray[a][b] ==  inputarray[row][column] + 1) )
				{
					dp[a][b] = -1;
					maxpathcalculator(a, b, maxrows, maxcolumns, maxpath+1);	
				}		
		}	
}

int main()
{
	int rows, columns;
	int n = 1;
	scanf("%d %d", &rows, &columns);
	while(rows && columns) {
		for(int i = 0; i< rows; i++)
				scanf("%s", inputarray[i]);
		maximumpathvalue = 0;
		int count = 0;
		for(int i=0; i< rows; i++)
			for(int j = 0; j< columns; j++)
			{
				if(inputarray[i][j] == 'A')
				{
					for(int k=0; k<55; k++)
					{
						for(int l=0; l<55; l++)
							dp[k][l] = 0;
					} 
					dp[i][j] = -1;
					count = 1;
					maxpathcalculator(i, j, rows, columns, 1);
				}
			}
		if(count == 0) 
			printf("Case %d: %d\n", n, 0);
		else 
			printf("Case %d: %d\n", n, maximumpathvalue);
		scanf("%d %d", &rows, &columns) ;
		n++;
	
	}
	return 0;
}
