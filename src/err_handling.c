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
	{
		perror("pipex: infile");
		return (0);
	}
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

int	check_commands(char **av, char **env)
{
	char	*path1;
	char	*path2;

	path1 = get_path(av[2], env);
	path2 = get_path(av[3], env);
	if (!path1 || access(path1, F_OK | X_OK) != 0)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(av[2], 2);
		free(path1);
		free(path2);
		return (0);
	}
	if (!path2 || access(path2, F_OK | X_OK) != 0)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(av[3], 2);
		free(path1);
		free(path2);
		return (0);
	}
	free(path1);
	free(path2);
	return (1);
}