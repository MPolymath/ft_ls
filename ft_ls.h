/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 15:30:58 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/04 01:12:11 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					FT_LS_H
# define				FT_LS_H
# include               "libft/libft.h"
# include				<dirent.h>
# include               <stdlib.h>
# include               <sys/types.h>
# include               <sys/stat.h>
# include               <unistd.h>
# include               <errno.h>
# include               <stdio.h>
# include               <string.h>
# include				<pwd.h>
# include				<grp.h>
# include				<time.h>

typedef struct			s_hash
{
	int					i;
	char				*argv;
}						t_hash;

typedef struct			s_main
{
	int					i;
	int					j;
	int					good;
	int					*argv_i;
	t_hash				temp;
}						t_main;

typedef	struct			s_files
{
	struct stat			stats;
	char				*path;
	char				*nme;
}						t_files;

typedef struct			s_main_ext
{
	int					a;
	int					l;
	int					*tbl_argv_i;
}						t_main_ext;

typedef struct			s_id
{
	struct passwd		*pass;
	struct group		*grp;
	char				*time;
}						t_id;

typedef struct			s_dir
{
	DIR					*dir;
	struct dirent		*entry;
	char				*path;
	int					l;
	int					i;
	int					j;
	int					k;
	int					valid;
	int					nbr_files;
	t_files				*files;
}						t_dir;

void					cpy_hash(t_hash *hash1, t_hash *hash2);
void					cr_tb_hash_init(t_main *vars, int argc,
						t_hash *tb_hash, char **argv);
void					cr_tb_hash_main(t_main *vars,
						int argc, t_hash *tb_hash);
int						*cr_tb_hash(int argc, char **argv);
void					order_files(t_files **files);
void					odr_prnt_r1(t_dir **vars, int **argc);
void					odr_prnt_r0(t_dir **vars);
void					order_print_files(t_dir *vars, int *argc, int r);
void					ft_print_rights(t_dir **vars, int i);
void					ft_print_rights2(t_dir **vars, int i, t_id *id_vars);
void					fill_path(t_dir **vars, char **argv,
									int **argv_i);
void					fill_path_r(t_dir **vars, char **argv,
									int **argv_i, int *argc);
void					ls_init(t_dir *vars);
void					ft_ls_chck_lst(t_dir *vars);
void					ft_ls_r_init_loop(t_dir *vars,
						char **argv, int **argv_i, int *argc);
void					ft_ls_init_loop(t_dir *vars,
						char **argv, int **argv_i);
void					ft_ls(char **argv, int *argv_i,
							  int argc, int a);
void					ft_ls_l(char **argv, int *argv_i, int argc);
void					ft_ls_r(char **argv,
						int *argv_i, int argc, int a);
void					ft_fix_time_str(char **time);
void					ft_fix_time_str2(char **time);
void					flip_argv(char **argv, int *argc);
int						main_argc(char **argv, t_main_ext *vars,
										int *argc);
void					main_extension(char **argv, t_main_ext *vars,
										int *argc);
void					set_extensions(char **argv, t_main_ext **vars,
										int *argc);
#endif

