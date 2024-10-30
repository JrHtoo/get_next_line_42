/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:55:05 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/09/10 15:57:30 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;

	if (!s)
		return (NULL);
	i = 0;
	chr = (char)c;
	while (s[i])
	{
		if (chr == s[i])
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == chr)
		return ((char *)(s + i));
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s2));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	tmp = str;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*cpy;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len && s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		s_len;
	int		sub_len;
	int		i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (s_len - start > len)
		sub_len = len;
	else
		sub_len = s_len - start;
	substr = malloc(sub_len + 1);
	if (!substr)
		return (0);
	i = 0;
	while (i < sub_len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
