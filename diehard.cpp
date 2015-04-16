

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int array1[1000][1000];
int array2[1000][1000];
int array3[1000][1000];

int main ()
{
	int recursivecalculator(int a, int b, int c);
	int i,j;

	int maxfinder(int ,int); 
	int health, armor;
	int testcases;
	for(i = 0; i< 1000; i++)
		for(j = 0; j < 1000; j++)
		{
			array1[i][j] = -1;
			array2[i][j] = -1;
			array3[i][j] = -1;
		}
	cin >> testcases;
	while (testcases > 0)
	{
		cin >> health;
		cin >> armor;

		cout << recursivecalculator(1, health, armor) << endl ;
		testcases--;

	}
}



int recursivecalculator(int mode, int health, int armor)
{
	int maxfinder(int a, int b);
	int value;
	if (mode == 1)
	{
		if(array1[health][armor] != -1)
			return array1[health][armor];

		health += 3;
		armor += 2;

		if (health > 0 && armor > 0)
		{
			value =  1 + maxfinder(recursivecalculator(2,health, armor ),recursivecalculator(3,health, armor)) ;
			array1[health - 3][armor -2] = value;
			return value;
		}

		else
			return 0;
	}

	else if (mode == 2)
	{
		if (array2[health][armor] != -1)
			return array2[health][armor];

		health -= 5;
		armor -= 10;


		if (health > 0 && armor > 0)
		{
			value  =  1 + recursivecalculator(1,health , armor ); //,recursivecalculator(3,health, armor)) ;
			array2[health + 5][armor + 10] = value;
			return value;
		}

		else
			return 0;
	}

	else // mode = 3
	{
		if (array3[health][armor] != -1)
			return array3[health][armor] ;

		health -= 20;
		armor += 5;

		if (health > 0 && armor > 0)
		{
			value =  1 + recursivecalculator(1,health, armor); //,recursivecalculator(1,health, armor )) ;
			array3[health+20][armor -5] = value;
			return value;
		}

		else
			return 0;

	}


}


int maxfinder(int a, int b)
{
	if ( a >= b)
		return a;
	else
		return b;

}