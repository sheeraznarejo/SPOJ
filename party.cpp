#include <stdio.h>
#include <stdlib.h>
using namespace std;

int max(int a, int b)
{
	return (a >b) ? a : b;
}
int fun[101];
int cost[101];
 // dp[i][j] == maximum fun with a cost of j;
int main()
{
	int dp[101][501] = {0};
	int budget;
	int numberofparties;
	scanf("%d %d", &budget, &numberofparties);
	while(budget && numberofparties)
	{
		for(int k=0; k<numberofparties; k++)
		{
			scanf("%d %d", &cost[k], &fun[k]);

		}
	
	for(int i=1; i<= numberofparties; i++)
	{

		for(int j= 1; j<= budget; j++)
		{
			if(j >= cost[i-1])
			{
				dp[i][j] = max(dp[i-1][j - cost[i-1]] + fun[i-1], dp[i-1][j]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	int maxcost = budget;
	int max = dp[numberofparties][budget];
	for(int i = budget; i>= 1; i--)
	{
		if(dp[numberofparties][i-1] == max) 
			maxcost = i - 1;
		else break;
	}
	printf("%d %d\n", maxcost, dp[numberofparties][budget]);
	scanf("%d %d", &budget, &numberofparties);
	}
}