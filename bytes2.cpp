#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int timesarray[10000008];


int main()
{
	int n;
	int k, j;
	k = 5; j = 200;
	scanf("%d", &n); 
	while(n--)
	{

		int arraysize, entry, exit2;
		int maxexit = 0;
		scanf("%d", &arraysize);
		int p = arraysize;
		while(p--)
		{
			scanf("%d %d", &entry, &exit2); 
			if(exit2 > maxexit) maxexit = exit2;
			timesarray[entry] = k;
			timesarray[exit2] = j;
		}
		int sum = 0;
		int maxsum = 0;
		for(int i=0; i<= maxexit; i++)
		{
			if(timesarray[i] == k)
			{ 
				sum++;
				if(sum > maxsum)
					maxsum = sum;
			}
			else if (timesarray[i] == j)
				sum--;	
		}
		printf("%d\n", maxsum);
		k++;
		j++;

	}
}