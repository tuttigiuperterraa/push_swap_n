/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:12:36 by gcosenza          #+#    #+#             */
/*   Updated: 2024/04/05 08:12:37 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack **stack_a, t_stack **stack_b, int index, int size)
{
	ft_index(*stack_a);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(stack_a);
			index--;
		}
		pb(stack_b, stack_a);
	}
	else if (index > size / 2)
	{
		while (index < size)
		{
			rra(stack_a);
			index++;
		}
		pb(stack_b, stack_a);
	}
}

void	move_to_a(t_stack **stack_b, t_stack **stack_a, int index, int size)
{
	ft_index(*stack_b);
	if (index < size / 2)
	{
		while (index > 1)
		{
			rb(stack_b);
			index--;
		}
		if ((*stack_b)->val < (*stack_b)->next->val)
			sb(stack_b);
		else if (index == 1)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (index >= size / 2)
	{
		while (index < size)
		{
			rrb(stack_b);
			index++;
		}
		pa(stack_a, stack_b);
	}
}

int	is_to_push(t_stack **stack_a, int j, t_stack *to_check, int size)
{
	t_stack	*node;
	int		check;

	node = *stack_a;
	check = 0;
	ft_index(*stack_a);
	while (node != NULL)
	{
		if (node->index == to_check->index || node->val > j)
		{
			check = 1;
			node = node->next;
		}
		else
		{
			if (node->index <= size / 2)
				check = push1(node, to_check, size, check);
			else if (node->index > size / 2)
				check = push2(node, to_check, size, check);
			node = node->next;
		}
	}
	return (check);
}
