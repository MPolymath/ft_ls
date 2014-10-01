/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:25:15 by mdiouf            #+#    #+#             */
/*   Updated: 2014/04/14 11:26:54 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptc;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ptc = (char*)&s[i];
			return (ptc);
		}
		i++;
	}
	if (c == '\0')
	{
		ptc = (char*)&s[i];
		return (ptc);
	}
	return (NULL);
}
