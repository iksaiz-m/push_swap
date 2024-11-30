/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:39:16 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/30 21:44:57 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PUSH_SWAP_H)
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "limits.h"
# include <stdbool.h>

# define MAX_INT	2147483647
# define MIN_INT -2147483648
# define ERROR_INT 9999999999

typedef struct s_stack
{
	int				t;
	int				i;
	int				cost;
	int				above_media;
	int				cheapest;
	long			index;
	long			num;
	int				boolean;
	long			result;
	char			**str;
	char			*x;
	char			*y;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

//arguments check//
char	**handle_multiple_arguments(int ac, char **av);
int		handle_repetition(char **str);
char	**handle_one_argument(char *av);

//fill stack//
long	*create_long(t_stack **a, char **str, int size);
void	charge_nlist(t_stack **a, long *nlist, int size);

//utils//
void	ft_free(char **a);
void	error(void);
long	ft_long_atoi(const char *str, int i);
int		checklenght(t_stack *stack);
size_t	ft_multiple_num(char const *s, char c);

//rules//
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_swap(t_stack **swap);
// void	ft_rotate(t_stack **rotate);
void	ft_revrotate(t_stack **revrotate);

//sort//
bool	ft_sorted(t_stack *stack);
void	ft_sort3_num(t_stack **a);
//int		ft_get_smaller(t_stack **a);
void	ft_sort4_num(t_stack **a, t_stack **b);
void	ft_sort5_num(t_stack **a, t_stack **b);
void	ft_sortbignums(t_stack **a, t_stack **b);
//sort utils//
void	set_cheapest(t_stack *stack);
void	current_index(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
t_stack	*biggest(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	push(t_stack **stack, t_stack *top_node, char stack_name);
t_stack	*get_cheapest(t_stack *stack);
void	init_nodes_b(t_stack *a, t_stack *b);
void	min_on_top(t_stack **a);

#endif // PUSH_SWAP_H

//static void	check_argument(char *av);