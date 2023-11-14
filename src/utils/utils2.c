/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:49:45 by akambou           #+#    #+#             */
/*   Updated: 2023/11/14 10:40:17 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int i)
{
	while ('0' <= i && i <= '9')
		return (1);
	return (0);
}

int	neg_num(char *num)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (num[i])
	{
		if (num[i] == 45)
			minus++;
		else if (ft_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	if (minus > 1)
		return (0);
	return (1);
}

int	check_sorted(int *stack_a, int *nums_in_a)
{
	int	i;
	int	j;
	int	max;

	i = 1;
	j = 0;
	max = stack_a[0];
	while (i < nums_in_a[1])
	{
		if (stack_a[i] > max)
		{
			max = stack_a[i];
			j++;
		}
		i++;
	}
	if (j == nums_in_a[1] - 1)
		return (0);
	return (-1);
}
