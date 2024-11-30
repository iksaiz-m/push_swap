/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:56:22 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/30 21:44:30 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	checkpa(t_stack **a)
{
	t_stack	*temporal;
	t_stack	**j;

	j = a;
	while (*j)
	{
		temporal = ((*j))->next;
		ft_printf("%d ", (*j)->num);
		*j = temporal;
	}
}

int	checklenght(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	ft_order(t_stack **a, t_stack **b)
{
	int	size;

	size = checklenght(*a);
	if (ft_sorted(*a))
		return ;
	if (size == 2)
		ft_sa(a);
	if (size == 3)
		ft_sort3_num(a);
	if (size == 4)
		ft_sort4_num(a, b);
	if (size == 5)
		ft_sort5_num(a, b);
	if (size > 5)
		ft_sortbignums(a, b);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		**str;
	int			i;

	i = 0;
	a = NULL;
	str = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
		str = handle_one_argument(av[1]);
	if (ac > 2)
		str = handle_multiple_arguments(ac, av);
	handle_repetition(str);
	while (str[i])
		i++;
	create_long(&a, str, i);
	ft_order(&a, &b);
	checkpa(&a);
	free(a);
	return (0);
}
