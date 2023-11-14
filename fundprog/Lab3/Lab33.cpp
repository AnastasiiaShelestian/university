#include <iostream> 
using namespace std; 

int main() 
{ 
	int i, i1; 
	int j = 0; 
	int start = 0; 
	char a[256]; 
	char b[256]; 

	cout << "enter word" << endl; 
	cin.getline(a, 256); 

	cout << "Initial string: " << a << endl; 

	for (i = 0; a[i-1] != '\0'; i++) 
	{  
		if (((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122)))
		{ 
			if (i > 0 && !((a[i-1] >= 65 && a[i-1] <= 90) || (a[i-1] >= 97 && a[i-1] <= 122)))
			{ 
				start = i; 
			}
		}
		else { 
			if (i > 0 && ((a[i-1] >= 65 && a[i-1] <= 90) || (a[i-1] >= 97 && a[i-1] <= 122)))
			{ 
				if (i - start <= 6) 
				{ 
					for (i1 = start; i1 < i; i1++) 
					{
						b[j] = a[i1];
						j++;
					}
				}
			}
			b[j] = a[i];
			j++;
		}
	}
	cout << "Modified string: " << b;
}