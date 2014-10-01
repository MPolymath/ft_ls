/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:55:19 by mdiouf            #+#    #+#             */
/*   Updated: 2014/04/14 11:26:09 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*s1cpy;
	int		lengths1;

	i = 0;
	lengths1 = ft_strlen(s1) + 1;
	s1cpy = malloc(lengths1 * (sizeof(char)));
	if (s1cpy == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		s1cpy[i] = s1[i];
		i++;
	}
	s1cpy[i] = '\0';
	return (s1cpy);
}
