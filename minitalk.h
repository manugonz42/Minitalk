/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:43:14 by manugonz          #+#    #+#             */
/*   Updated: 2023/10/21 16:43:20 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "libft/libft.h"

void	ft_configure_sigaction(struct sigaction *sa);
void	ft_send_bit(pid_t pid, char bit, char flag_to_pause);
void	ft_send_int(pid_t pid, int num);
void	ft_send_char(pid_t pid, char c);

typedef struct s_protocol
{
	int		bits;
	int		data;
	int		flag;
	char	*message;
}	t_protocol;

#endif
