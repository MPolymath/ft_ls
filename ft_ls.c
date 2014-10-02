/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 14:27:23 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/02 03:45:05 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*join_new_path(char *path, char *file_name)
{
	char	*new_path;

	new_path = ft_strjoin(path, "/");
	new_path = ft_strjoin(new_path, file_name);
	return (new_path);
}

void		main_extension(char **argv, int *a, int *l, int **tbl_argv_i, int *argc)
{
	if (ft_strcmp(argv[1], "-a") == 0)
		*a = 1;
	else
		*a = 0;
	if (ft_strcmp(argv[1], "-l") == 0)
		*l = 1;
	else
		*l = 0;
	flip_argv(argv, argc);
	*tbl_argv_i = cr_tb_hash(*argc, argv);
	if (*a == 1)
		ft_ls(argv, *tbl_argv_i, *argc, 1);
	else if (*l == 1)
		ft_ls_l(argv, *tbl_argv_i, *argc);
	else
		ft_ls_r(argv, *tbl_argv_i, *argc, 0);
}

int			main(int argc, char **argv)
{
	int		a;
	int		l;
	int		*tbl_argv_i;

	a = 0;
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-a") == 0 || ft_strcmp(argv[1], "-r") == 0 || ft_strcmp(argv[1], "-l") == 0)
			main_extension(argv, &a, &l, &tbl_argv_i, &argc);
		else if (argv[1][0] == '-')
		{
			ft_putstr("Not supported\n");
			return (0);
		}
		else
		{
			tbl_argv_i = cr_tb_hash(argc, argv);
			ft_ls(argv, tbl_argv_i, argc, 0);
		}
	}
	else
	{
			tbl_argv_i = cr_tb_hash(argc, argv);
			ft_ls(argv, tbl_argv_i, argc, 0);
	}
	return (1);
}
