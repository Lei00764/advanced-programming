/* 2053932 Èí¼ş À×Ïè */
#include <iostream>
using namespace std;


int main()
{
	int a[101] = {0}; 
	for (int i = 1; i < 101; i++)
	{
		for (int j = i; j < 101; j++)
		{
			if (j % i == 0)
			{
				if (a[j] == 1)
					a[j] = 0;
				else
					a[j] = 1;
			}
		}
	}

	for (int k = 1; k < 101; k++)
	{
		if (a[k] == 1)
			cout << k << " ";
	}
	cout << endl;

	return 0;
}