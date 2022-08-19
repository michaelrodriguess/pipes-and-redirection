/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:40:31 by microdri          #+#    #+#             */
/*   Updated: 2022/08/19 19:38:29 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**matriz_path(char **envp)
{
	int		index;
	char	*env;
	char	**matriz;
	
	env = NULL;
	matriz = NULL;
	index = 0;
	while(envp[index])
	{
		if (ft_strncmp("PATH=", envp[index], 5))
		{
			env = ft_strdup(&envp[index][5]);
			break ;
		}
		index++;
	}
	matriz = ft_split(env, ':');
	return (matriz);
}

char	*find_path(char **cmd, char **envp)
{
	int 	i;
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
		if (access(path_temp, X_OK) == 0)
			return (path_temp);
		else
			free(pathname);	
		i++;
	}
	return (NULL);
}

char	**split_args(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	return (args);
}

