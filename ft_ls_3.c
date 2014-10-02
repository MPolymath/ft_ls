/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 22:59:58 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/02 05:06:32 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	count_file_nbr(t_dir **vars)
{
	(*vars)->nbr_files = 0;
	while ((*vars)->dir != NULL && readdir((*vars)->dir))
		(*vars)->nbr_files++;
	if ((*vars)->dir != NULL)
	{
		closedir((*vars)->dir);
		(*vars)->dir = opendir((*vars)->path);
	}
}

void	ft_ls_r_init_loop(t_dir *vars, char **argv, int **argv_i, int *argc)
{
	int	i;

	i = 0;
	if (*argc > 1)
	{
		vars->path = ft_strdup((argv)[(*argv_i)[(*argc) - 2]]);
		while (vars->path[i] != '\0') // testing seg solve
			i++;
		if (vars->path[i - 1] != '/')
			vars->path = ft_strjoin(vars->path, "/");
		printf("var_path: %s\n", vars->path);
		vars->dir = opendir(vars->path);
	}
	else
	{
		vars->path = ft_strdup("./");
		vars->dir = opendir(vars->path);
	}
	if (vars->dir == NULL)
	{
		ft_putstr("ls: ");
		ft_putstr((argv)[(*argv_i)[*argc - 2]]);
		ft_putstr(": No such file or directory\n");
		ft_putstr("\n");
	}
	count_file_nbr(&vars);
	vars->files = (t_files*)malloc(sizeof(t_files) * vars->nbr_files);
}

void	ft_ls_init_loop(t_dir *vars, char **argv, int **argv_i)
{
	int i;

	i = 0;
	if (argv[(*argv_i)[vars->k]] != NULL)
	{
		vars->path = ft_strdup(argv[(*argv_i)[vars->k]]);
		while (vars->path[i]) // testing seg solve
			i++;
		if (vars->path[i - 1] != '/')
			vars->path = ft_strjoin(vars->path, "/");
		printf("var_path: %s\n", vars->path);
		vars->dir = opendir(vars->path);
	}
	else
	{
		vars->path = ft_strdup("./");
		vars->dir = opendir(vars->path);
	}
	if (vars->dir == NULL)
	{
		ft_putstr("ls: ");
		ft_putstr(argv[(*argv_i)[vars->k]]);
		ft_putstr(": No such file or directory\n");
		ft_putstr("\n");
	}
	count_file_nbr(&vars);
	vars->files = (t_files*)malloc(sizeof(t_files) * vars->nbr_files);
}

void	ft_ls_none(char **argv, int *argv_i, int argc, int a) // added for noparam handling
{
	t_dir			vars;

	ls_init(&vars);
	ft_ls_init_loop(&vars, argv, &argv_i);
	while (vars.dir != NULL && (vars.entry = readdir(vars.dir)))
	{
		if (a == 0 && (vars.entry)->d_name[0] != '.')
		{
			ft_ls_chck_lst(&vars);
			vars.files[vars.i].nme = (char*)malloc(sizeof(char)
									* (ft_strlen(vars.entry->d_name) + 1));
			vars.files[vars.i].nme = (vars.entry)->d_name;
			vars.files[vars.i].path = ft_strjoin(vars.path, vars.files[vars.i].nme);
		    stat(vars.files[vars.i].path , &(vars.files[vars.i].stats));
		}
		else if (a == 1)
		{
			ft_ls_chck_lst(&vars);
			vars.files[vars.i].nme = (char*)malloc(sizeof(char)
									* (ft_strlen(vars.entry->d_name) + 1));
			vars.files[vars.i].nme = (vars.entry)->d_name;
			vars.files[vars.i].path = ft_strjoin(vars.path, vars.files[vars.i].nme);
			stat(vars.files[vars.i].path , &(vars.files[vars.i].stats));
		}
	}
	order_print_files(&vars, &argc, 0);
	printf("test6\n");
	free(vars.path);
}

void	ft_ls_l_none(char **argv, int *argv_i, int argc, int a) // added for noparam handling
{
	t_dir			vars;

	vars.l = 1;
	ls_init(&vars);
	ft_ls_init_loop(&vars, argv, &argv_i);
	while (vars.dir != NULL && (vars.entry = readdir(vars.dir)))
	{
		if (a == 0 && (vars.entry)->d_name[0] != '.')
		{
			ft_ls_chck_lst(&vars);
			vars.files[vars.i].nme = (char*)malloc(sizeof(char)
									* (ft_strlen(vars.entry->d_name) + 1));
			vars.files[vars.i].nme = (vars.entry)->d_name;
			vars.files[vars.i].path = ft_strjoin(vars.path, vars.files[vars.i].nme);
		    stat(vars.files[vars.i].path , &(vars.files[vars.i].stats));
		}
		else if (a == 1)
		{
			ft_ls_chck_lst(&vars);
			vars.files[vars.i].nme = (char*)malloc(sizeof(char)
									* (ft_strlen(vars.entry->d_name) + 1));
			vars.files[vars.i].nme = (vars.entry)->d_name;
			vars.files[vars.i].path = ft_strjoin(vars.path, vars.files[vars.i].nme);
			stat(vars.files[vars.i].path , &(vars.files[vars.i].stats));
		}
	}
	order_print_files(&vars, &argc, 0);
	printf("test6\n");
	free(vars.path);
}

void	ft_ls(char **argv, int *argv_i, int argc, int a)
{
	t_dir			vars;

	if (argc == 1)
		ft_ls_none(argv, argv_i, argc, a);
	ls_init(&vars);
	while (vars.k != (argc - 1))
	{
		ft_ls_init_loop(&vars, argv, &argv_i);
		while (vars.dir != NULL && (vars.entry = readdir(vars.dir)))
		{
			if (a == 0 && (vars.entry)->d_name[0] != '.')
			{
				ft_ls_chck_lst(&vars);
				vars.files[vars.i].nme = (char*)malloc(sizeof(char)
										* (ft_strlen(vars.entry->d_name) + 1));
				vars.files[vars.i].nme = (vars.entry)->d_name;
				vars.files[vars.i].path = ft_strjoin(vars.path, vars.files[vars.i].nme);
			    stat(vars.files[vars.i].path , &(vars.files[vars.i].stats));
			}
			else if (a == 1)
			{
				ft_ls_chck_lst(&vars);
				vars.files[vars.i].nme = (char*)malloc(sizeof(char)
										* (ft_strlen(vars.entry->d_name) + 1));
				vars.files[vars.i].nme = (vars.entry)->d_name;
				vars.files[vars.i].path = ft_strjoin(vars.path, vars.files[vars.i].nme);
			    stat(vars.files[vars.i].path , &(vars.files[vars.i].stats));
			}
		}
		order_print_files(&vars, &argc, 0);
		free(vars.path);
	}
}

void	ft_ls_l(char **argv, int *argv_i, int argc)
{
	t_dir	vars;

	vars.l = 1;
	if (argc == 1)
		ft_ls_l_none(argv, argv_i, argc, 1);
	ls_init(&vars);
	while (vars.k != (argc - 1))
	{
		ft_ls_init_loop(&vars, argv, &argv_i);
		while (vars.dir != NULL && (vars.entry = readdir(vars.dir)))
		{
				ft_ls_chck_lst(&vars);
				vars.files[vars.i].nme = (char*)malloc(sizeof(char)
										* (ft_strlen(vars.entry->d_name) + 1));
				vars.files[vars.i].nme = (vars.entry)->d_name;
				vars.files[vars.i].path = ft_strjoin(vars.path, vars.files[vars.i].nme);
			    stat(vars.files[vars.i].path , &(vars.files[vars.i].stats));
		}
		order_print_files(&vars, &argc, 0);
		free(vars.path);
	}
}

void	ft_ls_r_none(char **argv, int *argv_i, int argc, int a)
{
	t_dir			vars;

	ls_init(&vars);
	ft_ls_r_init_loop(&vars, argv, &argv_i, &argc);
	while (vars.dir != NULL && (vars.entry = readdir(vars.dir)))
	{
		if (a == 0 && (vars.entry)->d_name[0] != '.')
		{
			ft_ls_chck_lst(&vars);
			vars.files[vars.i].nme = (char*)malloc(sizeof(char)
									* (ft_strlen(vars.entry->d_name) + 1));
			vars.files[vars.i].nme = (vars.entry)->d_name;
		}
		else if (a == 1)
		{
			ft_ls_chck_lst(&vars);
			vars.files[vars.i].nme = (char*)malloc(sizeof(char)
									* (ft_strlen(vars.entry->d_name) + 1));
			vars.files[vars.i].nme = (vars.entry)->d_name;
		}
	}
	order_print_files(&vars, &argc, 1);
	free(vars.path);
}

void	ft_ls_r(char **argv, int *argv_i, int argc, int a)
{
	t_dir			vars;

	if (argc == 1)
		ft_ls_r_none(argv, argv_i, argc, a);
	ls_init(&vars);
	while ((argc - 1) != 0)
	{
		ft_ls_r_init_loop(&vars, argv, &argv_i, &argc);
		while (vars.dir != NULL && (vars.entry = readdir(vars.dir)))
		{
			if (a == 0 && (vars.entry)->d_name[0] != '.')
			{
				ft_ls_chck_lst(&vars);
				vars.files[vars.i].nme = (char*)malloc(sizeof(char)
										* (ft_strlen(vars.entry->d_name) + 1));
				vars.files[vars.i].nme = (vars.entry)->d_name;
			}
			else if (a == 1)
			{
				ft_ls_chck_lst(&vars);
				vars.files[vars.i].nme = (char*)malloc(sizeof(char)
										* (ft_strlen(vars.entry->d_name) + 1));
				vars.files[vars.i].nme = (vars.entry)->d_name;
			}
		}
		order_print_files(&vars, &argc, 1);
		free(vars.path);
	}
}

void	flip_argv(char **argv, int *argc)
{
	int	i;

	i = 1;
	*argc = *argc - 1;
	while (argv[i + 1] != '\0')
	{
		argv[i] = argv[i + 1];
		i++;
	}
	if (argv[i + 1] == '\0')
		argv[i] = '\0';
}
