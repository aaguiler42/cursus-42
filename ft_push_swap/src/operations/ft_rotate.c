/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:18:56 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/07 16:08:54 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_rot(int *stack, int stack_len, int n)
{
	int	i;

	i = 0;
	while (i < stack_len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[stack_len - 1] = n;
}

void	ft_rotate_a(t_stacks *stack, int print)
{
	if (stack->size_a < 2)
		return ;
	ft_rot(stack->stack_a, stack->size_a, stack->stack_a[0]);
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stacks *stack, int print)
{
	if (stack->size_b < 2)
		return ;
	ft_rot(stack->stack_b, stack->size_b, stack->stack_b[0]);
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rotate_both(t_stacks *stacks, int print)
{
	ft_rotate_b(stacks, 0);
	ft_rotate_a(stacks, 0);
	if (print)
		write(1, "rr\n", 3);
}
