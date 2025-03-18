
#include "push_swap.h"

int	ft_strncmp(char *line, char *checker)
{
	int	i;

	i = 0;
	while (line && line[i] != '\n')
	{
		if (line[i] == checker[i])
			i++;
		else
			return (1);
	}
	if (line[i] == '\n' && checker[i] != '\n')
		return (1);
	else
		return (0);
}

int	ft_scommand(int *buf_a, int *buf_b, char *line, int *buf_len)
{	
	if (ft_strncmp(line, "sa\n") == 0)
		ft_srrr_check(buf_a, buf_len[0], 1);
	else if (ft_strncmp(line, "sb\n") == 0)
		ft_srrr_check(buf_b, buf_len[1], 1);
	else if (ft_strncmp(line, "ss\n") == 0)
		ft_ssab_check(buf_a, buf_b, buf_len);
	else if (ft_strncmp(line, "ra\n") == 0)
		ft_srrr_check(buf_a, buf_len[0], 2);
	else if (ft_strncmp(line, "rb\n") == 0)
		ft_srrr_check(buf_b, buf_len[1], 2);
	else if (ft_strncmp(line, "rr\n") == 0)
		ft_rrab_check(buf_a, buf_b, buf_len);
	else if (ft_strncmp(line, "rra\n") == 0)
		ft_srrr_check(buf_a, buf_len[0], 3);
	else if (ft_strncmp(line, "rrb\n") == 0)
		ft_srrr_check(buf_b, buf_len[1], 3);
	else if (ft_strncmp(line, "rrr\n") == 0)
		ft_rrrab_check(buf_a, buf_b, buf_len);
	else
		return (0);
	return (1);
}
