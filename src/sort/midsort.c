/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:26:32 by akambou           #+#    #+#             */
/*   Updated: 2023/11/04 02:52:52 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a_radix(int *stack_a, int *nums_in_a)
{
	rotate_a(stack_a, nums_in_a);
	rotate_a(stack_a, nums_in_a);
}

void	rev_rotate_a_radix(int *stack_a, int *nums_in_a)
{
	rev_rotate_a(stack_a, nums_in_a);
	rev_rotate_a(stack_a, nums_in_a);
}

void	first_stack(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	if (stack_b[0] < stack_a[0])
		push_a(stack_a, stack_b, nums_in_a, nums_in_b);
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		rotate_a(stack_a, nums_in_a);
		push_a(stack_a, stack_b, nums_in_a, nums_in_b);
		rev_rotate_a(stack_a, nums_in_a);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		rev_rotate_a(stack_a, nums_in_a);
		push_a(stack_a, stack_b, nums_in_a, nums_in_b);
		rev_rotate_a(stack_a, nums_in_a);
		rev_rotate_a(stack_a, nums_in_a);
	}
	else if (stack_b[0] > stack_a[2])
	{
		push_a(stack_a, stack_b, nums_in_a, nums_in_b);
		rotate_a(stack_a, nums_in_a);
	}
}

void	second_stack(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	if (stack_b[0] < stack_a[0])
		push_a(stack_a, stack_b, nums_in_a, nums_in_b);
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		rotate_a(stack_a, nums_in_a);
		push_a(stack_a, stack_b, nums_in_a, nums_in_b);
		rev_rotate_a(stack_a, nums_in_a);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		rotate_a(stack_a, nums_in_a);
		push_a(stack_a, stack_b, nums_in_a, nums_in_b);
		swap_a(stack_a, nums_in_a);
		rev_rotate_a(stack_a, nums_in_a);
	}
	else if ((stack_b[0] > stack_a[2]) && (stack_b[0] < stack_a[3]))
	{
		rev_rotate_a(stack_a, nums_in_a);
		push_a(stack_a, stack_b, nums_in_a, nums_in_b);
		rotate_a_radix(stack_a, nums_in_a);
	}
	else if (stack_b[0] > stack_a[3])
		params(stack_a, stack_b, nums_in_a, nums_in_b);
}

void	midsort(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	push_b(stack_a, stack_b, nums_in_a, nums_in_b);
	push_b(stack_a, stack_b, nums_in_a, nums_in_b);
	minisort(stack_a, nums_in_a);
	while (*nums_in_b != 0)
	{
		if (nums_in_a[1] == 3)
			first_stack(stack_a, stack_b, nums_in_a, nums_in_b);
		else if (nums_in_a[1] == 4)
			second_stack(stack_a, stack_b, nums_in_a, nums_in_b);
	}
}
