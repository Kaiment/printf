/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 12:04:25 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 16:27:06 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <stdio.h>

char	*free_n_join(char **f_str, char **converted)
{
	char	*tmp1;
	char	*tmp2;
	char	*new;

	tmp1 = *f_str;
	tmp2 = *converted;
	new = ft_strjoin(*f_str, *converted);
	free(tmp1);
	free(tmp2);
	return (new);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			nb_char;
	char		*f_str;
	char		*tmp;

	nb_char = 0;
	va_start(ap, format);
	f_str = ft_memalloc(1);
	while (*format)
	{
		tmp = ft_strcdup(format, '%');
		ft_putstr(tmp);
		nb_char += ft_strlen(tmp);
		format += ft_strclen(format, '%');
		if (!*format)
			break;
		free(tmp);
		tmp = ft_conversion(&format, &ap);
		ft_putstr(tmp);
		nb_char += ft_strlen(tmp);
		free(tmp);
	}
	va_end(ap);
	return (nb_char);
}
