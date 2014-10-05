/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 14:27:23 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/05 21:24:05 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			set_extensions(char **argv, t_main_ext **vars, int *argc)
{
	argc = argc;
	if (ft_strcmp(argv[1], "-a") == 0)
		(*vars)->a = 1;
	else
		(*vars)->a = 0;
	if (ft_strcmp(argv[1], "-l") == 0)
		(*vars)->l = 1;
	else
		(*vars)->l = 0;
}

void			add_slash(char **argv)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (argv[i] != '\0')
	{
		while (argv[i][j] != '\0')
			j++;
		if (argv[i][j - 1] != '/')
			argv[i] = ft_strjoin(argv[i], "/");
		j = 0;
		i++;
	}
}

void			main_extension(char **argv, t_main_ext *vars, int *argc)
{
	set_extensions(argv, &vars, argc);
	flip_argv(argv, argc);
	add_slash(argv);
	vars->tbl_argv_i = cr_tb_hash(*argc, argv);
	if (vars->a == 1)
		ft_ls(argv, vars->tbl_argv_i, *argc, 1);
	else if (vars->l == 1)
		ft_ls_l(argv, vars->tbl_argv_i, *argc);
	else
		ft_ls_r(argv, vars->tbl_argv_i, *argc, 0);
}

int				main_argc(char **argv, t_main_ext *vars, int *argc)
{
	if (ft_strcmp(argv[1], "-a") == 0 ||
		ft_strcmp(argv[1], "-r") == 0)
		main_extension(argv, vars, argc);
	else if (argv[1][0] == '-')
	{
		ft_putstr("Not supported\n");
		return (0);
	}
	else
	{
		vars->tbl_argv_i = cr_tb_hash(*argc, argv);
		ft_ls(argv, vars->tbl_argv_i, *argc, 0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_main_ext	vars;

	vars.a = 0;
	if (argc > 1)
	{
		if (main_argc(argv, &vars, &argc) == 0)
			return (0);
	}
	else
	{
		vars.tbl_argv_i = cr_tb_hash(argc, argv);
		ft_ls(argv, vars.tbl_argv_i, argc, 0);
	}
	return (1);
}
