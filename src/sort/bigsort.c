/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:23:45 by akambou           #+#    #+#             */
/*   Updated: 2023/11/04 06:10:05 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_chunk(int *stack, int *stack_size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < stack_size[0])
	{
		j = i + 1;
		while (j < stack_size[0])
		{
			if (stack[i] > stack[j])
			{
				temp = stack[i];
				stack[i] = stack[j];
				stack[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	fill_copys(int *copy, int *copy_swap_a, int *stack_a, int *nums_in_a)
{
	int	i;

	i = 0;
	while (i < nums_in_a[0])
	{
		copy[i] = stack_a[i];
		copy_swap_a[i] = stack_a[i];
		i++;
	}
}

void	to_ogstack(int *copy, int *copy_swap_a, int *stack_a, int *nums_in_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nums_in_a[1])
	{
		j = 0;
		while (j < nums_in_a[0])
		{
			if (copy_swap_a[i] == copy[j])
				stack_a[i] = j;
			j++;
		}
		++i;
	}
}

void	bitshift(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	int	max_num;
	int	max_bits;
	int	loop[2];

	max_num = nums_in_a[1] - 1;
	max_bits = 0;
	loop[0] = 0;
	loop[1] = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (loop[0] < max_bits)
	{
		loop[1] = 0;
		while (loop[1] < nums_in_a[0])
		{
			if (((stack_a[0] >> loop[0]) & 1) == 1)
				rotate_a(stack_a, nums_in_a);
			else
				push_b(stack_a, stack_b, nums_in_a, nums_in_b);
			++loop[1];
		}
		print_stacks(stack_a, stack_b, nums_in_a, nums_in_b);
		while (*nums_in_b != 0)
			push_a(stack_a, stack_b, nums_in_a, nums_in_b);
		++loop[0];
	}
}

void	bigsort(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	int	*copy;
	int	*copy_swap_a;

	copy = (int *)malloc(nums_in_a[0] * sizeof(int));
	copy_swap_a = (int *)malloc(nums_in_a[0] * sizeof(int));
	fill_copys(copy, copy_swap_a, stack_a, nums_in_a);
	sort_chunk(copy, nums_in_a);
	to_ogstack(copy, copy_swap_a, stack_a, nums_in_a);
	free(copy);
	free(copy_swap_a);
	bitshift(stack_a, stack_b, nums_in_a, nums_in_b);
}
