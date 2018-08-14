#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int Mayor(int n1, int n2, int n3);
int Mayor2(int n1, int n2, int n3);

int main(void) {
	int n1, n2, n3;
	int may = 0;

	printf("N1:\n");
	scanf("%d", &n1);

	printf("N2:\n");
	scanf("%d", &n2);

	printf("N3:\n");
	scanf("%d", &n3);

	may = Mayor(n1, n2, n3);

	printf("Mayor: %d\n", may);

	system("pause");
	return 0; // o return EXIT_SUCCESS o EXIT_FAILURE
}

int Mayor(int n1, int n2, int n3)
{
	int resp = -1;
	if (n1 > n2)
	{
		if (n1 > n3) {
			resp = n1;
		}
		else if (n1 != n3)
		{
			resp = n3;
		}
	}
	else
	{
		if (n3 > n2)
		{
			resp = n3;
		}
		else
		{
			if (n2 != n1) {
				if (n2 != n3)
				{
					resp = n2;
				}
			}
		}
	}
	return resp;
}

int Mayor2(int n1, int n2, int n3) {
	if (n1 > n2 && n1 > n3)
		return n1;

	if (n2 > n1 && n2 > n3)
		return n2;

	if (n3 > n1 && n3 > n2)
		return n3;

	return -1;
}
