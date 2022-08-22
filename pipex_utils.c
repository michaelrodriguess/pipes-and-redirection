/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:40:31 by microdri          #+#    #+#             */
/*   Updated: 2022/08/22 18:25:44 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**matriz_path(char **envp)
{
	int		index;
	char	**matriz;

	index = 0;
	matriz = NULL;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{	
			matriz = ft_split(&envp[index][5], ':');
			break ;
		}
		index++;
	}
	return (matriz);
}

char	*find_path(char **cmd, char **envp)
{
	int		i;
	char	*pathname;
	char	*path_temp;
	char	**matriz;

	i = 0;
	pathname = NULL;
	matriz = matriz_path(envp);
	while (matriz[i])
	{
		pathname = ft_strjoin(matriz[i], "/");
		path_temp = ft_strjoin(pathname, cmd[0]);
		free(pathname);
		if (access(path_temp, F_OK | X_OK) == 0)
			return (path_temp);
		free(path_temp);
		i++;
	}
	return (path_temp);
}

char	**split_args(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	return (args);
}
