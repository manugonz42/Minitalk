/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:42:33 by manugonz          #+#    #+#             */
/*   Updated: 2023/10/21 16:42:34 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_check_len_recived(t_protocol *t_server)
{
	if (t_server->bits == (sizeof(int) * 8) && t_server->flag == 0)
	{
		t_server->flag = 1;
		ft_putstr_fd ("\e[92mreceived length = [", STDOUT_FILENO);
		ft_putnbr_fd (t_server->data, STDOUT_FILENO);
		ft_putstr_fd ("]\n\e[0m", STDOUT_FILENO);
		t_server->message = malloc(sizeof(char) * (t_server->data + 1));
		if (!t_server->message)
		{
			ft_putstr_fd ("\e[31mError: \e[32m failed allocating \
			 memory. \e[0m\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		t_server->message[t_server->data] = '\0';
		t_server->bits = 0;
	}
}

void	ft_check_str_recived(t_protocol *t_server, int *i, pid_t client_pid)
{
	if (t_server->bits == (sizeof(char) * 8) && t_server->flag == 1)
	{
		t_server->message[*i] = t_server->data;
		(*i)++;
		if (t_server->data == '\0')
		{
			ft_putstr_fd("\e[92mreceived message = [", STDOUT_FILENO);
			ft_putstr_fd(t_server->message, STDOUT_FILENO);
			ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
			free(t_server->message);
			t_server->message = NULL;
			t_server->flag = 0;
			*i = 0;
			ft_send_bit(client_pid, 1, 0);
		}
		t_server->bits = 0;
	}
}
	/*ft_putstr_fd("\e[92mi = ", STDOUT_FILENO);
	ft_putnbr_fd(i, STDOUT_FILENO);
	ft_putstr_fd("\e[92m, server.bits = ", STDOUT_FILENO);
	ft_putnbr_fd(t_server.bits, STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);*/

void	ft_server_handler(int signal, siginfo_t *info, void *context)
{
	static t_protocol	t_server;	
	static int			i;

	usleep (100);
	(void)context;
	(void)info;
	if (t_server.bits == 0)
		t_server.data = 0;
	if (signal == SIGUSR2 && t_server.flag == 0)
		t_server.data |= 1 << ((sizeof(int) * 8) - 1 - t_server.bits);
	if (signal == SIGUSR2 && t_server.flag == 1)
		t_server.data |= 1 << ((sizeof(char) * 8) - 1 - t_server.bits);
	t_server.bits++;
	ft_check_len_recived (&t_server);
	ft_check_str_recived (&t_server, &i, info->si_pid);
	ft_send_bit (info->si_pid, 0, 0);
}
//in sa_flags '|' activate both, activate bits of both variables.

int	main(void)
{
	struct sigaction	sa_server;

	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_sigaction = ft_server_handler;
	sa_server.sa_flags = SA_SIGINFO | SA_RESTART;
	ft_configure_sigaction(&sa_server);
	ft_putstr_fd("\e[92mserver [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
