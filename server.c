/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 10:37:01 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/03/29 14:52:49 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr_to_string(int sig)
{
	static unsigned char	somenumber = '\0';
	static size_t			count = 8;

	if (sig == 30)
		somenumber |= 0;
	if (sig == 31)
		somenumber |= 1;
	count--;
	if (count == 0)
	{
		count = 8;
		write(1, &somenumber, 1);
		somenumber = 0;
	}
	somenumber <<= 1;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, handle_sigusr_to_string);
	signal(SIGUSR2, handle_sigusr_to_string);
	while (1)
		sleep(1);
}
