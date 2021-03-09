#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = printf("%s",NULL);
	printf("%d\n", a);
	a = printf("%6.3s", NULL);
	printf("%d\n", a);
	a = printf("%8s", NULL);
	printf("%d", a);
}
