/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:46:45 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:46:46 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		*stack_from_tab(char **tab, int size, int start_i)
{
	int		*stack;
	int		i;

	stack = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		stack[i] = ft_atoi(tab[start_i]);
		start_i++;
		i++;
	}
	return (stack);
}

void	print_stack(t_stack *stack)
{
	int		i;

	printf("stack size = %i\n", stack->size);
	printf("stack first = %i\n", stack->first);
	i = stack->first - 1;
	while (++i < stack->size)
		printf("stack[%i] = [%i]\n", i, (stack->stack)[i]);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	ft_printf(" stack_a    stack_b \n");
	ft_printf("---------  ---------\n");
	i = -1 + ((stack_a->first < stack_b->first) ? \
	stack_a->first : stack_b->first);
	while (++i < stack_a->size)
	{
		if (stack_a->first <= i)
			ft_printf("%9i  ", (stack_a->stack)[i]);
		else
			ft_printf("%11c", ' ');
		if (stack_b->first <= i)
			ft_printf("%9i\n", (stack_b->stack)[i]);
		else
			ft_printf("\n");
	}
	ft_printf("---------  ---------\n");
}
