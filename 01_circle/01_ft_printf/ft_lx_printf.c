#include "ft_printf.h"

int	X_num_len(unsigned int *num, t_point *pt)
{
	int		len;
	int		_num;

	len = 0;
	_num = *num;
	if (*num < 0)
	{
		pt->sign = 1;
		*num = -(*num);
	}
	while (_num)
	{
		_num = _num / 10;
		len++;
	}
	return (len);
}

void	X_putnbr_printf(long long num)
{
	long long	quo;
	long long	rem;
	char		ch;

	quo = num / 16;
	rem = num % 16;
	if (quo > 16)
		X_putnbr_printf(quo);
	else
	{
		ch = '0' + quo;
		write(1, &ch, 1);
	}
	write(1, &LARGE[rem], 1);
}

void	X_padding_operation(t_point *pt)
{
	if (pt->sign)
		write (1, "-", 1);
	if (pt->padding > 0)
		printf_zs('0', pt->padding);
}

void	X_width_operation(t_point *pt, int *len)
{
	if (pt->width - *len <= 0)
		return ;
	printf_zs(' ', pt->width - *len);
	*len = pt->width;
}

int	X_printf(t_point *pt, unsigned int num)
{
	int	len;

	len = X_num_len(&num, pt);
	if (pt->pre > len)
		pt->padding = pt->pre - len;//숫자 앞에 zero padding
	if (pt->zero && pt->width - len > pt->padding)
		pt->padding = pt->width - len;
	len += pt->padding;
	if (pt->minus)
	{
		X_padding_operation(pt);
		X_putnbr_printf(num);
		X_width_operation(pt, &len);
	}
	else
	{
		X_width_operation(pt, &len);
		X_padding_operation(pt);
		X_putnbr_printf(num);
	}
	return (len + pt->padding);//수정
}
