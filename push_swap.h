/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:28:23 by aconti            #+#    #+#             */
/*   Updated: 2024/04/05 08:43:43 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	long			val;
	int				index;
	struct s_stack	*next;
}	t_stack;

//atoi.c
int			is_sign(char av);
long int	extract_number(char *str, int *index);
int			process_string(char *str, long int *nums, int n2);
int			ft_atoi(char **nptr, long int *nums, int n2);
//checks.c
int			ft_check(long int *nums, int i);
void		check_atoi(char **argv, long int *nums, int n);
int			is_sorted(long int *arr, int n);
void		little_check(t_stack **a, t_stack **b);
//math.c
int			max(t_stack **stack);
int			err(char **nptr);
int			count_num(char **nptr);
//push_utils.c
void		move_to_b(t_stack **stack_a,
				t_stack **stack_b, int index, int size);
void		move_to_a(t_stack **stack_b,
				t_stack **stack_a, int index, int size);
int			is_to_push(t_stack **stack_a, int j, t_stack *to_check, int size);
//push.c
void		pa(t_stack **add, t_stack **take);
void		pb(t_stack **add, t_stack **take);
int			push1(t_stack *node, t_stack *to_check, int size, int check);
int			push2(t_stack *node, t_stack *to_check, int size, int check);
//rev_rotate.c
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
//rotate_utils.c
int			type_rot_b(t_stack **stack);
void		rotate(t_stack **lst);
void		reverse_rotate(t_stack **lst);
void		do_rrotate(t_stack **a, t_stack **b, int cod);
void		do_rotate(t_stack **a, t_stack **b, int cod);
//rotate.c
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
//sort.c
void		sort_array(int *arr, int size);
void		pre_order(t_stack **stack_a, t_stack **stack_b, int j, int size);
int			pivot(int *arr, int size);
void		cont(t_stack **a, t_stack **b);
void		sort(t_stack **stack_a, int size);
//stackA.c
void		array_to_stack(long int *arr, int size, t_stack **stack);
void		ft_index(t_stack *stack);
int			*stack_to_array(t_stack *stack_a, int size);
//swap.c
void		sa(t_stack **a);
void		sb(t_stack **a);
void		ss(t_stack **a, t_stack **b);
//utils.c
int			counter(t_stack *a);
void		f(t_stack *stack);
void		remove_first(t_stack **stack);
void		free_stack(t_stack *head);
void		exit_error(t_stack *stack);

#endif
