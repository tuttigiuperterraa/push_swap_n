/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:12:09 by gcosenza          #+#    #+#             */
/*   Updated: 2024/04/05 08:27:51 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	pre_order(t_stack **stack_a, t_stack **stack_b, int j, int size)
{
	t_stack	*node;

	node = NULL;
	node = *stack_a;
	ft_index(*stack_a);
	while (node != NULL)
	{
		if (node->val <= j)
		{
			if (is_to_push(stack_a, j, node, size) == 1)
			{
				move_to_b(stack_a, stack_b, node->index, size);
				size--;
				ft_index(*stack_a);
				node = *stack_a;
			}
			else
				node = node->next;
		}
		else
			node = node->next;
	}
}

int	pivot(int *arr, int size)
{
	if (size == 2 || size == 3)
		return (arr[0]);
	else if (size == 5)
		return (arr[size / 2]);
	else if (size <= 100)
		return (arr[size / 4]);
	else if (size <= 400)
		return (arr[size / 6]);
	else
		return (arr[size / 10]);
}

void	cont(t_stack **a, t_stack **b)
{
	if (counter(*a) == 3)
	{
		if ((max(a) == (*a)->next->val && (*a)->val < (*a)->next->next->val)
			|| (max(a) == (*a)->val && (*a)->next->val > (*a)->next->next->val))
		{
			sa(a);
			write (1, "sa\n", 3);
		}
		if (max(a) == (*a)->val && (*a)->next->val < (*a)->next->next->val)
			do_rotate(a, b, 1);
		else if ((*a)->next->val > (*a)->val || max(a) == (*a)->next->val)
			do_rrotate(a, b, 4);
		else if (max(a) == (*a)->next->next->val && (*a)->val > (*a)->next->val)
		{
			sa(a);
			write (1, "sa\n", 3);
		}
	}
	else
	{
		little_check(a, b);
		if (b && *b)
			pa(a, b);
		free_stack(*b);
	}
}

void	sort(t_stack **stack_a, int size)
{
	t_stack	*stack_b;
	int		*arr;
	int		p;

	arr = stack_to_array(*stack_a, size);
	if (arr == NULL)
		exit_error(*stack_a);
	p = pivot(arr, size);
	stack_b = NULL;
	while (size > 2)
	{
		pre_order(stack_a, &stack_b, p, size);
		size = counter((*stack_a));
		free(arr);
		arr = stack_to_array((*stack_a), size);
		if (arr == NULL)
			exit_error(*stack_a);
		p = pivot(arr, size);
	}
	free(arr);
	if ((*stack_a)->val > (*stack_a)->next->val && (counter(*stack_a) == 2))
		sa(stack_a);
	cont(stack_a, &stack_b);
}
