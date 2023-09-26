#include <stdio.h>
#include <math.h>
int main()
{
	float x, y;
	printf("---------------\n");
	printf("|  x   |   y  |\n");
	printf("---------------\n");
	for (x = 0; x <= 40; x += 2)
	{
		if (x < 20)
		{
			y = 0.3 * x + 1 / x;
		}
		else {
			y = sqrt(x * x + 3 * x) / 0.7;
		}
		printf("|%-6.0f|%6.3f|\n", x, y);
	}
	printf("---------------\n");
}
	


