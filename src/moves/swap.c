/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:02:12 by akambou           #+#    #+#             */
/*   Updated: 2023/10/29 22:54:14 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

void	swap_a(int *stack_a, int *nums_in_a)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	if (nums_in_a[1] > 1)
	{
		temp[0] = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp[0];
	}
	free(temp);
	write(1, "sa\n", 3);
}

void	swap_b(int *stack_b, int *nums_in_b)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	if (*nums_in_b > 1)
	{
		temp[0] = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp[0];
	}
	free(temp);
	write(1, "sb\n", 3);
}

void	swap_both(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	if (nums_in_a[1] > 1)
	{
		temp[0] = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp[0];
	}
	if (*nums_in_b > 1)
	{
		temp[0] = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp[0];
	}
	free(temp);
	write(1, "ss\n", 3);
}
