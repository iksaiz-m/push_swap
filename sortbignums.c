/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbignums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:43:45 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/30 21:43:07 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	push(a, (*b)->target, 'a');
	ft_pa(a, b);
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		ft_rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		ft_rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheaptmp;

	cheaptmp = get_cheapest(*a);
	if (cheaptmp->above_media
		&& cheaptmp->target->above_media)
		rotate_both(a, b, cheaptmp);
	else if (!(cheaptmp->above_media)
		&& !(cheaptmp->target->above_media))
		rev_rotate_both(a, b, cheaptmp);
	push(a, cheaptmp, 'a');
	push(b, cheaptmp->target, 'b');
	ft_pb(a, b);
}

void	ft_sortbignums(t_stack **a, t_stack **b)
{
	int	len;

	len = checklenght(*a);
	if (len-- > 3 && !ft_sorted(*a))
		ft_pb(a, b);
	if (len-- > 3 && !ft_sorted(*a))
		ft_pb(a, b);
	while (len-- > 3 && !ft_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	ft_sort3_num(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
