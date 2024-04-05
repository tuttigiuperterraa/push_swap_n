/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackA.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:12:40 by gcosenza          #+#    #+#             */
/*   Updated: 2024/04/05 08:12:40 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_to_stack(long int *arr, int size, t_stack **stack)
{
	t_stack		*new_node;
	int			i;

	i = size - 1;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			f(*stack);
		new_node->val = arr[i];
		new_node->next = *stack;
		*stack = new_node;
		i--;
	}
}

void	ft_index(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

int	*stack_to_array(t_stack *stack_a, int size)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * size + 1);
	if (!arr)
		return (NULL);
	while (stack_a != NULL)
	{
		arr[i] = stack_a->val;
		stack_a = stack_a->next;
		i++;
	}
	sort_array(arr, size);
	return (arr);
}
