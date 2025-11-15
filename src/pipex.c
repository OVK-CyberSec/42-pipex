/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:28:05 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/14 22:04:58 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_absolute_or_relative(char **s_cmd, char **env)
{
	if (access(s_cmd[0], F_OK | X_OK) == 0)
	{
		execve(s_cmd[0], s_cmd, env);
		perror("pipex");
	}
	else
	{
		ft_putstr_fd("pipex: no such 	file or permission denied: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
	}
	ft_free_tab(s_cmd);
	exit(127);
}

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd || !s_cmd[0])
	{
		ft_putstr_fd("pipex: invalid command\n", 2);
		exit(1);
	}
	if (ft_strchr(s_cmd[0], '/'))
		exec_absolute_or_relative(s_cmd, env);
	path = get_path(s_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(127);
	}
	execve(path, s_cmd, env);
	perror("pipex");
	ft_free_tab(s_cmd);
	free(path);
	exit(127);
}

void	child(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	p_fd[2];
	int	pid1;
	int	pid2;

	if (pipe(p_fd) == -1 || !check_files(ac, av) || !check_commands(av, env))
		exit(1);
	pid1 = fork();
	if (pid1 == 0)
		child(av, p_fd, env);
	pid2 = fork();
	if (pid2 == 0)
		parent(av, p_fd, env);
	else
	{
		close(p_fd[0]);
		close(p_fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
