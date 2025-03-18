
#include "push_swap.h"

int	ft_s_r_rr(int *x, int len, int move, char *message)
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
	return (ft_putstr(message));
}

void	ft_prearange_b(int *a, int *b, int *len)
{
	int	i;
	int	big;

	i = 1;
	big = b[ft_small_big(b, len[1], 2)];
	while (big != b[0])
	{
		if (big == b[1])
			i *= ft_s_r_rr(b, len[1], 1, "sb\n");
		else if (big == b[len[1] - 1])
			i *= ft_s_r_rr(b, len[1], 3, "rrb\n");
		while (big != b[0] && big != b[1])
		{
			if (b[0] > b[1])
				i *= ft_s_r_rr(b, len[1], 1, "sb\n");
			if (big != b[0])
				i *= ft_s_r_rr(b, len[1], 2, "rb\n");
		}
	}
	if (i == 0)
		ft_double_error(a, b);
}

static int	*ft_push_b_back(int *a, int *b, int *len)
{
	int	i;
	int	x;

	i = 1;
	while (b && len[1] > 0)
	{
		if (len[1] <= 3)
			ft_two_three(a, b, len);
		else
			ft_prearange_b(a, b, len);
		if (a[0] < b[0] && a[1] < b[0])
		{
			x = ft_second_b(b, len[1]);
			while (a[0] < b[0] && a[0] < b[x])
				i *= ft_s_r_rr(a, len[0], 2, "ra\n");
		}
		len = ft_pa(a, b, len);
		if (a[0] > a[1])
			i *= ft_s_r_rr(a, len[0], 1, "sa\n");
	}
	while (len[1] == 0 && ft_check_a(a, len[0]) != len[0])
		i *= ft_s_r_rr(a, len[0], 3, "rra\n");
	if (i == 0)
		ft_double_error(a, b);
	return (len);
}

int	ft_choose_move(int *a, int *b, int *len)
{
	if (ft_check_a(a, len[0]) == len[0])
		return (len[0]);
	if (len[0] >= 2 && len[0] < 6 && len[1] == 0)
	{
		len = ft_short_sort(a, b, len);
		if (ft_check_a(a, len[0]) == len[0] && len[1] != 0)
			len = ft_push_b_back(a, b, len);
	}
	else if (len[0] >= 6 && len[1] == 0)
		len = ft_large_sort(a, b, len);
	return (len[0]);
}
