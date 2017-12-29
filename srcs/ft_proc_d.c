/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_proc_d.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 16:10:08 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 12:29:45 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_proc_d(t_param **spec, va_list *ap)
{
	char	size;

	if ((*spec)->type == 'D')
		return (ft_itoa(va_arg(*ap, long)));
	else if ((size = (*spec)->p_h))
	{
		if (size == 1)
			return (ft_itoa((short)va_arg(*ap, int)));
		else
			return (ft_itoa((signed char)va_arg(*ap, int)));
	}
	else if ((size = (*spec)->p_l))
	{
		if (size == 1)
			return (ft_itoa(va_arg(*ap, long)));
		else
			return (ft_itoa(va_arg(*ap, long long)));
	}
	else if ((*spec)->p_j)
		return (ft_itoa(va_arg(*ap, intmax_t)));
	else if ((*spec)->p_z)
		return (ft_itoa(va_arg(*ap, ssize_t)));
	else
		return (ft_itoa(va_arg(*ap, int)));
}
