/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:45 by manugonz          #+#    #+#             */
/*   Updated: 2023/02/20 16:50:47 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*r;

	j = start;
	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	r = (char *)malloc(sizeof(*s) * (len + 1));
	if (!r)
		return (NULL);
	while (i < len && s[j])
	{
		r[i] = s[j];
		j++;
		i++;
	}
	r[i] = 0;
	return (r);
}
