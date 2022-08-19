/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdr@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:28:54 by microdri          #+#    #+#             */
/*   Updated: 2022/08/19 14:45:32 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	size_len;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	size_len = ft_strlen(s);
	if (size_len < len)
		len = size_len;	
	temp = malloc((len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if(i >= start && j < len)
			temp[j++] = s[i];
	}
	temp[j] = '\0';
	return (temp);
}
