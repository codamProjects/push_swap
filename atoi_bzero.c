
#include "push_swap.h"

int	*ft_b_zero(int *x, int len)
{
	int	i;

	i = 0;
	x = (int *)malloc((len + 1) * sizeof(int));
	if (!x)
		return (NULL);
	while (i <= len)
		x[i++] = '\0';
	return (x);
}

int	ft_atoi(char *str, int size, int *a)
{
	ssize_t	buff;
	int		i;

	i = 0;
	buff = 0;
	while (str[i])
	{
		if (str[i] == 45 && i == 0)
			i++;
		if (str[i] < 48 || str[i] > 57 || buff > 2147483648)
			ft_error(a);
		buff = buff * 10 + (str[i] - 48);
		i++;
	}
	if (str[0] == 45)
		buff = -buff;
	if (buff > 2147483647 || buff < -2147483648)
		ft_error(a);
	i = -1;
	while (++i < size - 1 && size > 1)
	{
		if (a[i] == (int)buff)
			ft_error(a);
	}
	return ((int)buff);
}
