#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

int			ft_atoi(const char *s)
{
	long long	ret;
	long long	tmp;
	int			of_cnt;

	ret = 0;
	of_cnt = 0;
	while (ft_isdigit(*s))
	{
		tmp = ret * 10 + (*s++ - '0');
		if ((((1 << 31) & tmp) ^ ((1 << 31) & ret)) == 0)
			of_cnt++;
		ret = tmp;
	}
	if (of_cnt >= 1 && ret >= 2147483647)
		return (-1);
	if (of_cnt >= 1 && ret < 0)
		return (0);
	return ((int)ret);
}

int main()
{
	//char* a;

	//a = "2147483647";
	char *a = "2147483646";
	printf("atoi : %d\n", ft_atoi(a));
	//int b = printf("%2147483646d", 1);
	//printf("%d", b);
}
