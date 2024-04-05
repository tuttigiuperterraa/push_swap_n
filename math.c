/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:29:05 by gcosenza          #+#    #+#             */
/*   Updated: 2024/04/05 08:29:05 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	temp = *stack;
	max = INT_MIN;
	while (temp)
	{
		if (max < temp->val)
			max = temp->val;
		temp = temp->next;
	}
	return (max);
}

int	err(char **nptr)
{
	int	i;
	int	j;

	i = 0;
	while (nptr[++i])
	{
		j = 0;
		while (nptr[i][j])
		{
			if (is_sign(nptr[i][j]) && (nptr[i][j + 1] < '0'
				|| nptr[i][j + 1] > '9'))
				return (0);
			if (nptr[i][j] >= '0' && nptr[i][j] <= '9')
			{
				while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
				{
					if (nptr[i][j + 1] == '+' || nptr[i][++j] == '-')
						return (0);
				}
			}
			else
				j++;
		}
	}
	return (1);
}

int	count_num(char **nptr)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 1;
	if (!err(nptr))
		return (-1);
	while (nptr[i])
	{
		j = 0;
		while (nptr[i][j])
		{
			if (nptr[i][j] >= '0' && nptr[i][j] <= '9')
			{
				while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
					j++;
				n++;
			}
			else
				j++;
		}
		i++;
	}
	return (n);
}
