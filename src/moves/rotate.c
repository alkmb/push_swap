/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:37:28 by akambou           #+#    #+#             */
/*   Updated: 2023/11/04 02:53:53 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(int *stack_a, int *nums_in_a)
{
	int	i;
	int	*temp;

	i = 0;
	temp = (int *)malloc(sizeof(int));
	*temp = stack_a[0];
	while (i < nums_in_a[1])
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[nums_in_a[1] - 1] = *temp;
	free(temp);
	write(1, "ra\n", 3);
}

void	rotate_b(int *stack_b, int *nums_in_b)
{
	int	i;
	int	*temp;

	i = 0;
	temp = (int *)malloc(sizeof(int));
	*temp = stack_b[0];
	while (i < *nums_in_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*nums_in_b - 1] = *temp;
	free(temp);
	write(1, "rb\n", 3);
}

void	rotate_both(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b)
{
	int	i;
	int	*temp;

	i = 0;
	temp = (int *)malloc(sizeof(int));
	*temp = stack_a[0];
	while (i < nums_in_a[1])
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[nums_in_a[1] - 1] = *temp;
	i = 0;
	*temp = stack_b[0];
	while (i < *nums_in_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*nums_in_b - 1] = *temp;
	free(temp);
	write(1, "rr\n", 3);
}
