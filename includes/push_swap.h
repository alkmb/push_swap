/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:36:43 by akambou           #+#    #+#             */
/*   Updated: 2023/11/14 10:10:53 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>

//-------------------MOVEMENTS------------------------------------------------
void	push_a(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
void	push_b(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
void	swap_a(int *stack_a, int *nums_in_a);
void	swap_b(int *stack_b, int *nums_in_b);
void	swap_both(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
void	rotate_a(int *stack_a, int *nums_in_a);
void	rotate_b(int *stack_b, int *nums_in_b);
void	rotate_both(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
void	rev_rotate_a(int *stack_a, int *nums_in_a);
void	rev_rotate_b(int *stack_b, int *nums_in_b);
void	rev_rotate_both(int *stack_a, int *stack_b, \
int		*nums_in_a, int *nums_in_b);
//------------------FREES-----------------------------------------------------
void	free_exit(int *nums_in_a, int *nums_in_b);
void	free_exit_error(int *nums_in_a, int *nums_in_b);
void	free_stacks(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
void	free_str(char **str);
//------------------STACKS----------------------------------------------------
void	check_params(int argc, char **argv, int *nums_in_a, int *nums_in_b);
void	set_nums(int *nums_in_a, int *nums_in_b, int argc);
void	params(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
int		stack_size(int argc, char **argv);
int		rep_nums(int *stack_a, int nums_in_a);
int		out_of_range(char *str_num);
void	print_stacks(int *stack_a, int *stack_b, int *nums_in_a, \
int		*nums_in_b);
//------------------SORT------------------------------------------------------
void	minisort(int *stack_a, int *nums_in_a);
void	sort_chunk(int *stack, int *stack_size);
void	fill_copys(int *copy, int *copy_swap_a, int *stack_a, int *nums_in_a);
void	to_ogstack(int *copy, int *copy_swap_a, int *stack_a, int *nums_in_a);
void	bitshift(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
void	rotate_a_radix(int *stack_a, int *nums_in_a);
void	rev_rotate_a_radix(int *stack_a, int *nums_in_a);
void	first_stack(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
void	second_stack(int *stack_a, int *stack_b, int *nums_in_a, \
int		*nums_in_b);
void	midsort(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
void	bigsort(int *stack_a, int *stack_b, int *nums_in_a, int *nums_in_b);
//------------------UTILS-----------------------------------------------------
void	ft_realloc(int *ptr, int startsize, int newsize);
void	set_nums(int *nums_in_a, int *nums_in_b, int argc);
char	**ft_split(const char *str, char c);
int		ft_isdigit(int i);
int		neg_num(char *num);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		check_sorted(int *stack_a, int *nums_in_a);
int		num_input(int *stack_a, int *nums_in_a, char **argv, char **nums_list);
int		std_input(int *stack_a, int *nums_in_a, char **argv);
int		check_input_nums(int *stack_a, int *nums_in_a, char **argv);

#endif
