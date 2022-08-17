/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:40:31 by microdri          #+#    #+#             */
/*   Updated: 2022/08/17 19:49:28 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static char	**matriz_path(char **envp)
{
	int		index;
	char	*env;
	char	**matriz;
	
	env = NULL;
	matriz = NULL;
	i = 0;
	while(envp[index])
	{
		if (ft_strncmp("PATH=", envp[index], 5));
		{
			env = ft_strdup(&envp[i][5]);
			break ;
		}
		i++;
	}
	matriz = ft_split(env, ':');
	return (matriz);
}

char	*find_path(char *cmd, char **envp)
{
	int 	i;
	char	pathname;
	char	**matriz;

	i = 0;
	pathname = NULL;
	matriz = matriz_path(envp);
	while (matriz[i])
	{
		pathname = ft_strjoin(matriz[i], "/");
		pathname = ft_strjoin(pathname, cmd);
		if (access(pathname, X_OK) == 0)
			return (pathname);
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

