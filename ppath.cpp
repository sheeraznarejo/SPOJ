#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <fstream>
using namespace std;

int primes[10050];
int dist[12000];
int dp[12000];

 void sieve()
{
    for(int i=2;i<=100;i++)
    {
        if(!primes[i])
        {
            for(int j=i*i;j<=10009;j+=i)
                primes[j] = true;
        }
    }
}


void numtoarray(int a[],int num)
{
    int w=3;
    while(num)
    {
        a[w--] = num%10;
        num/=10;
    }
}

int numberconverter(int a[])
{
    int temp=0,k=0;
    while(k<4){
        temp = temp*10 + a[k];
        k++;
    }
    return temp;
}



int bfs(int startnumber, int endnumber)
{
;
	dist[startnumber] = 0;
	int x = 0;
	queue<int> q; q.push(startnumber);
	while(!q.empty()) {
		int curr = q.front();
		int newnumber[4];
		
		dp[curr] = -1;	
		for(int i=0; i<= 3; i++)
			for(int j=0; j<=9; j++)
			{	
				
				numtoarray(newnumber, curr);
				newnumber[i] = j;
				int a = numberconverter(newnumber);
				if(!primes[a] && dp[a] != -1 && dist[a] == -1 && a>= 1000) {
					dist[a] = dist[curr] + 1;
					if(a == endnumber)
						return 0;
					q.push(a);
				}
			}
		q.pop();
	}
		
}  

int main()
{
	sieve();
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		memset(dist, -1,sizeof(dist));
		memset(dp, 0, sizeof(dp));
		bfs(a,b);
		(dist[b] == -1) ? printf("Impossible\n") : printf("%d\n", dist[b]);
	} 
	
}