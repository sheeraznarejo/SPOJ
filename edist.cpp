/* SPOJ Problem EDIST : 
Algorithm Dynamic Programming Minimum Edit Distance */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
int min(int a, int b)
{
	return (a<b) ? a : b;
}

int dp[2005][2005];
int main()
{
	int T;
	cin >> T;
	while(T--)
	{

		dp[0][0] = 0;
		string a, b;
		cin >> a; cin >> b;
		int m = a.size();
		int n = b.size();
		for(int i=1; i<= m; i++) dp[i][0] = i;
		for(int j=1; j<= n; j++) dp[0][j] = j;
		for(int i = 1; i<= m; i++)
			for(int j = 1; j<= n; j++)
			{
				int k = 1;
				if(a[i-1] == b[j-1]) k = 0;
					int state = dp[i-1][j-1] + k;
				
					dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1) , state);
			}
		cout << dp[m][n] << endl;
	}

}