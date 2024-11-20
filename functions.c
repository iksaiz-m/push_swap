/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:43:27 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/20 21:36:29 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_sa(t_stack **a)
{
	t_stack	*tmp;
	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b)
{
	t_stack	*tmp;
	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_printf("sb\n");
}
void	ft_ss(t_stack **a, t_stack **b)
{
    if(!a || !(*a)->next)
    	return ;
        //call functions sa&sb
    ft_printf("ss\n");
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	if (!*b)
    	return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
    *a = tmp;
    ft_printf("pb\n");
}

void	ft_pb(t_stack **a, t_stack **b)
{
    t_stack	*tmp;
	if (!*a)
    	return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
    *b = tmp;
    ft_printf("pb\n");
}

void	ft_ra(t_stack **a)
{
	if (!*a || !((*a)->next))
    	return ;
    ft_printf("ra\n");
}

void	ft_rb(t_stack **a)
{
	if (!*a || !((*a)->next))
    	return ;
    ft_printf("rb\n");
}

void	ft_rr(t_stack **a)
{
	if (!*a || !((*a)->next))
    	return ;
        //call functions ra&rb
    ft_printf("rr\n");
}

void	ft_rra(t_stack **a)
{
    if(!a || !(*a)->next)
    	return ;
    ft_printf("rra\n");
}

void	ft_rrb(t_stack **a)
{
    if(!a || !(*a)->next)
    	return ;
    ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a)
{
    if(!a || !(*a)->next)
    	return ;
        //call functions rra&rrb
    ft_printf("rrr\n");
}
