/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:18:40 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/22 19:22:35 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_swap(t_stack **swap)
{
	t_stack	*tmp;

	if (!*swap || !((*swap)->next))
		return ;
	tmp = *swap;
	*swap = (*swap)->next;
	tmp->next = (*swap)->next;
	(*swap)->next = tmp;
}

void	ft_sa(t_stack **a)
{
	if (!*a || !((*a)->next))
		return ;
	ft_swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b)
{
	if (!*b || !((*b)->next))
		return ;
	ft_swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	if (!a || !(*a)->next || !*b || !((*b)->next))
		return ;
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
