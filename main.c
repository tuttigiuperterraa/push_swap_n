/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:11:54 by gcosenza          #+#    #+#             */
/*   Updated: 2024/04/05 08:11:54 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			n;
	long int	*nums;

	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	n = count_num(argv);
	if (n < 0)
		return (write(STDERR_FILENO, "Error\n", 6));
	nums = malloc(sizeof(long int ) * n);
	check_atoi(argv, nums, n);
	if (n == 1 || is_sorted(nums, n))
	{
		free(nums);
		return (0);
	}
	array_to_stack(nums, n, &stack_a);
	sort(&stack_a, n);
	free_stack(stack_a);
	free(nums);
	return (0);
}
