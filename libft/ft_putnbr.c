/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:09:57 by mdiouf            #+#    #+#             */
/*   Updated: 2014/04/14 10:03:23 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int i)
{
	static int	n = 0;

	if (i < 0)
	{
		i = -i;
		n = 1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		if (n == 1)
		{
			ft_putchar('-');
			n = 0;
		}
		ft_putchar(48 + i);
	}
}
