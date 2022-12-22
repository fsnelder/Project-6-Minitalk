/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 10:37:59 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/02/11 10:38:10 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		count += write (1, "-", 1);
		i *= -1;
	}
	if (i > 9)
		count += ft_putnbr(i / 10);
	i = i % 10 + '0';
	count += write (1, &i, 1);
	return (count);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			negpos;

	i = 0;
	num = 0;
	negpos = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negpos = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}	
	return (num * negpos);
}
