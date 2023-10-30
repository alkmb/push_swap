/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:09:22 by akambou           #+#    #+#             */
/*   Updated: 2023/10/30 02:25:10 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_exit(int *nums_in_a, int *nums_in_b)
{
	free(nums_in_a);
	free(nums_in_b);
	exit(0);
}

void	free_exit_error(int *nums_in_a, int *nums_in_b)
{
	free(nums_in_a);
	free(nums_in_b);
	write(1, "Error\n", 6);
	exit(0);
}

void	check_params(int argc, char **argv, int *nums_in_a, int *nums_in_b)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		free_exit(nums_in_a, nums_in_b);
	while (i < argc)
	{
		if ((argv[i][ft_strlen(argv[i]) - 1] == ' ') || (argv[i][0] == ' '))
			free_exit_error(nums_in_a, nums_in_b);
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (((argv[i][j] < 48) || (argv[i][j] > 57)) && (argv[i][j] != 32))
			{
				if (argv[i][j] != 45)
					free_exit_error(nums_in_a, nums_in_b);
			}
			if ((argv[i][j] == 32) && (argv[i][j + 1] == 32))
				free_exit_error(nums_in_a, nums_in_b);
			j++;
		}
		i++;
	}
}

void	set_nums(int *nums_in_a, int *nums_in_b, int argc)
{
	nums_in_a[0] = argc - 1;
	nums_in_a[1] = nums_in_a[0];
	*nums_in_b = 0;
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	*nums_in_a;
	int	*nums_in_b;

	nums_in_a = (int *)malloc(2 * sizeof(int));
	nums_in_b = (int *)malloc(sizeof(int));
	check_params(argc, argv, nums_in_a, nums_in_b);
	set_nums(nums_in_a, nums_in_b, argc);
	stack_a = (int *)malloc(sizeof(long) * stack_size(argc, argv));
	stack_b = (int *)malloc(sizeof(long) * stack_size(argc, argv));
	if ((separating_input_nums(stack_a, nums_in_a, argv) == -1) 
		|| (check_sorted(stack_a, nums_in_a) == 0))
		free_stacks(stack_a, stack_b, nums_in_a, nums_in_b);
	if ((nums_in_a[1] == 2) && (stack_a[0] > stack_a[1]))
		rotate_a(stack_a, nums_in_a);
	else if (nums_in_a[1] == 3)
		minisort(stack_a, nums_in_a);
	else if (nums_in_a[1] == 5)
		midsort(stack_a, stack_b, nums_in_a, nums_in_b);
	else
		bigsort(stack_a, stack_b, nums_in_a, nums_in_b);
	free_stacks(stack_a, stack_b, nums_in_a, nums_in_b);
	return (0);
}
