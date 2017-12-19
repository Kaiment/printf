/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:08 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 18:37:08 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	value;
	char	*n_s;

	value = c;
	n_s = (char *)s;
	while (*n_s)
	{
		if (*n_s == c)
			return (n_s);
		n_s++;
	}
	if (c == '\0')
		return (n_s);
	return (NULL);
}
