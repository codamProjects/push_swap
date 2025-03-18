
#include "push_swap.h"

static int	*ft_turn_down_a(int *a, int *b, int *len, int h)
{
	int	i;
	int	high;
	int	s_high;

	high = b[h];
	s_high = b[ft_second_b(b, len[1])];
	i = 1;
	while (high != b[0] && len[1] > 1 && h > (len[1] / 2))
	{
		if (b[0] == s_high && a[0] > high)
			len = ft_pa(a, b, len);
		if (b[0] != high)
			i *= ft_s_r_rr(b, len[1], 3, "rrb\n");
	}
	if (i == 0)
		ft_double_error(a, b);
	return (len);
}

static int	*ft_turn_up_a(int *a, int *b, int *len, int h)
{
	int	i;
	int	high;
	int	s_high;

	high = b[h];
	s_high = b[ft_second_b(b, len[1])];
	i = 1;
	while (high != b[0] && len[1] > 1 && h <= (len[1] / 2))
	{
		if (b[0] == s_high && a[0] > high)
			len = ft_pa(a, b, len);
		if (high == b[1] && b[0] != high)
			i *= ft_s_r_rr(b, len[1], 1, "sb\n");
		else if (b[0] != high)
			i *= ft_s_r_rr(b, len[1], 2, "rb\n");
	}
	if (i == 0)
		ft_double_error(a, b);
	return (len);
}

static int	*ft_high_to_a(int *a, int *b, int *len)
{
	int	i;
	int	h;
	int	high;

	i = 1;
	while (b && len[1] > 0)
	{
		h = ft_small_big(b, len[1], 2);
		high = b[h];
		if (h <= (len[1] / 2))
			len = ft_turn_up_a(a, b, len, h);
		else if (h > (len[1] / 2))
			len = ft_turn_down_a(a, b, len, h);
		if (high == b[0])
		{
			len = ft_pa(a, b, len);
			if (a[0] > a[1])
				i *= ft_s_r_rr(a, len[0], 1, "sa\n");
		}
	}
	if (i == 0)
		ft_double_error(a, b);
	return (len);
}

static int	*ft_low_to_b(int *a, int *b, int *len, int h)
{
	int	i;
	int	low;

	i = 1;
	low = a[ft_small_big(a, len[0], 1)];
	while (len[0] > 1 && a[len[0] - 1] <= h)
		i *= ft_s_r_rr(a, len[0], 3, "rra\n");
	while (low <= h)
	{
		while (a[0] <= h || a[1] <= h)
		{
			if (a[1] <= h && a[0] > a[1])
				i *= ft_s_r_rr(a, len[0], 1, "sa\n");
			len = ft_pb(a, b, len);
			if (len[1] > 1 && ft_small_big(b, len[1], 1) == 0)
				i *= ft_s_r_rr(b, len[1], 2, "rb\n");
		}
		low = a[ft_small_big(a, len[0], 1)];
		while (a[0] > h && low <= h)
			i *= ft_s_r_rr(a, len[0], 2, "ra\n");
	}
	if (i == 0)
		ft_double_error(a, b);
	return (len);
}

int	*ft_large_sort(int *a, int *b, int *len)
{
	int	h;
	int	p;

	while (ft_check_a(a, len[0]) != len[0] && len[0] > 3)
	{
		if ((len[0] + len[1]) < 10)
			p = 2;
		else if (len[0] <= 50)
			p = 3;
		else if (len[0] <= 100)
			p = 4;
		else if (len[0] <= 200)
			p = 5;
		else
			p = 7;
		h = ft_half(a, len[0], p);
		if (h == -1)
			ft_double_error(a, b);
		len = ft_low_to_b(a, b, len, a[h]);
	}
	if (len[0] <= 3 && ft_check_a(a, len[0]) != len[0])
		ft_two_three(a, b, len);
	len = ft_high_to_a(a, b, len);
	return (len);
}
