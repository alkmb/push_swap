/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:17:40 by akambou           #+#    #+#             */
/*   Updated: 2023/11/04 02:52:09 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	minisort(int *stack_a, int *nums_in_a)
{
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2])
		&& (stack_a[0] < stack_a[2]))
		swap_a(stack_a, nums_in_a);
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] > stack_a[2]))
	{
		swap_a(stack_a, nums_in_a);
		rev_rotate_a(stack_a, nums_in_a);
	}
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2])
		&& (stack_a[0] > stack_a[2]))
		rotate_a(stack_a, nums_in_a);
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] < stack_a[2]))
	{
		swap_a(stack_a, nums_in_a);
		rotate_a(stack_a, nums_in_a);
	}
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] > stack_a[2]))
		rev_rotate_a(stack_a, nums_in_a);
}
