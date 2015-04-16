/* SPOJ Problem BITMAP 
Algorithm : Breadth First Search */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <queue>
#include <fstream>
using namespace std;

int dist[183][183];
char dp[183][183];

int dx[] = {1, -1, 0, 0};
int dy[] = {0,  0, 1,-1};

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{

		int rows, columns;
		scanf("%d %d", &rows, &columns);
		queue<pair<int,int> > s;
		char bitmp[rows][columns];

		for(int i = 0; i<rows; i++)
			scanf("%s", bitmp[i]);
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<columns; j++)
			{
				if(bitmp[i][j] == '1')
				{
					pair<int,int> p = make_pair(i,j);
					dist[i][j] = 0;
					s.push(p);
				}
				else dist[i][j] = 365; 
			}

		}

		while(!s.empty())
		{
			pair<int,int> start = s.front();
			s.pop();
			memset(dp,0,sizeof(dp));
			queue<pair<int,int> > l;
			l.push(start);
			while(!l.empty())
			{
				pair<int,int> p3 = l.front();
				l.pop();
				dp[p3.first][p3.second] = -1;
				for(int i=0; i<4; i++)
				{
					int x = p3.second + dx[i];
					int y = p3.first + dy[i];
					if(x >=0 && x < columns && y >=0 && y< rows && dp[y][x] != -1 && bitmp[y][x] =='0')
					{

						if(dist[y][x] > dist[p3.first][p3.second] + 1)
						{
							dist[y][x] = dist[p3.first][p3.second] + 1;
							pair<int,int> p2 = make_pair(y,x);
							l.push(p2);		
						}
						
					}
					
				}
			}
		}
		for(int i=0; i< rows; i++)
		{
			for(int j=0; j<columns; j++)
			{
				printf("%d ", dist[i][j]);
			}
			printf("\n");
		}
	

	}
}