/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 10:37:38 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/03/29 13:58:04 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*convert_sigusr_to_binary(int pid, char *s)
{	
	size_t	i;
	int		bit;
	size_t	somenumber;

	i = 0;
	while (s[i] != '\0')
	{
		bit = 7;
		while (bit >= 0)
		{
			somenumber = (s[i] >> bit) & 1;
			if (somenumber == 0)
				kill(pid, SIGUSR1);
			if (somenumber == 1)
				kill(pid, SIGUSR2);
			bit--;
			usleep(100);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		convert_sigusr_to_binary(ft_atoi(argv[1]), argv[2]);
	else
		write(1, "enter [pid] [message]\n", 22);
	return (0);
}
