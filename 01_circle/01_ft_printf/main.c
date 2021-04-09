#include "ft_printf.h"

int main()
{
	char *a = NULL;
	char b = 'c';
	int x,y ;


	// printf s
	/*
	x = ft_printf("%5.3s\n", a);
	printf("%d\n", x);
	y = printf("%5.3s\n", a);
	printf("%d\n", y);
	x = ft_printf("%.3s\n", "hi my name");
	printf("%d\n", x);
	y = printf("%.3s\n", "hi my name");
	printf("%d\n", y);*/

	x = ft_printf("%d\n", 12);
	//printf("%d\n", x);
	//y = printf("%d\n", 12);
	//printf("%d\n", y);
	/*
	printf("=c------=\n");
	x = ft_printf("%123c\n", b);
	printf("%d\n", x);
	y = printf("%123c\n", b);
	printf("%d\n", y);*/
	/*
	printf("\n\n");
	printf("=p------=\n");
	x = ft_printf("%.p\n", &a);
	printf("%d\n", x);
	y = printf("%.p\n", &a);
	printf("%d\n", y);

	x = ft_printf("%1p\n", &a);
	printf("%d\n", x);
	y = printf("%1p\n", &a);
	printf("%d\n", y);
*/
	/*
	printf("%s\n", "hi my name is");
	printf("%5.s\n", "hi my name is");
	printf("%3.5s\n", "hi my name is");
*/
	printf("\n\n");
	return (0);
}
