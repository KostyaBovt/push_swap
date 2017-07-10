/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:46:28 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:46:29 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_stack(int *stack, int first, int last)
{
	int		i;
	int		j;
	int		median;

	i = first;
	j = last;
	median = stack[(first + last) / 2];
	while (i <= j)
	{
		while (stack[i] < median)
			i++;
		while (stack[j] > median)
			j--;
		if (i <= j)
		{
			if (stack[i] > stack[j])
				ft_swap(&stack[i], &stack[j]);
			i++;
			j--;
		}
	}
	if (i < last)
		sort_stack(stack, i, last);
	if (first < j)
		sort_stack(stack, first, j);
}

int		is_dublic_stack(t_stack *stack)
{
	int			i;
	t_stack		*stack_sorted;

	stack_sorted = copy_stack(stack);
	sort_stack(stack_sorted->stack, 0, stack_sorted->size - 1);
	i = 0;
	while (++i < stack_sorted->size)
		if ((stack_sorted->stack)[i] == (stack_sorted->stack)[i - 1])
		{
			error_return0("stack has dublicates");
			del_stack(&stack_sorted);
			return (1);
		}
	del_stack(&stack_sorted);
	return (0);
}
