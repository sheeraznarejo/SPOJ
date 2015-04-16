/* SPOJ Problem : Treats for the Cows 
Dynamic Programming */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return (a>b) ? a : b;
}

long long dp[2010][2010] ; 
// dp[a][b] contains the value of the sequence from list position a to list position b
// dp[a][b] = max(age*value(a) + dp[a+1][b], age*value(b) dp[a][b-1];

int main()
{
	int n;
	int values[2010];
	scanf("%d", &n);
	int a = n;
	int i=1;
	while(a--)
	{
		scanf("%d", &values[i++]);
	} 

	for(int i = 1; i<= n; i++)
	{
		dp[i][i] = n * values[i];
	}

	for(int i = n; i>=1; i--)
	{
		for(int j = i+1; j<= n; j++)
		{
			if(i==j)
				continue;
			int age = i + n - j;
			dp[i][j] = max(age*values[i] + dp[i+1][j], age*values[j] + dp[i][j-1]);
		}
	}

	printf("%lld\n", dp[1][n]);
}

