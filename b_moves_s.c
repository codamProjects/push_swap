
#include "push_swap.h"

void	ft_srrr_check(int *x, int len, int move)
{
	int	buf;
	int	i;

	i = -1;
	if (move == 1)
	{
		buf = x[0];
		x[0] = x[1];
		x[1] = buf;
	}
	else if (move == 2)
	{
		buf = x[i + 1];
		while (++i < len - 1)
			x[i] = x[i + 1];
		x[i] = buf;
	}
	else if (move == 3)
	{
		buf = x[len - 1];
		while (++i < len - 1)
			x[len - 1 - i] = x[len - 2 - i];
		x[len - 1 - i] = buf;
	}
}

void	ft_ssab_check(int *a, int *b, int *len)
{
	int	bufb;
	int	bufa;

	if (len[0] < 2 && len[1] > 1)
		ft_srrr_check(b, len[1], 1);
	else if (len[0] > 1 && len[1] < 2)
		ft_srrr_check(a, len[0], 1);
	else if (len[0] > 1 && len[1] > 1)
	{
		bufa = a[0];
		bufb = b[0];
		a[0] = a[1];
		b[0] = b[1];
		a[1] = bufa;
		b[1] = bufb;
	}
}

void	ft_rrab_check(int *a, int *b, int *len)
{
	int	buf;
	int	i;

	if (len[0] < 2 && len[1] > 1)
		ft_srrr_check(b, len[1], 2);
	else if (len[0] > 1 && len[1] < 2)
		ft_srrr_check(a, len[0], 2);
	else if (len[0] > 1 && len[1] > 1)
	{
		i = -1;
		buf = a[i + 1];
		while (++i < len[0] - 1)
			a[i] = a[i + 1];
		a[i] = buf;
		i = -1;
		buf = b[i + 1];
		while (++i < len[1] - 1)
			b[i] = b[i + 1];
		b[i] = buf;
	}
}

void	ft_rrrab_check(int *a, int *b, int *len)
{
	int	buf;
	int	i;

	if (len[0] < 2 && len[1] > 1)
		ft_srrr_check(b, len[1], 3);
	else if (len[0] > 1 && len[1] < 2)
		ft_srrr_check(a, len[0], 3);
	else if (len[0] > 1 && len[1] > 1)
	{
		i = -1;
		buf = a[len[0] - 1];
		while (++i < len[0] - 1)
			a[len[0] - 1 - i] = a[len[0] - 2 - i];
		a[len[0] - 1 - i] = buf;
		i = -1;
		buf = b[len[1] - 1];
		while (++i < len[1] - 1)
			b[len[1] - 1 - i] = b[len[1] - 2 - i];
		b[len[1] - 1 - i] = buf;
	}
}
