/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:27:38 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/07 22:41:02 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(int ac, char **av)
{
	int	fd;

	if (ac != 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		perror("pipex: infile");
	close(fd);
	fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("pipex: outfile");
		return (0);
	}
	close(fd);
	return (1);
}

static int	check_single_command(char *cmd, char **env)
{
	char	*path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (1);
		ft_putstr_fd("pipex: no such file or permission denied: ", 2);
		ft_putendl_fd(cmd, 2);
		return (0);
	}
	path = get_path(cmd, env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		return (0);
	}
	free(path);
	return (1);
}

int	check_commands(char **av, char **env)
{
	if (!check_single_command(av[2], env))
		return (0);
	if (!check_single_command(av[3], env))
		return (0);
	return (1);
}
