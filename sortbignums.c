/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbignums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:43:45 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/29 21:47:36 by iksaiz-m         ###   ########.fr       */
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
			stack->t = 1;
		else
			stack->t = 0;
		stack = stack->next;
		i++;
	}
}
t_stack	*biggest(t_stack *stack)
{
	long	big;
	t_stack	*biggest_node;

	if (!stack)
		return (NULL);
	big = LONG_MIN;
	while (stack)
	{
		if (stack->num > big)
		{
			big = stack->num;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	set_target_a(t_stack *a, t_stack *b)
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
void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	lenght_a;
	int	lenght_b;

	lenght_a = checklenght(a);
	lenght_b = checklenght(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->t))
			a->cost = lenght_a - (a->index);
		if (a->target->t)
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
	cheapest->cheapest = 1;
}
void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while(*b != cheapest->target && *a != cheapest)
		ft_rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		ft_rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->t)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->t)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheaptmp;

	cheaptmp = get_cheapest(*a);
	if (cheaptmp->t
		&& cheaptmp->target->t)
		rotate_both(a, b, cheaptmp);
	else if (!(cheaptmp->t)
		&& !(cheaptmp->target->t))
		rev_rotate_both(a, b, cheaptmp);
	push(a, cheaptmp, 'a');
	push(b, cheaptmp->target, 'b');
	ft_pb(b, a);
}

t_stack	*find_min(t_stack *stack)
{
	long	small;
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->num < small)
		{
			small = stack->num;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num
				&& current_a->num < best_match)
			{
				best_match = current_a->num;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	push(a, (*b)->target, 'a');
	ft_pa(a, b);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->num != find_min(*a)->num)
	{
		if (find_min(*a)->t)
			ft_ra(a);
		else
			ft_rra(a);
	}
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

// int	ft_sorted(t_stack **a)
// {
// 	t_stack	*tmp;
// 	t_stack	*tmp2;

// 	tmp = *a;
// 	tmp2 = tmp->next;
// 	while (tmp2 != NULL)
// 	{
// 		if (tmp->num > tmp2->num)
// 			return (0);
// 		else
// 		{
// 			tmp = tmp->next;
// 			tmp2 = tmp->next;
// 		}
// 	}
// 	return (1);
// }

