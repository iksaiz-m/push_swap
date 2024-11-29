/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:56:22 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/29 21:56:42 by iksaiz-m         ###   ########.fr       */
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

int	checklenght(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_order(t_stack **a, t_stack **b)
{
	if (ft_sorted(*a))
		return ;
	if (checklenght(*a) == 2)
		ft_sa(a);
	if (checklenght(*a) == 3)
		ft_sort3_num(a);
	if (checklenght(*a) == 4)
		ft_sort4_num(a, b);
	if (checklenght(*a) == 5)
		ft_sort5_num(a, b);
	if (checklenght(*a) > 5)
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
	ft_printf("lenght a: %d\n", checklenght(a));
	ft_order(&a, &b);
	checkpa(&a);
	free(a);
	return (0);
}
