/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 10:36:52 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/02/11 10:49:57 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	handle_sigusr_to_string(int sig);
void	*convert_sigusr_to_binary(int pid, char *s);
int		ft_putnbr(long int i);
int		ft_atoi(const char *str);

#endif
