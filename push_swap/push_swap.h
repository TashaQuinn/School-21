#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_elem
{
	int				value;
	int				a_score;
	int				b_score;
	int				a_score_rev;
	int				b_score_rev;
	int				rank;
	struct s_elem	*next;
}	t_elem;

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t n, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
int				splited_argc(char **str);
void			ft_putstr_fd(char *s, int fd);
int				are_args_valid(char **argv, int argc, int flag);
void			free_array(char **argv);
int				ft_is_space(int c);
int				ft_is_digit(int c);
size_t			ft_strlen(const char *str);
long long int	ft_atoi(const char *str);
t_elem			*stack_init(char **argv, int argc, int flag);
int				*sort_array(int *array, int size, t_elem *stack);
void			add_back(t_elem **stack, t_elem *new);
void			do_ra(t_elem **stack, int flag);
void			triple_sort(t_elem **stack);
int				stack_size(t_elem *stack);
void			do_pb(t_elem **stack_a, t_elem **stack_b, int flag);
void			do_sa(t_elem **stack, int flag);
t_elem			*find_last(t_elem *elem);
void			move_to_a(t_elem **stack_a, t_elem **stack_b);
t_elem			*pick_the_best(t_elem *stack, int *ttype);
void			assign_ranks(t_elem *stack, int *array);
void			do_operations(t_elem **stack_a, t_elem **stack_b,
					t_elem *elem, int *ttype);
void			do_operations2(t_elem **stack_a, t_elem **stack_b,
					t_elem *elem, int *ttype);
void			final_sort(t_elem **stack);
int				find_minmaxmed(t_elem **stack, int *min, int *max, int *med);
void			free_stack(t_elem **stack);
void			do_pa(t_elem **stack_a, t_elem **stack_b, int flag);
void			do_rb(t_elem **stack, int flag);
void			do_rr(t_elem **stack_a, t_elem **stack_b, int flag);
t_elem			*find_before_last(t_elem *stack);
void			add_front(t_elem **stack, t_elem *elem);
void			do_rrb(t_elem **stack, int flag);
void			do_rra(t_elem **stack, int flag);
void			do_rrr(t_elem **stack_a, t_elem **stack_b, int flag);
void			stack_sort(t_elem **stack);
int				ft_strcmp(const char *str1, const char *str2);
char			*get_next_line(int fd);
void			check_instructions(t_elem **stack_a);
void			do_sb(t_elem **stack, int flag);
void			do_ss(t_elem **stack_a, t_elem **stack_b, int flag);

#endif