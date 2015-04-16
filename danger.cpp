#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[4]; 
	scanf("%s", s);
	while(strncmp(s, "00e0", 4) != 0)
	{
		int a = ((s[0] - '0')* 10 + (s[1] - '0'));
		int b = s[3] - '0';
		int z = 1; 
		while(b--)
			z = z*10;
		int josephus = a * z; 
		//printf("josephus is %d\n", josephus);

		if(josephus == 1 || josephus ==2 || josephus == 0) printf("1\n");
		else if(josephus == 3) printf("3\n");
		else
		{
			int n = 4;
			while(josephus > n*2 - 1 || josephus < n) n = n*2;
			int p = josephus - n;
			printf("%d\n", (p*2) + 1);
		}
		scanf("%s", s);
	}

	return 0;
}