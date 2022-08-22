/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:17:42 by microdri          #+#    #+#             */
/*   Updated: 2022/08/22 18:24:24 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	.\pipex infile cat rev outfile
//	   [0]   [1]   [2] [3]   [4]
#include "pipex.h"

void	process_child1(int *fd, char **argv, char **envp)
{
	int		fd_arq;
	char	*pathname;
	char	**args;

	args = split_args(argv[2]);
	pathname = find_path(args, envp);
	close(fd[0]);
	fd_arq = open(argv[1], O_RDONLY);
	dup2(fd[1], 1);
	dup2(fd_arq, 0);
	close(fd_arq);
	close(fd[1]);
	execve(pathname, args, NULL);
}

void	process_child2(int *fd, char **argv, char **envp)
{
	int		fd_arq;
	char	*pathname;
	char	**args;

	args = split_args(argv[3]);
	pathname = find_path(args, envp);
	close(fd[1]);
	fd_arq = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	dup2(fd[0], 0);
	dup2(fd_arq, 1);
	close(fd[0]);
	execve(pathname, args, NULL);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	(void)argc;
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return (2);
	else if (pid1 == 0)
		process_child1(fd, argv, env);
	pid2 = fork();
	if (pid2 == -1)
		return (2);
	else if (pid2 == 0)
		process_child2(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
