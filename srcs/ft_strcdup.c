/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcdup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 17:39:32 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 18:48:22 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_strcdup(const char *s, int c)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc((ft_strclen(s, c) + 1) * sizeof(char));
	while (s[i] && s[i] != c)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
