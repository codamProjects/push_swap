
#include "push_swap.h"

void	ft_two_three(int *a, int *b, int *len)
{
	int	i;

	i = 1;
	if (a && len[0] > 1)
	{
		if (len[0] == 3 && a[0] < a[1] && a[1] > a[len[0] - 1])
			i *= ft_s_r_rr(a, len[0], 3, "rra\n");
		else if (len[0] >= 3 && a[0] > a[1] && a[0] > a[2])
			i *= ft_s_r_rr(a, len[0], 2, "ra\n");
		if (len[0] > 1 && a[0] > a[1])
			i *= ft_s_r_rr(a, len[0], 1, "sa\n");
	}
	if (b && len[1] > 1)
	{
		if (len[1] == 3 && b[0] > b[1] && b[1] < b[len[1] - 1])
			i *= ft_s_r_rr(b, len[1], 3, "rrb\n");
		else if (len[1] >= 3 && b[0] < b[1] && b[0] < b[2])
			i *= ft_s_r_rr(b, len[1], 2, "rb\n");
		if (len[1] > 1 && b[0] < b[1])
			i *= ft_s_r_rr(b, len[1], 1, "sb\n");
	}
	if (i == 0)
		ft_double_error(a, b);
}

void	ft_prearange_a(int *a, int *b, int *len, int h)
{
	int	i;
	int	l;

	i = 1;
	l = (len[0] - 1);
	if (a[l] < h && a[l] < a[0] && a[l] < a[1])
	{
		if (a[0] > a[1])
			i *= ft_s_r_rr(a, len[0], 1, "sa\n");
		i *= ft_s_r_rr(a, len[0], 3, "rra\n");
	}
	else if (a[1] < h && a[1] < a[0] && a[1] < a[l])
	{
		if (a[0] >= h && a[1] < h && (len[0] > 3 && a[2] < h && a[3] < h))
			i *= ft_s_r_rr(a, len[0], 2, "ra\n");
		else
			i *= ft_s_r_rr(a, len[0], 1, "sa\n");
	}
	if ((a[0] > a[1] && a[1] < h) || (a[0] > a[l] && a[l] < h))
		ft_prearange_a(a, b, len, h);
	if (i == 0)
		ft_double_error(a, b);
}

static void	ft_after_pb(int *a, int *b, int *len)
{
	int	i;

	i = 1;
	if (b && len[1] > 1)
	{
		if (len[1] > 2 && ft_small_big(b, len[1], 1) == 0)
			i *= ft_s_r_rr(b, len[1], 2, "rb\n");
		if (b[0] < b[1])
			i *= ft_s_r_rr(b, len[1], 1, "sb\n");
	}
	if (i == 0)
		ft_double_error(a, b);
}

int	*ft_four_five(int *a, int *b, int *len, int h)
{
	int	i;

	i = 1;
	while ((a[len[0] - 1] < h || a[0] < h || a[1] < h) && len[0] > 3)
	{
		if (ft_check_a(a, len[0]) == len[0])
			break ;
		if (a[0] > a[1] || a[0] > a[len[0] - 1])
			ft_prearange_a(a, b, len, h);
		if (a[0] < h && ft_check_a(a, len[0]) != len[0])
		{
			len = ft_pb(a, b, len);
			ft_after_pb(a, b, len);
		}
	}
	while (a[0] >= h && len[0] > 3 && ft_check_a(a, len[0]) != len[0])
	{
		if (a[0] > a[1] && a[1] >= h)
			i *= ft_s_r_rr(a, len[0], 1, "sa\n");
		i *= ft_s_r_rr(a, len[0], 2, "ra\n");
	}
	if (i == 0)
		ft_double_error(a, b);
	return (len);
}

int	*ft_short_sort(int *a, int *b, int *len)
{
	int	h;
	int	half;

	h = ft_half(a, len[0], 2);
	if (h == -1)
		ft_double_error(a, b);
	half = a[h];
	if (len[0] >= 4 && len[0] < 6)
	{
		while (len[0] > 3 && len[1] < 2)
		{
			len = ft_four_five(a, b, len, half);
			if (ft_check_a(a, len[0]) == len[0])
				break ;
		}
	}
	if (len[0] == 2 || len[0] == 3)
		ft_two_three(a, b, len);
	return (len);
}
