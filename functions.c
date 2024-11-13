/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:43:27 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/13 20:19:00 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
void	sa(t_stack **stack_a)
{
    if(ft_lstsize > 1)
    ft_printf("sa\n");
}

void	sb(t_stack **stack_a)
{

    ft_printf("sb\n");
}
void	ss(t_stack **stack_a)
{

    //call functions sa&sb
}

void	pa(t_stack **stack_a)
{
    ft_printf("pa\n");
}

void	pb(t_stack **stack_a)
{
    ft_printf("pb\n");
}

void	ra(t_stack **stack_a)
{
    ft_printf("ra\n");

}

void	rb(t_stack **stack_a)
{
    ft_printf("rb\n");
}

void	rr(t_stack **stack_a)
{
    //call functions ra&rb
}

void	rra(t_stack **stack_a)
{
    ft_printf("rra\n");
}

void	rrb(t_stack **stack_a)
{
    ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a)
{
    //call functions rra&rrb
}
