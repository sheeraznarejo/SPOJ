/* SPOJ TRIKA. Dynamic Programming Problemm */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int P[25][25];
int dp[25][25];

int min(int a, int b)
{
	return (a<b) ? a : b;
}


int main()
{
	int N, M;
	int X, Y;
	scanf("%d %d", &N, &M);
	scanf("%d %d", &X, &Y);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d", &P[i][j]);
	int currentpower = 0 ; 
	for(int j = Y+1; j<= M; j++)
	{
		currentpower += P[X][j];
		dp[X][j] = currentpower;
	}
	currentpower = 0;
	for(int i = X+1; i<= N; i++)
	{
		currentpower += P[i][Y];
		dp[i][Y] = currentpower;
	}

	for(int i = X+1; i<= N; i++)
	{
		for(int j = Y+1; j<= M; j++)
		{
			dp[i][j] = min(dp[i-1][j] + P[i][j], dp[i][j-1] + P[i][j]);
		}
	}

 	int finalvalue = P[X][Y] - dp[N][M]; 
 	(finalvalue >= 0) ? printf("Y %d\n", finalvalue) : printf("N\n");
		 
	

}