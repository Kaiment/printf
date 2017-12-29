/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_proc_x.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 16:21:28 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 18:00:42 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static char		*hextoa(long n, t_param *spec)
{
	char	type;

	type = spec->type;
	if (type == 'x' && spec->p_l)
		return (ft_itoa_base_long(n, "0123456789abcdef"));
	else if (type == 'X')
		return (ft_itoa_base_long(n, "0123456789ABCDEF"));
	else if (type == 'x')
		return (ft_itoa_base(n, "0123456789abcdef"));
	else if (type == 'o')
		return (ft_itoa_base(n, "01234567"));
	else if (type == 'O')
		return (ft_itoa_base_long(n, "01234567"));
	else if (type == 'u' || type == 'U')
		return (ft_itoa_base(n, "0123456789"));
	else if (type == 'U' || spec->p_l)
		return (ft_itoa_base_long(n, "0123456789"));
	return (NULL);
}

char			*ft_proc_x(t_param **spec, va_list *ap)
{
	char	size;
	char	type;

	type = (*spec)->type;
	if (type == 'X' || type == 'O' || type == 'U')
		return (hextoa(va_arg(*ap, unsigned long), *spec));
	if ((size = (*spec)->p_h))
	{
		if (size == 1)
			return (hextoa(va_arg(*ap, unsigned int), *spec));
		else
			return (hextoa(va_arg(*ap, unsigned int), *spec));
	}
	else if ((size = (*spec)->p_l))
	{
		if (size == 1)
			return (hextoa(va_arg(*ap, unsigned long), *spec));
		else
			return (hextoa(va_arg(*ap, unsigned long), *spec));
	}
	else if ((*spec)->p_j)
		return (hextoa(va_arg(*ap, uintmax_t), *spec));
	else if ((*spec)->p_z)
		return (hextoa(va_arg(*ap, size_t), *spec));
	return (hextoa(va_arg(*ap, unsigned int), *spec));
}
