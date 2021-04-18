#include "ft_printf.h"
#include <fcntl.h>

int main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";


	//printf("---- return : %d\n", printf("%08.5d", 0));
	//printf("---- return : %d\n", ft_printf("%08.5d", 0));
	printf("---- return : %d\n", printf("%3.5p", (void*)20));
	printf("---- return : %d\n", ft_printf("%3.5p", (void*)20));
	//printf(" --- Return : %d\n", printf("%-*p", 8, (void *)1));
	//printf(" --- Return : %d\n", ft_printf("%-*p", 8, (void *)1));
/*
	printf(" --- Return : %d\n", printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", 11, (void *)209590960, 11, 209590960, 11, (void *)209590960, 11, 209590960, 11, (void *)209590960, 11, 209590960, 11, (void *)209590960, 11, 209590960));

	printf(" --- Return : %d\n", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", 11, (void *)209590960, 11, 209590960, 11, (void *)209590960, 11, 209590960, 11, (void *)209590960, 11, 209590960, 11, (void *)209590960, 11, 209590960));
		*/		/*
	printf(" --- Return : %d\n", printf("%0*.*u", 3, -1, i));
	printf(" --- Return : %d\n", ft_printf("%0*.*u",3, -1, i));
*/	/*
	printf(" --- Return : %d\n", printf("%x", j));
	printf(" --- Return : %d\n", ft_printf("%x", j));
	printf(" --- Return : %d\n", printf("%X", j));
	printf(" --- Return : %d\n", ft_printf("%X", j));
*/
	/*	
	printf(" ---- Return : %d\n", printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", -4, n, -4, o, -4, p, -4, q, -4, r, -4, s, -4, t, -4, u)); // 1st '*' = -4, 2nd '*' = 14

	printf(" ---- Return : %d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", -4, n, -4, o, -4, p,-4, q,-4, r,-4, s,-4, t,-4, u)); // 1st '*' = -4, 2nd '*' = 14

printf(" ---- Return : %d\n", printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", -4, n, -4, o, -4, p, -4, q, -4, r, -4, s, -4, t, -4, u)); // 1st '*' = -4, 2nd '*' = 14

	printf(" ---- Return : %d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", -4, n, -4, o, -4, p,-4, q,-4, r,-4, s,-4, t,-4, u)); // 1st '*' = -4, 2nd '*' = 14*/

	/*printf(" --- Return : %d\n", printf("%*.*ik\n", 1, 0, 0));  // 1st '*' = 1, 2nd '*' = 0

	printf(" --- Return : %d\n", ft_printf("%*.*ik\n", 1, 0, 0));  // 1st '*' = 1, 2nd '*' = 0*/
	//PRINT(" --- Return : %d\n", PRINT("Simple input test"));
	//PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	//printf(" --- Return : %d\n", printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d)); //T3
	//printf(" --- Return : %d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d)); //T3
	//printf(" --- Return : %d\n", printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d)); //T4  
	//printf(" --- Return : %d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d)); 
	//printf(" --- Return : %d\n", printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
	//printf(" --- Return : %d\n", ft_printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
/*{
	char *a = NULL;
	char b = 'c';
	int x,y ;
*/
/*
	int a, b;

	a = printf("%1d", 0);
	printf(" %d\n", a);
	a = ft_printf("%1d", 0);
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
*/
	//printf x
	//int a = d;
/*
	printf("--retrn : %d \n",printf("1 :%6x ", a));
	printf("--retrn : %d \n",ft_printf("1 :%6x ", a));
	printf("--retrn : %d \n",printf("1 :%6X ", a));
	printf("--retrn : %d \n",ft_printf("1 :%6X ", a));
*/
	//printf("--retrn : %d \n",printf("1 :%*.*u ", -1, -4,4282621618));
	//printf("--retrn : %d \n",printf("1 :%*.*u ", -1, -4, 4282621618));
	/*
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
	ft_printf("14 :%-4.3x\n\n", a);

	//printf X
	
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
