
#include "push_swap.h"

int	*ft_pb_check(int *a, int *b, int *len)
{
	int	i;

	if (len[0] < 1)
		return (len);
	len[0] -= 1;
	len[1] += 1;
	i = 0;
	while (++i < len[1] && b)
		b[len[1] - i] = b[len[1] - 1 - i];
	b[len[1] - i] = a[0];
	i = -1;
	while (++i < (len[0]) && a)
		a[i] = a[i + 1];
	a[i] = '\0';
	return (len);
}

int	*ft_pa_check(int *a, int *b, int *len)
{
	int	i;

	if (len[1] < 1)
		return (len);
	len[0] += 1;
	len[1] -= 1;
	i = 0;
	while (++i < len[0] && a)
		a[len[0] - i] = a[len[0] - 1 - i];
	a[len[0] - i] = b[0];
	i = -1;
	while (++i < (len[1]) && b)
		b[i] = b[i + 1];
	b[i] = '\0';
	return (len);
}
