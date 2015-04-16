#include <stdio.h>

bool countx(char a, char m[3][3])
{
	if(m[0][0] == a && m[0][1] == a && m[0][2] == a)
	{
		 return true;
	}
				
	if(m[1][0] == a && m[1][1] == a && m[1][2] == a)
	{
		return true;
	}				
	if(m[2][0] == a && m[2][1] == a && m[2][2] == a)
	{		 
		return true;
	}				
	if(m[0][0] == a && m[1][0] == a && m[2][0] == a)
	{	
		return true;
	}						
	if(m[0][1] == a && m[1][1] == a && m[2][1] == a)
	{	
		return true;
	}						
	if(m[0][2] == a && m[1][2] == a && m[2][2] == a)
	{
		return true;
	}						
	if(m[0][0] == a && m[1][1] == a && m[2][2] == a)
	{ 
		return true;
	}						
	if(m[0][2] == a && m[1][1] == a && m[2][0] == a)
	{
		return true;
	}

	return false;
}

int main()
{
	char dummy;
	int t; int n = 1;
	scanf("%d", &t);
	while(t--)
	{
		char m[3][3];
		int xtotal, ototal;
		xtotal = ototal = 0;
		for(int i =0; i<=2; i++)
			scanf("%s", m[i]);
		for(int i=0; i<=2; i++)
			for(int j=0; j<=2; j++)
			{
				if(m[i][j] == 'X')
					xtotal++;
				if(m[i][j] == 'O')
					ototal++;
			}
		
		if(ototal > xtotal)
			printf("no\n");
		
		 else if(xtotal == ototal)
		{
			
			if (countx('X', m) == true)
				printf("no\n");
			else
				printf("yes\n")	;	

		}

		 else if (xtotal == ototal+1)
		{
			if (countx('O', m) == true)
			{
				printf("no\n");
			}
			else
				printf("yes\n")	;				
		}
		 else if (xtotal > ototal+1) 
		{
			printf("no\n");
		}

		else
		{
			printf("yes\n");
		}

	}
}


