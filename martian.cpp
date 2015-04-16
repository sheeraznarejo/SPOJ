#include <stdio.h>
int dp[510][510];
int yeyenum[510][510];
int bloggium[510][510];
int maxyeyenum[510][510];
int maxbloggium[510][510];


/* SPOJ Martian Mining */

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int main()
{	

		int numberofrows, numberofcolumns;
		scanf("%d %d", &numberofrows, &numberofcolumns);
		while(numberofrows && numberofcolumns) {
			int m = numberofrows;
			int n = numberofcolumns;
			for(int i = numberofrows-1; i >=0 ; i--)
				for(int j=0; j<numberofcolumns; j++)
					scanf("%d", &yeyenum[i][j]);

			for(int i = 0; i < numberofrows; i++)
				for(int j=0; j<numberofcolumns; j++)
					scanf("%d", &bloggium[numberofrows - i -1][j]);

			for(int i = 0; i < numberofrows; i++)
			{
				int yeymax = 0;
				for(int j = 0; j<numberofcolumns; j++)
				{
					yeymax = yeymax + yeyenum[i][j];
					maxyeyenum[i][j] = yeymax;
				}
			}

			for(int j = 0; j < numberofcolumns; j++)
			{
				int blogmax = 0;
				for(int i = numberofrows-1; i>=0; i--)
				{
					blogmax = blogmax + bloggium[i][j];
					maxbloggium[i][j] = blogmax;
				}
			}

			for(int i = 0; i <numberofrows; i++)
			{
				dp[numberofrows][i] = 0;
				dp[0][i] = 0;
			}

			dp[numberofrows-1][0] = max (bloggium[numberofrows-1][0], yeyenum[numberofrows-1][0]);
			for(int i = numberofrows-1; i>=0; i--)
			{
				for(int j= 0; j< numberofcolumns; j++)
				{
					if(j==0 && i == numberofrows-1)
						continue;
					dp[i][j] = max(maxyeyenum[i][j] + dp[i+1][j], maxbloggium[i][j] + dp[i][j-1]);
				}
			}
			

			/*for(int i = numberofrows-1; i >=0; i--)
			{
				
					printf("%d ", maxyeyenum[i][numberofcolumns-1]);
				printf("\n");
			}*/

			printf("%d\n", dp[0][numberofcolumns-1]);
			scanf("%d%d", &numberofrows, &numberofcolumns);

		}
	
}