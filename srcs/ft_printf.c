/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 12:04:25 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 10:08:43 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

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
	char		*tmp;

	nb_char = 0;
	va_start(ap, format);
	while (*format)
	{
		tmp = ft_strcdup(format, '%');
		ft_putstr(tmp);
		nb_char += ft_strlen(tmp);
		format += ft_strclen(format, '%');
		if (!*format)
			break ;
		free(tmp);
		if (!(tmp = ft_conversion(&format, &ap)))
			continue ;
		ft_putstr(tmp);
		nb_char += ft_strlen(tmp);
		free(tmp);
	}
	va_end(ap);
	return (nb_char);
}
