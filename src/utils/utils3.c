/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:42:27 by akambou           #+#    #+#             */
/*   Updated: 2023/11/14 10:45:03 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

int	num_input(int *stack_a, int *nums_in_a, char **argv, char **nums_list)
{
	int	i;
	int	nums;

	i = 0;
	nums = 0;
	nums_list = ft_split(argv[1], 32);
	while (nums_list[i])
	{
		nums++;
		i++;
	}
	nums_in_a[0] = nums;
	nums_in_a[1] = nums_in_a[0];
	i = 0;
	while (i < nums_in_a[0])
	{
		stack_a[i] = ft_atoi(nums_list[i]);
		i++;
	}
	free_str(nums_list);
	free(nums_list);
	return (0);
}

int	std_input(int *stack_a, int *nums_in_a, char **argv)
{
	int	i;

	i = 0;
	while (i < nums_in_a[1])
	{
		if (neg_num(argv[i + 1]) == 1)
			stack_a[i] = ft_atoi(argv[i + 1]);
		else
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_input_nums(int *stack_a, int *nums_in_a, char **argv)
{
	char	**nums_list;

	nums_list = NULL;
	if (nums_in_a[0] == 1)
	{
		if (num_input(stack_a, nums_in_a, argv, nums_list) == -1)
			return (-1);
	}
	else
	{
		if (std_input(stack_a, nums_in_a, argv) == -1)
			return (-1);
	}
	if (rep_nums(stack_a, nums_in_a[1]) == -1)
		return (-1);
	return (0);
}
