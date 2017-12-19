/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:11 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 18:37:11 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_n;
	unsigned char	*src_n;

	dst_n = (unsigned char *)dst;
	src_n = (unsigned char *)src;
	if (len == 0)
	{
		return ((char *)dst_n);
	}
	i = 0;
	while (src_n[i] != '\0' && (i < len))
	{
		dst_n[i] = src_n[i];
		i++;
	}
	while (i < len)
	{
		dst_n[i] = '\0';
		i++;
	}
	return ((char*)dst_n);
}
