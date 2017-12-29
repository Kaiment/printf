/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_proc_p.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 16:07:01 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 09:33:55 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_proc_p(t_param **spec, va_list *ap)
{
	if ((*spec)->type == 0)
		return (NULL);
	return (ft_itoa_base((unsigned int)va_arg(*ap, void *),
				"0123456789abcdef"));
}
