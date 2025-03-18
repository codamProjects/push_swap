
#include "push_swap.h"

void	ft_free_al(int *buf_a, int *buf_b, char *instructions, int i)
{
	buf_a = ft_free(buf_a);
	buf_b = ft_free(buf_b);
	if (instructions)
	{
		free (instructions);
		instructions = NULL;
	}
	exit (i);
}

static int	*ft_do_check(int *buf_a, int *buf_b, char *m, int *buf_len)
{
	int	i;
	int	k;

	i = 0;
	while (m && m[i])
	{
		k = i;
		while (m[i] != '\n' && m[i])
			i++;
		if (ft_strncmp(&m[k], "pa\n") == 0)
			buf_len = ft_pa_check(buf_a, buf_b, buf_len);
		else if (ft_strncmp(&m[k], "pb\n") == 0)
			buf_len = ft_pb_check(buf_a, buf_b, buf_len);
		else if (ft_scommand(buf_a, buf_b, &m[k], buf_len) == 0)
		{
			write(2, "Error\n", 6);
			ft_free_al(buf_a, buf_b, m, 1);
		}
		i++;
	}
	return (buf_len);
}	

void	ft_check_if_ok(int *buf_a, int *buf_b, char *instructions, int *buf_len)
{
	if (ft_check_a(buf_a, buf_len[0]) != buf_len[0])
		write(1, "KO\n", 3);
	else if (ft_check_b(buf_b, buf_len[1]) != buf_len[1] && buf_len[1] > 0)
		write(1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	ft_free_al(buf_a, buf_b, instructions, 0);
}

static char	*ft_create_line(char *instructions, char *str, int l)
{
	char	*buf;
	int		i;
	int		k;

	buf = (char *)malloc((l + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	while (instructions && instructions[i])
	{
		buf[i] = instructions[i];
		i++;
	}
	k = 0;
	while (i < l && str[k])
		buf[i++] = str[k++];
	buf[i] = '\0';
	if (instructions)
	{
		free (instructions);
		instructions = NULL;
	}
	return (buf);
}

void	ft_read(int *buf_a, int *buf_b, int *buf_len)
{
	static char	*instructions;
	char		str[10];
	int			l;
	int			rd;

	l = 0;
	rd = read(0, str, 10);
	while (rd > 0)
	{
		l += rd;
		instructions = ft_create_line(instructions, str, l);
		if (!instructions)
			ft_free_al(buf_a, buf_b, instructions, 1);
		rd = read(0, str, 10);
	}
	if (rd == -1)
		ft_free_al(buf_a, buf_b, instructions, 1);
	buf_len = ft_do_check(buf_a, buf_b, instructions, buf_len);
	ft_check_if_ok(buf_a, buf_b, instructions, buf_len);
}
