/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 22:59:12 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/01 00:27:19 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			odr_prnt_r1(t_dir **vars, int **argc)
{
	while ((*vars)->files[(*vars)->i].nme != '\0')
		((*vars)->i)++;
	((*vars)->i)--;
	while (((*vars)->i) != -1)
	{
		ft_putstr((*vars)->files[(*vars)->i].nme);
		ft_putstr("\n");
		((*vars)->i)--;
		((*vars)->j)++;
	}
	(**argc)--;
}

void			odr_prnt_r0(t_dir **vars)
{
	while ((*vars)->files[(*vars)->i].nme != '\0')
	{
		ft_putstr((*vars)->files[(*vars)->i].nme);
		ft_putstr("\n");
		((*vars)->i)++;
		((*vars)->j)++;
	}
	((*vars)->k)++;
}

void			order_print_files(t_dir *vars, int *argc, int r)
{
	if (vars->dir == NULL)
	{
		(vars->k)++;
		return ;
	}
	order_files(&(vars->files));
	(vars->i) = 0;
	if (r == 1)
		odr_prnt_r1(&vars, &argc);
	else if (r == 0)
		odr_prnt_r0(&vars);
	if ((vars->j) == 3)
	{
		ft_putstr("\n");
		(vars->j) = 0;
	}
	if (vars->files[0].nme != '\0')
		ft_putstr("\n");
	(vars->i) = 0;
	if (vars->dir != NULL)
		closedir(vars->dir);
}

void			ls_init(t_dir *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->k = 0;
}

void			ft_ls_chck_lst(t_dir *vars)
{
	while ((vars->files)[vars->i].nme != '\0')
		(vars->i)++;
}
