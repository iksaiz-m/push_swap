/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:43:27 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/22 19:22:54 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_revrotate(t_stack **revrotate)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*tmp_prev;

	if (!*revrotate || !((*revrotate)->next))
		return ;
	tmp = *revrotate;
	last = NULL;
	tmp_prev = tmp;
	while (tmp->next != NULL)
	{
		tmp_prev->prev = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	tmp = *revrotate;
	*revrotate = last;
	(*revrotate)->next = tmp;
	tmp_prev = tmp_prev->prev;
	tmp_prev->next = NULL;
}

void	ft_rra(t_stack **a)
{
	if (!*a || !((*a)->next))
		return ;
	ft_revrotate(a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **b)
{
	if (!*b || !((*b)->next))
		return ;
	ft_revrotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next || !*b || !((*b)->next))
		return ;
	ft_revrotate(a);
	ft_revrotate(b);
	ft_printf("rrr\n");
}
