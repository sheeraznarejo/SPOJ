#include <cstring>
#include <stdio.h>
int best[1001][25][85] = {1000000};
int wt[1001];
int vo[1001];
int vn[1001];

int min(int a, int b)
{
	return (a<b) ? a : b;
}

void knapsack(int n)
{
	for(int i=0; i<=n-1; i++)
	{
		scanf("%d %d %d", &vo[i], &vn[i], &wt[i]);
	}

	for(int o =0; o<=vo[0]; o++)
		for(int k=0; k<=vn[0]; k++)
		{
			best[1][o][k] = wt[0];
		}

	for(int i=2; i<=n; i++)
	{
		int oxy = vo[i-1]; int nit = vn[i-1];
		for(int o =0; o<=24; o++)
			for(int k=0; k<=84; k++)
		{
			int reducedo = o - oxy;
			int reducedn = k - nit;
			if(reducedo <0) reducedo = 0;
			if(reducedn <0) reducedn = 0;

			int mid = min(best[i-1][reducedo][reducedn] + wt[i-1], best[i-1][o][k]);
			int mid2 = min(wt[i-1], best[i-1][o][k]);

			if (reducedn == 0 && reducedo == 0)
			{
				best[i][o][k] = mid2;
				
				
			}
			else{


			if(mid >1000000)
				best[i][o][k] = 1000000;
			else
				best[i][o][k] = mid;
		}
		}	
	}

}


int main()
{
	int t, n, minoxy, minnitr;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d", &minoxy, &minnitr);
		scanf("%d", &n);
		for(int i=0; i<=n; i++)
			for(int j=0; j<=24;j++)
				for(int k=0; k<=84; k++)
				{
					best[i][j][k] = 1000000;
				}
		knapsack(n);
		/*int a,b,c;
		while(scanf("%d %d %d", &a, &b, &c) == 3)
			printf("%d\n", best[a][b][c]);
		*/
		printf("%d\n", best[n][minoxy][minnitr]);
	}

}