/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:12:47 by gcosenza          #+#    #+#             */
/*   Updated: 2024/04/05 08:12:47 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counter(t_stack *a)
{
	int		n;
	t_stack	*temp;

	n = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}

void	f(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return ;
}

void	remove_first(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack)->next;
	free(*stack);
	(*stack) = temp;
}

void	free_stack(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	exit_error(t_stack *stack)
{
	if (stack != NULL)
	{
		free_stack(stack);
		write(1, "Error\n", 6);
		exit(1);
	}
}
