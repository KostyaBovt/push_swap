/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:52:09 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:52:10 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*get_stack(int argc, char **argv, t_ps_bskt **bskt)
{
	if ((*bskt)->s)
		return (get_stack_file(bskt));
	else
		return (get_stack_argv(argc, argv, bskt));
}

t_stack		*get_stack_file(t_ps_bskt **bskt)
{
	int			fd;
	t_gnl_list	*gnl_stack;
	char		**tab_stack;
	char		*gnl_str;
	t_stack		*stack;

	stack = NULL;
	fd = open((*bskt)->s_file, O_RDONLY);
	if (fd == -1)
		return ((t_stack*)error_return0("cannot open the file for stack"));
	if (!(gnl_stack = get_inpt_fd(fd)))
		return ((t_stack*)error_return0("the file is empty"));
	gnl_str = gnl_to_string(gnl_stack);
	del_gnl_list(&gnl_stack);
	tab_stack = ft_strsplit(str_replace(gnl_str, '\n', ' '), ' ');
	free(gnl_str);
	if (!check_digits(0, count_tabs(tab_stack), tab_stack))
		return ((t_stack *)del_tab(&tab_stack));
	stack = new_stack(count_tabs(tab_stack), 0);
	stack->stack = stack_from_tab(tab_stack, stack->size, 0);
	del_tab(&tab_stack);
	if (!check_dubls(&stack))
		return (del_stack(&stack));
	return (stack);
}

t_stack		*get_stack_argv(int argc, char **argv, t_ps_bskt **bskt)
{
	t_stack		*stack;

	if (!check_digits((*bskt)->stack_i, argc, argv))
		return (NULL);
	stack = new_stack(argc - (*bskt)->stack_i, 0);
	stack->stack = stack_from_tab(argv, stack->size, (*bskt)->stack_i);
	if (!check_dubls(&stack))
		return (del_stack(&stack));
	return (stack);
}
