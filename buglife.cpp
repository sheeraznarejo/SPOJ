#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

char connections[2005][2005];
char visited[2005] ; 
int main()
{
	int n;
	scanf("%d", &n);
	
	int looper = 1;
	while(n--)
	{
		
		int V, E, v1, v2;
		scanf("%d %d", &V, &E);
		char blue[V+1]; 
		char red[V+1];
		for(int k=0; k<= V; k++)
		{
			blue[k] = 0;
			red[k] = 0;
		}
		queue<pair<int,int> > q;
		memset(connections, 0, sizeof(connections));
		memset(visited, 0, sizeof(visited));
		while(E--)
		{
			scanf("%d %d", &v1, &v2); 
			connections[v1][v2] =  1;
			connections[v2][v1] = 1;
		}
		int startingnode = 1;
		pair<int,int> p1 = make_pair(startingnode,0);
		q.push(p1);
		red[startingnode] = 1;
		while(!q.empty())
		{
			pair<int,int> p = q.front();
			int b = p.first;
			visited[b] = -1;
			q.pop();
			int color = p.second;
			for(int i=1; i<= V; i++)
			{
				if(i == b) continue;
				if(connections[b][i] == 1 && visited[i]!= -1)
				{
					if(color == 0) 
					{
						blue[i] = 1;
						if(red[i] != 0)
						{
							printf("Scenario #%d:\nSuspicious bugs found!\n", looper);
							return 0;
						}
					}
					if(color ==1)
					{
						red[i] = 1;
						if(blue[i] != 0)
						{
							printf("Scenario #%d:\nSuspicious bugs found!\n", looper);
							return 0;
						}

					}
					pair<int,int> p2 = make_pair(i, 1-color);
					q.push(p2);
				} 
			}
		}
		printf("Scenario #%d:\nNo suspicious bugs found!\n", looper);
		looper++;
	}
}