#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
char dp[50005];
int nodefinal;
 
int labyr = 0;
struct AdjListNode
{
    int dest;
    int length;
    struct AdjListNode* next;
};
 
struct AdjList
{
    struct AdjListNode *head;  
};
 
struct Graph
{
    int V;
    struct AdjList* array;
};
 
struct AdjListNode* newAdjListNode(int dest, int length)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    newNode->length = length;
    return newNode;
}
 
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    graph->array = (struct AdjList*) malloc((V+1) * sizeof(struct AdjList));
 
    int i;
    for (i = 1; i <= V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest, int l)
{
   
    struct AdjListNode* newNode = newAdjListNode(dest,l);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newAdjListNode(src,l);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


void dfs(struct Graph* g, int n, int d)
{
	int sum = 0;
	dp[n] = 1;
	struct AdjListNode* newnode = g->array[n].head;
	while(newnode)
	{
		if(dp[newnode->dest] != 1)
		{
			dfs(g, newnode->dest, d+ newnode->length);
			if(d + newnode->length > labyr)
			{
				nodefinal = newnode->dest;
				labyr = d + newnode->length;
			}
			
		}
		newnode = newnode->next;
	}
	dp[n] = 0;
}




int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ofstream myfile("test.txt");
		labyr = 0;
		int n;

		scanf("%d", &n);
		struct Graph* g = createGraph(n);
		int src, dest, len;
		for(int i=0; i<n-1; i++)
		{
			scanf("%d %d %d", &src, &dest, &len);
			addEdge(g, src, dest, len);
		}
		dfs(g, src, 0);

		labyr = 0;
		dfs(g, nodefinal,0);
		cout << labyr << endl;
	}
}