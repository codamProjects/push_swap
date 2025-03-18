
#include "push_swap.h"

int	*ft_free(int *x)
{
	if (x)
		free (x);
	return (NULL);
}

void	ft_double_error(int *a, int *b)
{
	b = ft_free(b);
	ft_error(a);
}

void	ft_succes_exit(int *a)
{
	a = ft_free(a);
	exit(0);
}

void	ft_error(int *a)
{
	a = ft_free(a);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (0);
		i++;
	}
	return (1);
}
