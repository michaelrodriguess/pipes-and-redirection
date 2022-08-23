/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:17:42 by microdri          #+#    #+#             */
/*   Updated: 2022/08/23 17:24:03 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	.\pipex infile cat rev outfile
//	   [0]   [1]   [2] [3]   [4]
#include "pipex.h"

void	message_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	process_child1(int *pipe_fd, char **argv, char **envp)
{
	int		fd_arq;
	char	*pathname;
	char	**args;

	args = split_args(argv[2]);
	pathname = find_path(args, envp);
	close(pipe_fd[0]);
	fd_arq = open(argv[1], O_RDONLY);
	if (fd_arq == -1)
		message_error("Error with opening");
	dup2(pipe_fd[1], 1);
	dup2(fd_arq, 0);
	close(pipe_fd[1]);
	if ((execve(pathname, args, NULL) == -1))
		message_error("Error with first command");
}

void	process_child2(int *pipe_fd, char **argv, char **envp)
{
	int		fd_arq;
	char	*pathname;
	char	**args;

	args = split_args(argv[3]);
	pathname = find_path(args, envp);
	close(pipe_fd[1]);
	fd_arq = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_arq == -1)
		message_error("Error with opening or creating file");
	dup2(pipe_fd[0], 0);
	dup2(fd_arq, 1);
	close(pipe_fd[0]);
	if ((execve(pathname, args, NULL)) == -1)
		message_error("Error with second command");
}

int	main(int argc, char **argv, char **env)
{
	int	pipefd[2];
	int	pid1;
	int	pid2;

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			message_error("Error with Pipe");
		pid1 = fork();
		if (pid1 == -1)
			message_error("Error with First Proccess");
		else if (pid1 == 0)
			process_child1(pipefd, argv, env);
		pid2 = fork();
		if (pid2 == -1)
			message_error("Error with Second Proccess");
		else if (pid2 == 0)
			process_child2(pipefd, argv, env);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		write(1, "Invalid Arguments", 18);
}
