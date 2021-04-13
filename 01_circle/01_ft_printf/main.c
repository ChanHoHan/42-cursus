#include "ft_printf.h"

int main()
{
/*{
	char *a = NULL;
	char b = 'c';
	int x,y ;
*/

	int a, b;

	a = printf("%0*i", -4, 8);
	printf(" %d\n", a);
	a = ft_printf("%0*i", -4, 8);
	printf(" %d\n", a);

	printf("\n");
	a = printf("%.0d", -12);
	printf(" %d\n", a);
	a = ft_printf("%.0d", -12);
	printf(" %d\n", a);

	printf("\n");
	a = printf("%.0d", 123456789);
	printf(" %d\n", a);
	a = ft_printf("%.0d", 123456789);
	printf(" %d\n", a);

	printf("\n");
	a = printf("%.0d", 0);
	printf(" %d\n", a);
	a = ft_printf("%.0d", 0);
	printf(" %d\n", a);


	printf("\n");
	a = printf("%.0d", -12345678);
	printf(" %d\n", a);
	a = ft_printf("%.0d", -12345678);
	printf(" %d\n", a);

	printf("\n");

	a = printf("%.0d", 97);
	printf(" %d\n", a);
	a = ft_printf("%.0d", 97);
	printf(" %d\n", a);

	printf("\n");

	a = printf("%.0d", -2147483648);
	printf(" %d\n", a);
	a = ft_printf("%.0d", -2147483648);
	printf(" %d\n", a);

	printf("\n");

	a = printf("%.0d", 2147483647);
	printf(" %d\n", a);
	a = ft_printf("%.0d", 2147483647);
	printf(" %d\n", a);

	printf("\n");

	//printf x
	//unsigned int a = 30;
	/*
	printf("1 :%4x\n", a);
	ft_printf("1 :%4x\n", a);
	printf("1 :%3.4x\n", a);
	ft_printf("1 :%3.4x\n", a);
	printf("2 :%5.x\n", a);
	ft_printf("2 :%5.x\n", a);
	printf("3 :%3.4x\n", a);
	ft_printf("3 :%3.4x\n", a);
	printf("4 :%04.x\n", a);
	ft_printf("4 :%04.x\n", a);
	printf("5 :%03.3x\n", a);
	ft_printf("5 :%03.3x\n", a);
	printf("6 :%-4x\n",a);
	ft_printf("6 :%-4x\n",a);
	printf("7 :%4.x\n", a);
	ft_printf("7 :%4.x\n", a);
	printf("8 :%4.x\n", a);
	ft_printf("8 :%4.x\n", a);
	printf("9 :%04x\n", a);
	ft_printf("9 :%04x\n", a);
	printf("10 :%1x\n", a);
	ft_printf("10 :%1x\n", a);
	printf("11 :%.1x\n", a);
	ft_printf("11 :%.1x\n", a);
	printf("12 :%2.2x\n", a);
	ft_printf("12 :%2.2x\n", a);
	printf("13 :%4.3x\n", a);
	ft_printf("13 :%4.3x\n", a);
	printf("14 :%-4.3x\n", a);
	ft_printf("14 :%-4.3x\n", a);
*/

	//printf X
/*
	printf("1 :%4X\n", a);
	ft_printf("1 :%4X\n", a);
	printf("1 :%3.4X\n", a);
	ft_printf("1 :%3.4X\n", a);
	printf("2 :%5.X\n", a);
	ft_printf("2 :%5.X\n", a);
	printf("3 :%3.4X\n", a);
	ft_printf("3 :%3.4X\n", a);
	printf("4 :%04.X\n", a);
	ft_printf("4 :%04.X\n", a);
	printf("5 :%03.3X\n", a);
	ft_printf("5 :%03.3X\n", a);
	printf("6 :%-4X\n",a);
	ft_printf("6 :%-4X\n",a);
	printf("7 :%4.X\n", a);
	ft_printf("7 :%4.X\n", a);
	printf("8 :%4.X\n", a);
	ft_printf("8 :%4.X\n", a);
	printf("9 :%04X\n", a);
	ft_printf("9 :%04X\n", a);
	printf("10 :%1X\n", a);
	ft_printf("10 :%1X\n", a);
	printf("11 :%.1X\n", a);
	ft_printf("11 :%.1X\n", a);
	printf("12 :%2.2X\n", a);
	ft_printf("12 :%2.2X\n", a);
	printf("13 :%4.3X\n", a);
	ft_printf("13 :%4.3X\n", a);
	printf("14 :%-4.3X\n", a);
	ft_printf("14 :%-4.3X\n", a);
*/
	//printf u
/*
	unsigned int a = 30;
	
	printf("1 :%4u\n", a);
	ft_printf("1 :%4u\n", a);
	printf("1 :%3.4u\n", a);
	ft_printf("1 :%3.4u\n", a);
	printf("2 :%5.u\n", a);
	ft_printf("2 :%5.u\n", a);
	printf("3 :%3.4u\n", a);
	ft_printf("3 :%3.4u\n", a);
	printf("4 :%04.u\n", a);
	ft_printf("4 :%04.u\n", a);
	printf("5 :%03.3u\n", a);
	ft_printf("5 :%03.3u\n", a);
	printf("6 :%-4u\n",a);
	ft_printf("6 :%-4u\n",a);
	printf("7 :%4.u\n", a);
	ft_printf("7 :%4.u\n", a);
	printf("8 :%4.u\n", a);
	ft_printf("8 :%4.u\n", a);
	printf("9 :%04u\n", a);
	ft_printf("9 :%04u\n", a);
	printf("10 :%1u\n", a);
	ft_printf("10 :%1u\n", a);
	printf("11 :%.1u\n", a);
	ft_printf("11 :%.1u\n", a);
	printf("12 :%2.2u\n", a);
	ft_printf("12 :%2.2u\n", a);
	printf("13 :%4.3u\n", a);
	ft_printf("13 :%4.3u\n", a);
	printf("14 :%-4.3u\n", a);
	ft_printf("14 :%-4.3u\n", a);
	printf("15 : %u %u %u\n", 0, 2147483647, 42);
	ft_printf("15 : %u %u %u\n", 0, 2147483647, 42);*/
	// printf d
/*
	int a = 0;
	printf("1 :%4d\n", a);
	ft_printf("1 :%4d\n", a);
	printf("1 :%3.4d\n", a);
	ft_printf("1 :%3.4d\n", a);
	printf("2 :%5.d\n", a);
	ft_printf("2 :%5.d\n", a);
	printf("3 :%3.4d\n", a);
	ft_printf("3 :%3.4d\n", a);
	printf("4 :%04.d\n", a);
	ft_printf("4 :%04.d\n", a);
	printf("5 :%03.3d\n", a);
	ft_printf("5 :%03.3d\n", a);
	printf("6 :%-4d\n",a);
	ft_printf("6 :%-4d\n",a);
	printf("7 :%4.d\n", a);
	ft_printf("7 :%4.d\n", a);
	printf("8 :%4.d\n", a);
	ft_printf("8 :%4.d\n", a);
	printf("9 :%04d\n", a);
	ft_printf("9 :%04d\n", a);
	printf("10 :%1d\n", a);
	ft_printf("10 :%1d\n", a);
	printf("11 :%.1d\n", a);
	ft_printf("11 :%.1d\n", a);
	printf("12 :%2.2d\n", a);
	ft_printf("12 :%2.2d\n", a);
	printf("13 :%4.3d\n", a);
	ft_printf("13 :%4.3d\n", a);
	printf("14 :%-4.3d\n", a);
	ft_printf("14 :%-4.3d\n", a);
	printf("15 : %ld %d %d %d\n", -2147483648, 0, 2147483647, 42);
	ft_printf("15 : %d %d %d %d\n", -2147483648, 0, 2147483647, 42);
*/
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

	/*
	x = ft_printf("%-4.3d\n", -30);
	printf("%d\n", x);
	y = printf("%-4.3d\n", -30);
	printf("%d\n", y);*/
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
	return (0);
}
