/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:20:03 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/30 21:22:20 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// void	ft_rotate(t_stack **rotate)
// {
// 	t_stack	*tmp;
// 	t_stack	*last;

// 	if (!*rotate || !((*rotate)->next))
// 		return ;
// 	tmp = *rotate;
// 	last = NULL;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	last = tmp;
// 	tmp = *rotate;
// 	*rotate = (*rotate)->next;
// 	last->next = tmp;
// 	tmp->next = NULL;
// }

static void	ft_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ft_ra(t_stack **a)
{
	if (!*a || !((*a)->next))
		return ;
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **b)
{
	if (!*b || !((*b)->next))
		return ;
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (!a || !(*a)->next || !*b || !((*b)->next))
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
