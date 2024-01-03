/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:42:21 by manugonz          #+#    #+#             */
/*   Updated: 2023/10/21 16:42:22 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error_message(char *message)
{
	ft_putstr_fd("\e[31m## ERROR: \e[33m", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putendl_fd("\e[31m ##\e[0m", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

static void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("\e[33m > Signal received\n\e[0m",
			STDOUT_FILENO);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("\e[92m > end signal received\n\e[0m", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	ft_check_params(int c, const char **v)
{
	int	i;

	i = -1;
	if (c != 3)
		ft_error_message("Wrong number of parameters");
	else
	{
		while (v[1][++i])
		{
			if (v[1][i] < '0' || v[1][i] > '9')
				ft_error_message("PID should be composed solely of numbers");
		}
	}
	if (kill(ft_atoi(v[1]), 0) < 0)
		ft_error_message("Invalid PID, check process ID again");
}

int	main(int argc, char const *argv[])
{
	struct sigaction	s_client;
	int					i;
	int					pid;

	ft_check_params(argc, argv);
	pid = ft_atoi (argv[1]);
	i = -1;
	sigemptyset (&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = client_handler;
	ft_configure_sigaction (&s_client);
	ft_send_int (pid, ft_strlen(argv[2]));
	while (argv[2][++i])
		ft_send_char(pid, argv[2][i]);
	ft_send_char (pid, '\0');
	return (EXIT_SUCCESS);
}
