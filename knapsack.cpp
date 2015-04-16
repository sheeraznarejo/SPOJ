#include <stdio.h>
int max(int a, int b)
{
  return (a>b) ? a : b;
}

int dp[21] = {-1000};
int knapsack(int weights[], int values[], int V, int n,int min)
{
  for(int i = min; i<= V; i++)
  {
    int a = 0;
    for(int j = 1; j<= n; j++)
    {
      if(i >= weights[j]);
        a = max(a, values[j] + dp[i-weights[j]]);
    }
  }
  return dp[V];
}


int main()
{
  int values[] = {0,2,3,6,7,9,12,14};
  int weights[] = {0,2, 4,5,7,7,11,12};
  printf("%d\n", knapsack(weights,values, 20, 7,2));
  
}