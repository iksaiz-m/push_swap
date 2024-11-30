/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:37:40 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/30 21:43:46 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	current_index(t_stack *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = checklenght(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_media = true;
		else
			stack->above_media = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_mach;

	while (a)
	{
		best_mach = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num
				&& current_b->num > best_mach)
			{
				best_mach = current_b->num;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_mach == LONG_MIN)
			a->target = biggest(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	lenght_a;
	int	lenght_b;

	lenght_a = checklenght(a);
	lenght_b = checklenght(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_media))
			a->cost = lenght_a - (a->index);
		if (a->target->above_media)
			a->cost += a->target->index;
		else
			a->cost += lenght_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheap;
	t_stack	*cheapest;

	if (!stack)
		return ;
	cheap = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheap)
		{
			cheap = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
