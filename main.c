/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:56:22 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/25 21:29:14 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	checkpa(t_stack **a)
{
	t_stack	*temporal;
	t_stack	**j;

	j = a;
	ft_printf("Valor stack a:\n");
	while (*j)
	{
		temporal = ((*j))->next;
		ft_printf(" %d ", (*j)->num);
		*j = temporal;
	}
}

void	checkpb(t_stack **b)
{
	t_stack	*temporal;
	t_stack	**j;

	j = b;
	ft_printf("\nValor stack b:\n");
	while (*j)
	{
		temporal = ((*j))->next;
		ft_printf(" %d ", (*j)->num);
		*j = temporal;
	}
}

// void	ft_play(t_stack **a, t_stack **b)
// {
// 	ft_pb(&a, &b);
// 	ft_pb(&a, &b);
// 	ft_pb(&a, &b);
// 	ft_ss(&a, &b);
// 	ft_rr(&a, &b);
	//checkpa(&a);
// 	checkpb(&b);
// }

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

int	ft_sorted(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->num > tmp2->num)
			return (0);
		else
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
	}
	return (1);
}

void	ft_sort3_num(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*tmp3;

	tmp = *a;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	if (tmp->num > tmp2->num && tmp->num < tmp3->num)
		ft_sa(a);
	else if (tmp->num > tmp2->num && tmp2->num < tmp3->num)
		ft_ra(a);
	else if (tmp->num < tmp2->num && tmp2->num > tmp3->num)
	{
		ft_rra(a);
		if (!ft_sorted(a))
			ft_sa(a);
	}
	if (tmp->num > tmp2->num && tmp2->num > tmp3->num)
	{
		ft_ra(a);
		ft_sa(a);
	}
}
int	ft_get_smaller(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	int		x;

	tmp = *a;
	tmp2 = tmp->next;
	x = 0;
	i = 1;
	while (tmp2 != NULL)
	{
		if (tmp->num > tmp2->num)
		{
			tmp = tmp2;
			x = i;
		}
		tmp2 = tmp2->next;
		i++;
	}
	return(x);
}
void	ft_sort4_num(t_stack **a, t_stack **b)
{
	// t_stack	*tmp;
	// t_stack	*tmp2;

	if (ft_get_smaller(a) == 1)
		ft_sa(a);
	if (ft_get_smaller(a) == 2)
	{
		ft_ra(a);
		ft_sa(a);
	}
	if (ft_get_smaller(a) == 3)
		ft_rra(a);
	if (!ft_sorted(a))
	{
		ft_pb(a, b);
		ft_sort3_num(a);
		ft_pa(a, b);
	}
}


void	ft_order(t_stack **a, t_stack **b)
{
	ft_printf("longitud a: %d\n", checklenght(*a));
	if (ft_sorted(a))
		return ;
	if (checklenght(*a) == 2)
		ft_sa(a);
	if (checklenght(*a) == 3)
		ft_sort3_num(a);
	if (checklenght(*a) == 4)
		ft_sort4_num(a, b);
	// if (checklenght(*a) == 5)
	// 	ft_sort5_num(a);
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
	return (0);
}
