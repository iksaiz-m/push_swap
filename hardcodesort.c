/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcodesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:46:30 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/30 21:39:56 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

bool	ft_sorted(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->num > tmp2->num)
			return (false);
		else
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
	}
	return (true);
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
		if (!ft_sorted(*a))
			ft_sa(a);
	}
	if (tmp->num > tmp2->num && tmp2->num > tmp3->num)
	{
		ft_ra(a);
		ft_sa(a);
	}
}

static int	ft_get_smaller(t_stack **a)
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
	return (x);
}

void	ft_sort4_num(t_stack **a, t_stack **b)
{
	if (ft_get_smaller(a) == 1)
		ft_sa(a);
	if (ft_get_smaller(a) == 2)
	{
		ft_ra(a);
		ft_sa(a);
	}
	if (ft_get_smaller(a) == 3)
		ft_rra(a);
	if (!ft_sorted(*a))
	{
		ft_pb(a, b);
		ft_sort3_num(a);
		ft_pa(a, b);
	}
}

void	ft_sort5_num(t_stack **a, t_stack **b)
{
	if (ft_get_smaller(a) == 1)
		ft_sa(a);
	if (ft_get_smaller(a) == 2)
	{
		ft_ra(a);
		ft_sa(a);
	}
	if (ft_get_smaller(a) == 3)
	{
		ft_rra(a);
		ft_rra(a);
	}
	if (ft_get_smaller(a) == 4)
		ft_rra(a);
	if (!ft_sorted(*a))
	{
		ft_pb(a, b);
		ft_sort4_num(a, b);
		ft_pa(a, b);
	}
}
