/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:19:16 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/24 20:55:32 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../includes/minitalk_utils.h"

int	is_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (-1);
}

int	check_long(int number, char n, int sign)
{
	int	is_long;

	is_long = 1;
	if ((unsigned long) number * 10 + (n - '0')
		> 9223372036854775807 && sign == 1)
		is_long = -1;
	else if ((unsigned long) number * 10 + (n - '0')
		> 9223372036854775807 && sign == -1)
		is_long = 0;
	return (is_long);
}

void	skip_sign_and_spaces(const char *str, int *index, int *sign)
{
	while (str[(*index)] != '\0' && is_whitespace(str[(*index)]) == 1)
		(*index)++;
	if (str[(*index)] == '-' || str[(*index)] == '+')
	{
		if (str[(*index)] == '-')
			(*sign) = -1;
		(*index)++;
	}
}

int	ft_atoi(const char *str)
{
	int			index;
	int			sign;
	long long	number;
	int			is_long;

	sign = 1;
	index = 0;
	number = 0;
	is_long = 0;
	skip_sign_and_spaces(str, &index, &sign);
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		is_long = check_long(number, str[index], sign);
		if (is_long != 1)
			return (is_long);
		number *= 10;
		number += str[index] - 48;
		index++;
	}
	return (number * sign);
}