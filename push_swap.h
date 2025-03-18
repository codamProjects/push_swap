
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

int		main(int argc, char *argv[]);
int		ft_check_a(int *x, int len);
int		ft_check_b(int *x, int len);
int		ft_small_big(int *x, int len, int sb);
int		ft_second_b(int *b, int len);
int		ft_half(int *x, int len, int p);
int		*ft_b_zero(int *x, int len);
int		ft_atoi(char *str, int size, int *a);
int		ft_choose_move(int *a, int *b, int *len);
int		*ft_short_sort(int *a, int *b, int *len);
int		*ft_large_sort(int *a, int *b, int *len);
void	ft_two_three(int *a, int *b, int *len);
int		*ft_four_five(int *a, int *b, int *len, int h);
void	ft_prearange_a(int *a, int *b, int *len, int h);
void	ft_prearange_b(int *a, int *b, int *len);

int		*ft_pb(int *a, int *b, int *len);
int		*ft_pa(int *a, int *b, int *len);
int		ft_s_r_rr(int *x, int len, int move, char *message);
int		ft_putstr(char *str);
void	ft_error(int *a);
void	ft_succes_exit(int *a);
void	ft_double_error(int *a, int *b);
int		*ft_free(int *x);
int		ft_strncmp(char *line, char *checker);
int		ft_scommand(int *buf_a,	int *buf_b, char *line, int *buf_len);
int		*ft_pb_check(int *a, int *b, int *len);
int		*ft_pa_check(int *a, int *b, int *len);
void	ft_check_if_ok(int *buf_a, int *buf_b, char *instr, int *buf_len);
void	ft_srrr_check(int *x, int len, int move);
void	ft_ssab_check(int *a, int *b, int *len);
void	ft_rrab_check(int *a, int *b, int *len);
void	ft_rrrab_check(int *a, int *b, int *len);
void	ft_read(int *buf_a, int *buf_b, int *buf_len);
void	ft_free_al(int *buf_a, int *buf_b, char *instructions, int i);

#endif
