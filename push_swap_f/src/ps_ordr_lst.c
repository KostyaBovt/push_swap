/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ordr_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:53:13 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:53:14 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_front_ordr_lst(int new_pack, t_ordr_lst **head_ordr_lst)
{
	t_ordr_lst	*new_ordr_lst;

	new_ordr_lst = (t_ordr_lst*)malloc(sizeof(t_ordr_lst));
	new_ordr_lst->pack = new_pack;
	new_ordr_lst->next = NULL;
	if (*head_ordr_lst == NULL)
		*head_ordr_lst = new_ordr_lst;
	else
	{
		new_ordr_lst->next = *head_ordr_lst;
		*head_ordr_lst = new_ordr_lst;
	}
}

void	del_ordr_lst(t_ordr_lst **head_ordr_lst)
{
	t_ordr_lst	*temp;

	while (*head_ordr_lst)
	{
		temp = (*head_ordr_lst)->next;
		free(*head_ordr_lst);
		*head_ordr_lst = temp;
	}
	*head_ordr_lst = NULL;
}

void	del_first_ordr_lst(t_ordr_lst **head_ordr_lst)
{
	t_ordr_lst	*temp;

	temp = (*head_ordr_lst)->next;
	free(*head_ordr_lst);
	*head_ordr_lst = temp;
}

int		is_ordr_lst_one(t_ordr_lst *head_ordr_lst)
{
	t_ordr_lst	*temp;

	temp = head_ordr_lst->next;
	if (temp)
		if (temp->pack == 0)
			return (1);
	return (0);
}

void	print_ordr_lst(t_ordr_lst *lst)
{
	while (lst)
	{
		ft_printf("%i\n", lst->pack);
		lst = lst->next;
	}
	ft_printf("---\n");
}
