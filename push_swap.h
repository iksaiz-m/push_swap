/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:39:16 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/13 19:37:28 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PUSH_SWAP_H)
# define PUSH_SWAP_H

# include "libft/libft.h"

# define MAX_INT	2147483647
# define MIN_INT -2147483648
# define ERROR_INT 9999999999

typedef struct s_stack
{
	int				t;
	int				i;
	long			index;
	long			num;
	int				boolean;
	long			result;
	char			**str;
	char			*x;
	char			*y;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

#endif // PUSH_SWAP_H
