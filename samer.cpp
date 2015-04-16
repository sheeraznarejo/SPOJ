/* SPOJ SAMERO*C. Dynamic Programming Problem. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valuesarray[100010];
int rowsmaximum[100010];
int rowsmaximum2[100010];
int cm[100010];

int max(int a, int b)
{
	return (a>b) ? a : b;
}


int main()
{
	int rows, columns;
	scanf("%d %d", &rows, &columns);

	while(rows && columns)		
	{
		for(int i = rows-1; i>=0; i--)
		{
			for(int j=0; j<= columns-1; j++)
				scanf("%d", &valuesarray[j]);
			rowsmaximum[columns] = 0;
			rowsmaximum[columns+1] = 0;
			for(int j = columns-1;j>= 0; j--)
				rowsmaximum[j] = max(valuesarray[j] + rowsmaximum[j+2], rowsmaximum[j+1]);
			rowsmaximum2[i] = rowsmaximum[0] ; 

		}

		cm[rows] = 0;
		cm[rows+1] = 0;
		for(int j = rows-1; j>=0; j--)
		{	
			cm[j] = max(rowsmaximum2[j] + cm[j+2], cm[j+1]);
			
		}
		printf("%d\n", cm[0]);
		scanf("%d%d", &rows, &columns); 

	}
	return 0;
}