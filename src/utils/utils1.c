/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:40:27 by akambou           #+#    #+#             */
/*   Updated: 2023/10/30 02:44:34 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stacks(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	free(stack_a);
	free(stack_b);
	free(nums_in_a);
	free(nums_in_b);
	exit(0);
}

int	stack_size(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 32)
				size++;
			i++;
		}
	}
	else
		size = argc - 1;
	return (size);
}

int	rep_nums(int *stack_a, int nums_in_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nums_in_a)
	{
		j = 0;
		while (j < nums_in_a)
		{
			if ((stack_a[i] == stack_a[j]) && (i != j))
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_realloc(int *ptr, int startsize, int newsize)
{
	int	i;
	int	*temp;

	i = 0;
	if ((ptr != NULL) && (startsize < newsize))
	{
		temp = malloc(sizeof(int) * (newsize));
		while (i < startsize)
		{
			temp[i] = ptr[i];
			i++;
		}
		ptr = temp;
	}
	else if ((ptr != NULL) && (startsize > newsize))
	{
		temp = malloc(sizeof(int) * (newsize));
		while (i < newsize)
		{
			temp[i] = ptr[i];
			i++;
		}
		ptr = temp;
	}
}

void	params(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	push_a(stack_a, stack_b, nums_in_a, nums_in_b);
	rotate_a(stack_a, nums_in_a);
}
