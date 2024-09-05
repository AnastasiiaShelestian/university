#include <iostream>
using namespace std;


int main()
{
	int n, i, count, sum;
	int a[25];

	cout << "Enter the number of elements in the array" << endl;
	cin >> n;

	// Ввод количества элементов массива
	if (n > 25 || n <= 0)
	{
		cout << "Error n must be 0 < n <= 25";
		return -1;
	}

	cout << "Enter the elemets" << endl;

	// Ввод элементов массива 
	for (i = 0; i < n; i++)
	{
		cout << "Enter the number on index " << i << ": ";
		cin >> a[i];
		if (a[i] == 0)
		{
			cout << "Error a[i] must be > 0";
			return -1;
		}
	}

	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	count = 0;
	
	// Пункт а
	for (i = 0; i < n-1; i++)
	{
		if (a[i] * a[i + 1] < 0 )
		{
			count++;
		}
	}
	cout << "Summ of sign change " << count << endl;
	
	sum = 0;
	count = 0;
	
	// Пункт б
	for (i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			sum += a[i];
			count++;
		}
	}

	cout << "Average of positive numbers = " << (double)sum / count;
}
