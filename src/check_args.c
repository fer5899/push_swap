/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:50:17 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/21 17:39:48 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_int_digits(char *str)
{
	int	dig;

	dig = 0;
	if ((*str == '-' || *str == '+'))
		str++;
	while (*str == '0' && *str != '\0')
		str++;
	while (str[dig] != '\0' && str[dig] != '.')
		dig++;
	if (dig == 0)
		return (1);
	return (dig);
}

int	check_limit(char *str, int neg)
{
	char	*limit;
	int		i;

	i = 0;
	if (neg)
		limit = "2147483648";
	else
		limit = "2147483647";
	while (i < 10)
	{
		if (str[i] > limit[i])
			return (0);
		if (str[i] < limit[i])
			break ;
		i++;
	}
	return (1);
}

int	is_int_size(char *str)
{
	int		dig;
	int		neg;

	dig = get_int_digits(str);
	neg = 0;
	if (*str == '-')
		neg = 1;
	if ((*str == '-' || *str == '+'))
		str++;
	if (dig > 10)
		return (0);
	else if (dig < 10)
		return (1);
	if (check_limit(str, neg))
		return (1);
	return (0);
}

int	is_int(char *str)
{
	int	point;
	int	i;

	point = 0;
	i = 0;
	if ((*str == '-' || *str == '+'))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && !point)
			point = 1;
		else
		{
			if (!(ft_isdigit(str[i])))
				return (0);
			if (point && str[i] != '0')
				return (0);
		}
		i++;
	}
	if (((str[0] == '-' || str[0] == '+') && i == 1) || i == 0)
		return (0);
	return (is_int_size(str));
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
