#include <stdio.h>
int inputarray1[100010];
int inputarray2[100010];
int M1[100010];
int M2[100010];
int P1[100010];
int P2[100010];



int main()
{
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d %d", &inputarray1[i], &inputarray2[i]);
	}
	//for(int i=0; i<N; i++)
		//printf("%d %d ", inputarray1[i], inputarray2[i]);
	printf("\n");
	int L=0;
	for(int i=0; i<N; i++)
	{
		int lo=1;
		int hi=L;
		while(lo<=hi)
		{
			int mid = (lo+hi)/2;
			if((inputarray1[M1[mid]]<inputarray1[i]) && (inputarray2[M2[mid]]<inputarray2[i]))
				lo = mid+1;
			else
				hi = mid-1;	
		}
		int newl = lo;
		P1[i] = M1[newl-1];
		P2[i] = M2[newl-1];
		M1[newl] = i;
		M2[newl] = i;
		if(newl>L)
			L=newl;
	}
	printf("%d\n", L);
	return 0;
}