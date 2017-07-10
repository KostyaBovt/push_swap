/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:51:40 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:51:40 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			check_digits(int stack_i, int argc, char **argv)
{
	int			i;
	int			j;

	j = stack_i - 1;
	while (++j < argc)
	{
		i = -1;
		if (argv[j][0] == '-' || argv[j][0] == '+')
			i++;
		while (argv[j][++i])
			if (!ft_isdigit(argv[j][i]))
				return (error_return0("stack contains not integer arguments"));
		if (over_int(argv[j]))
			return (error_return0("stack contains too long integer values"));
	}
	return (1);
}

int			over_int(char *argv)
{
	long int	num;

	if (ft_strlen(argv) > 11)
		return (1);
	num = ft_atoi_long(argv);
	if (num > 2147483647)
		return (1);
	if (num < -2147483648)
		return (1);
	return (0);
}

int			isspc(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' \
	|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

long int	ft_atoi_long(char *argv)
{
	int			i;
	int			neg_flag;
	long int	num;

	i = 0;
	neg_flag = 0;
	num = 0;
	while (isspc(argv[i]))
		i++;
	if (argv[i] == 45)
		neg_flag = 1;
	if (argv[i] == 45 || argv[i] == 43)
		i++;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		num = num * 10;
		num = num + ((long int)argv[i] - 48);
		i++;
	}
	return (neg_flag == 1 ? -num : num);
}
