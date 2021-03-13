#include "ft_printf.h"

int main()
{
	int a = 10;

	ft_printf("%p\n", &a);
	printf("%p", &a);
	return (0);
}
