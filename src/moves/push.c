/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:47:32 by akambou           #+#    #+#             */
/*   Updated: 2023/10/30 02:42:17 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	int	i;

	(nums_in_a[1])++;
	i = nums_in_a[1] - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < *nums_in_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	(*nums_in_b)--;
	if (*nums_in_b == 0)
		stack_b = NULL;
	write(1, "pa\n", 3);
}

void	push_b(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	int	i;

	(*nums_in_b)++;
	i = *nums_in_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < nums_in_a[1])
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	(nums_in_a[1])--;
	if (nums_in_a[1] == 0)
		stack_a = NULL;
	write(1, "pb\n", 3);
}
