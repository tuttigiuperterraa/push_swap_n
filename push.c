/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:12:29 by gcosenza          #+#    #+#             */
/*   Updated: 2024/04/05 08:12:29 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **add, t_stack **take)
{
	t_stack	*g;
	t_stack	*temp;

	if (!add || !take)
		return ;
	g = malloc(sizeof(t_stack));
	if (!g)
	{
		while (*add != NULL)
		{
			temp = *add;
			*add = (*add)->next;
			free(temp);
		}
		return ;
	}
	g->val = (*take)->val;
	g->next = *add;
	*add = g;
	remove_first(take);
	write(1, "pa\n", 3);
}

void	pb(t_stack **add, t_stack **take)
{
	t_stack	*g;
	t_stack	*temp;

	if (!add || !take)
		return ;
	g = malloc(sizeof(t_stack));
	if (!g)
	{
		while (*add != NULL)
		{
			temp = *add;
			*add = (*add)->next;
			free(temp);
		}
		return ;
	}
	g->val = (*take)->val;
	g->next = *add;
	*add = g;
	remove_first(take);
	write(1, "pb\n", 3);
}

int	push1(t_stack *node, t_stack *to_check, int size, int check)
{
	if (to_check->index <= size / 2)
	{
		if (to_check->index < node->index)
			check = 1;
		else
			check = 0;
	}
	else if (to_check->index > size / 2)
	{
		if (size + 1 - to_check->index <= node->index)
			check = 1;
		else
			check = 0;
	}
	return (check);
}

int	push2(t_stack *node, t_stack *to_check, int size, int check)
{
	if (to_check->index >= size / 2)
	{
		if (size + 1 - to_check->index < size + 1 - node->index)
			check = 1;
		else
			check = 0;
	}
	else if (to_check->index < size / 2)
	{
		if (to_check->index <= size + 1 - node->index)
			check = 1;
		else
			check = 0;
	}
	return (check);
}
