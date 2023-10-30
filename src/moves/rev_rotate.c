/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:01:31 by akambou           #+#    #+#             */
/*   Updated: 2023/10/30 02:49:37 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rotate_a(int *stack_a, int *nums_in_a)
{
	int	i;
	int	*temp;

	i = nums_in_a[1] - 1;
	temp = (int *)malloc(sizeof(int));
	*temp = stack_a[nums_in_a[1] - 1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = *temp;
	free(temp);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(int *stack_b, int *nums_in_b)
{
	int	i;
	int	*temp;

	i = *nums_in_b - 1;
	temp = (int *)malloc(sizeof(int));
	*temp = stack_b[*nums_in_b - 1];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = *temp;
	free(temp);
	write(1, "rrb\n", 4);
}

void	rev_rotate_both(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	int	i;
	int	*temp;

	i = nums_in_b[1] - 1;
	temp = (int *)malloc(sizeof(int));
	*temp = stack_a[nums_in_a[1] - 1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = *temp;
	i = 0;
	*temp = stack_b[0];
	while (i < *nums_in_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*nums_in_b - 1] = *temp;
	free(temp);
	write(1, "rrr\n", 4);
}
