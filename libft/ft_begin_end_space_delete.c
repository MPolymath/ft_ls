/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_end_space_delete.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 06:18:55 by mdiouf            #+#    #+#             */
/*   Updated: 2014/04/14 11:30:36 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_begin_end_space_delete(char const *s)
{
	int		i;
	int		j;
	int		lastletter;
	char	*buffer;

	j = ft_index_firstalnum(s);
	lastletter = ft_index_lastalnum(s);
	i = 0;
	buffer = (char*)s;
	while (j <= lastletter)
	{
		buffer[i] = s[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
	return (buffer);
}
