#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fstream>
#include <iostream>

using namespace std;
int P[505];
int W[505];
int dp[505][10005];

int min(int a, int b)
{
  return (a < b) ? a : b;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    ofstream myfile;
    myfile.open("test.txt");
    int a, b;
    scanf("%d %d", &a, &b);
    int weight = b - a;
    int N;
    scanf("%d", &N);
    for(int i=0; i<= N; i++)
      for(int j=0; j<=weight; j++)
        dp[i][j] = INT_MAX;
    for(int i=0; i<N; i++)
    {
      scanf("%d %d", &P[i], &W[i]);
      dp[i][W[i]] = P[i];
    }
    dp[0][0] = 0;
    for(int i = 1; i<= N; i++)
    {
      dp[i][0] = 0;
      for(int j = 1; j<= weight; j++)
      {
        if(j >= W[i-1])
        {
          int a;
          int b =  dp[i][j-W[i-1]] + P[i-1];
          if( b >= 0)
          {
           a = min(dp[i-1][j], b);
           dp[i][j] = min(a, dp[i][j]);
          }
          else
            dp[i][j] = min(dp[i-1][j], dp[i][j]);
        }
        else
          dp[i][j] = dp[i-1][j];
      }
    }


    if(dp[N][weight] == INT_MAX) printf("This is impossible.\n");
    else 
      printf("The minimum amount of money in the piggy-bank is %d.\n", dp[N][weight]);

    /*for(int i=1; i<= N; i++)
    {
      for(int j=1; j<= weight; j++)
        printf("%d ", dp[i][j]);
      printf("\n");
    } */

  }
}