#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int dp[1001] = {-1};


int main()
{
	unsigned int recursivecalculator(unsigned int);
	int i;
	for(i = 0; i <= 11; i++)
		dp[i] = i;
	i = 12;
	for(; i <= 1000; i++)
		dp[i] = -1;

	unsigned int value;
	while( cin >> value) 
	{
		cout << recursivecalculator(value) << endl; 
	}

}


unsigned int recursivecalculator(unsigned int a) 
{
	unsigned int value;
	unsigned int maxfinder(unsigned int, unsigned int);
	if (a >= 0 && a <= 1000) 
	{
		if (dp[a]!= -1)
			return dp[a];
		else
		{
			value = maxfinder(a, recursivecalculator(a/2) + recursivecalculator(a/3) + recursivecalculator(a/4));
			dp[a] = value;
			return dp[a];
		}
	}
		
	else 
	{
		value = recursivecalculator(a/2) + recursivecalculator(a/4) + recursivecalculator(a/3);
		return value;
	}
}



unsigned int maxfinder(unsigned int a, unsigned int b)
{
	if (a >= b)
		return a;
	else 
		return b;

}


