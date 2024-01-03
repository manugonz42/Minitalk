/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:42:42 by manugonz          #+#    #+#             */
/*   Updated: 2023/10/21 16:42:43 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_configure_sigaction(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## Error \e[33m could \
		not setup SIGUSR1 \e[31m##\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## Error \e[33m could \
		not setup SIGUSR2 \e[31m##\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	ft_send_bit(pid_t pid, char bit, char flag_to_pause)
{
	(void)pid;
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending SIGUSR1 ##\n\e[0m",
				STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending SIGUSR2 ##\n\e[0m",
				STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	if (flag_to_pause != 0)
		pause();
}

void	ft_send_int(pid_t pid, int num)
{
	int		shift;
	char	bit;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		bit = (num >> shift) & 1;
		ft_send_bit(pid, bit, 1);
		shift--;
	}
}

void	ft_send_char(pid_t pid, char c)
{
	int		shift;
	char	bit;

	shift = (sizeof(char) * 8) - 1;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		ft_send_bit(pid, bit, 1);
		shift--;
	}
}
