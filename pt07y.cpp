/* Implementation of Union Find Algorithm 

A disjoint set datastructure is a data structure that keeps track of elements partitioned into a number of disjoint
subsets. A union find algorithm is an algorithm that performs two useful operations on such a data structure : 
1. Find : Find which particular subset an element is in.
2. Union : Join two subsets   */


// A union-find algorithm to detect cycle in a graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Edge
{
    int src, dest;
};
 
class Graph
{
	private : 
    int V;
    int E;
    int *parent;
    struct Edge* edge;


    public :
    Graph(int,int);
    void printparent(void);
    int find(int);
    void Union(int,int);
    bool isConnected();
    bool isCyclic();
    
};
 
Graph::Graph(int Vert, int Edge)
{
    V = Vert;
    E = Edge;
    parent = (int*) malloc((V +1)* sizeof (int));
    memset(parent, -1, (V+1) * sizeof(int));
    edge = (struct Edge*) malloc(E * (sizeof (struct Edge))); 
    for(int i=0; i<Edge; i++)
    {
    	int s, d;
    	scanf("%d %d", &s, &d);
    	edge[i].src = s;
    	edge[i].dest = d;
    }
}
 
int Graph::find(int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}
 
void Graph::Union( int x, int y)
{
	int xset = find(x);
    int yset = find(y);
    parent[xset] = yset;
}

bool Graph::isCyclic()
{

    for(int i = 0; i < E; ++i)
    {
        int x = find(edge[i].src);
        int y = find(edge[i].dest);
 
        if (x == y)
            return true;
        Union(y,x);
    }
    return false;
}

bool Graph::isConnected()
{
	int connectedcounter = 0;
	for(int i = 1; i<= V; i++)
		if(parent[i] == -1) connectedcounter++;
	if(connectedcounter > 1)
		return false;
	return true;

}

void Graph::printparent()
{
	for(int i  = 1; i<= V; i++)
		printf("%d ", parent[i]);

}
 
int main()
{

	int vertices, edges;
	int src, dest;
	scanf("%d %d", &vertices, &edges);
    Graph graph(vertices, edges);
   	if(!graph.isCyclic() && graph.isConnected())
   		printf("YES\n");
   	else
   		printf("NO\n");
   	return 0; 
}