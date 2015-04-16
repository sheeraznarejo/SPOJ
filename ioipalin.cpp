/* SPOJ IOIPALIN */

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

int dp[5010][5010];


int max(int a, int b)
{
	return (a>b) ? a : b;
}

using namespace std;

int lcs(char X[], int n) 
{
	for(int i = 1; i<= n; i++)
		for(int j = 1; j<= n; j++)
		{
			if(X[i-1] == X[n - j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

		}	
	return dp[n][n];
}


int main()
{
	int n;
	scanf("%d", &n);
	char X[n];
	scanf("%s", X);
	printf("%d\n", n - lcs(X, n )); 
}

