/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:28:10 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/07 22:49:15 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

int		open_file(char *file, int n);
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	exec(char *cmd, char **env);
void	ft_free_tab(char **tab);
void	exit_handler(int n_exit);
int		check_args_order(int ac, char **av, char **env);
int		check_commands(char **av, char **env);
int		check_files(int ac, char **av);
int		is_valid_absolute_path(char *path);
int		is_valid_command(char *cmd, char **env);

#endif
