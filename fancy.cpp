#include <iostream>
#include <string>
#include <sstream>


using std::cout;
using std::endl;
using std::cin;
using std::string;
string array1;
long numberofcases;




int main()
{
	int power(int, int);
	cin >> numberofcases;
	int i = 0;
	while(i < numberofcases)
	{

		cin >> array1;
		
		int m = 0;
		int p = 1;
		long long returnvalue = 1;
		for(; m <= array1.length() -2 ; m++)
		{
			if(array1.length() == 1)
				break;
			if (array1[m] == array1[m+1])
			{
				p++;
			}

			else
			{
				returnvalue  = returnvalue * power(2,p-1);
				p = 1;
			}

			if(m == array1.length() - 2 && p >1)
				returnvalue = returnvalue * power(2,p-1);

		}
		cout << returnvalue << endl;
		i++;

	}
}

int power(int n, int k)
{
	int value = 1;
	if (k == 0)
		return 1;
	int i = 0;
	for(; i <k; i++)
	{
		value = value * n;
	}

	return value;
}