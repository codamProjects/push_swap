
#include "push_swap.h"

static int	ft_len_of_one_arg(char *argv[])
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != 32 && (argv[1][i + 1] == 32 || !argv[1][i + 1]))
			len++;
		i++;
	}
	if (len == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (len);
}

static int	*ft_num_to_atoi(int *a, char *str, int i, int len)
{
	int	k;
	int	j;

	j = -1;
	while (++j < len)
	{
		while (str[i] == 32 && str[i + 1] == 32)
			i++;
		if (str[i] == 32)
			i++;
		k = i;
		while (str[i])
		{
			if (str[i] != 32 && (str[i + 1] == 32 || !str[i + 1]))
			{
				str[++i] = '\0';
				a[j] = ft_atoi(&str[k], (j + 1), a);
				break ;
			}
			i++;
		}
		i++;
	}
	a[j] = '\0';
	return (a);
}

static int	*ft_one_to_multiple(char *argv[], int len, int *a)
{
	char	*str;

	str = argv[1];
	if (!str || (!str[0] && str[0] != 48))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	a = (int *)malloc((len + 1) * sizeof(int));
	if (!a)
		ft_error(a);
	a = ft_num_to_atoi(a, str, 0, len);
	return (a);
}

static int	*ft_check_make(char *stack[], int len, int *a)
{
	int	i;

	i = 1;
	a = (int *)malloc((len + 1) * sizeof(int));
	if (!a)
		ft_error(a);
	while (i <= len)
	{
		if (!stack[i] || (!stack[i][0] && stack[i][0] != 48))
			ft_error(a);
		a[i - 1] = ft_atoi(stack[i], i, a);
		i++;
	}
	a[i - 1] = '\0';
	return (a);
}

int	main(int argc, char *argv[])
{
	static int	*a;
	static int	*b;
	int			len[2];

	if (argc < 1)
		exit(1);
	len[0] = argc - 1;
	len[1] = 0;
	if (argc == 1)
		ft_succes_exit(a);
	if (argc == 2)
	{
		len[0] = ft_len_of_one_arg(argv);
		a = ft_one_to_multiple(argv, len[0], a);
	}
	else
		a = ft_check_make(argv, len[0], a);
	b = ft_b_zero(b, len[0]);
	if (!a || !b)
		ft_double_error(a, b);
	if (ft_choose_move(a, b, len) != len[0])
		ft_double_error(a, b);
	b = ft_free(b);
	a = ft_free(a);
	return (0);
}
