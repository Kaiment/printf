/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wchart_to_str.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 11:05:18 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 12:18:12 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static unsigned int		wcharlen(unsigned int *characters)
{
	unsigned int	len;

	len = 0;
	while (*characters)
	{
		if (*characters >= 1 && *characters <= 127)
			len += 1;
		else if (*characters <= 2047)
			len += 2;
		else if (*characters <= 65535)
			len += 2;
		else if (*characters <= 2097151)
			len += 3;
		else
			return (0);
		characters += 1;
	}
	return (len);
}

char					*ft_wchart_to_str(unsigned int *characters)
{
	char			*str;
	char			*tmp;
	unsigned int	len;

	if (!(len = wcharlen(characters)))
		return (NULL);
	if (!(str = ft_memalloc((len + 1) * sizeof(char))))
		return (NULL);
	while (*characters)
	{
		tmp = ft_wint_to_str(*characters);
		ft_strcat(str, tmp);
		free(tmp);
	}
	return (str);
}
