
#include "push_swap.h"

int	ft_small_big(int *x, int len, int sb)
{
	int	i;
	int	a;

	i = 0;
	a = i;
	if (sb == 1)
	{
		while (x && i < len)
		{
			if (x[i] < x[a])
				a = i;
			i++;
		}
	}
	else if (sb == 2)
	{
		while (x && i < len)
		{
			if (x[i] > x[a])
				a = i;
			i++;
		}
	}
	return (a);
}

int	ft_second_b(int *b, int len)
{
	int	i;
	int	a;
	int	big;

	i = 0;
	big = ft_small_big(b, len, 2);
	if (len > 1 && b[big] == b[i])
		i++;
	a = i;
	while (b && i < len)
	{
		if (b[i] < b[big] && b[i] > b[a])
			a = i;
		i++;
	}
	return (a);
}

int	ft_check_b(int *x, int len)
{
	int	start;

	start = (len - 1);
	if (x)
	{
		while (--start > 0)
		{
			if (x[start] < x[start + 1])
				return (start);
		}
	}
	return (start);
}

int	ft_check_a(int *x, int len)
{
	int	start;

	start = 0;
	if (x)
	{
		while (++start < len)
		{
			if (x[start - 1] > x[start])
				return (start - 1);
		}
	}
	return (start);
}

int	ft_half(int	*x, int len, int p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if ((len % p) == 0)
		p = ((len / p) - 1);
	else
		p = (len / p);
	while (x && i < len)
	{
		j = 0;
		k = 0;
		while (j < len)
		{
			if (x[i] > x[j])
				k++;
			j++;
		}
		if (k == p)
			return (i);
		i++;
	}
	return (-1);
}
