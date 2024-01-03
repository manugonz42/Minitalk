/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:48:36 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/04 18:16:30 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cont;
	char	*cast;

	cast = (char *)s;
	cont = 0;
	while (cast[cont])
	{
		if (cast[cont] == c)
			return (cast + cont);
		cont++;
	}
	if (c == '\0')
		return (cast + cont);
	return (NULL);
}
