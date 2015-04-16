#include <stdio.h>
#include <vector>
using std::vector;
vector<int> q;



int lis(vector<int> a)
{
	int n = a.size();
	for(int i=0; i<n; i++)
		q.push_back(0);
	for(int k=0; k<n; k++)
	{
		int maxi=0;
		int ho=0;
		for(int j=0; j<k;j++)
		{

			if(a[j]<a[k])
			{

				if(q[j]>maxi)
				{
					maxi = q[j];
			
				}
			}

		}
		q[k] = maxi+1;
	}
	int maxi = 0; int placeholder;
	for(int i=0; i<n; i++)
	{
		if(q[i]>maxi)
		{
			maxi = q[i];
			placeholder = i;
		}
	}
	int currentmaxsize = maxi-1;
	int currentmaxelement = a[placeholder];
	printf("%d ", currentmaxelement);
	for(int i=placeholder-1; i>=0; i--)
	{
		if(q[i]==currentmaxsize && a[i]<currentmaxelement )
		{
			printf("%d ", a[i]);
			currentmaxsize--;
			currentmaxelement = a[i];
		}
	}
	printf("\n");

	return maxi;


}

int main()
{
	int n, g;
	vector<int> v;
	scanf("%d", &n);
	int b;
	for(int i=0; i<n; i++)
	{
		scanf("%d", &b);
		v.push_back(b);

	}
	
	printf("%d\n", lis(v));
	return 0;

}
