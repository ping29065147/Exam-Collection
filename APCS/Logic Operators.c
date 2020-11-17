#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, result;
	
	while(1){
		scanf("%d %d %d", &a, &b, &result);
	
		if (a == 0 && b == 0 && result == 0)
			printf("AND\nOR\nXOR\n");
		else if (a == 0 && b == 0 && result != 0)
			printf("IMPOSSIBLE\n");
		else if (a != 0 && b != 0 && result != 0)
			printf("AND\nOR\n");
		else if (a != 0 && b != 0 && result == 0)
			printf("XOR\n");
		else if (a != 0 && b == 0 && result != 0)
			printf("OR\nXOR\n");
		else if (a != 0 && b == 0 && result == 0)
			printf("AND\n");
		else if (a == 0 && b != 0 && result != 0)
			printf("OR\nXOR\n");
		else if (a == 0 && b != 0 && result == 0)
			printf("AND\n");

	}
		
	return 0;
}

