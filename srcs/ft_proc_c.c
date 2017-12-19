/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_proc_c.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 16:24:58 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 19:07:42 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_proc_c(t_param *spec, va_list *ap)
{
	if (spec->type == 0)
		return (NULL);
	if (spec->type == 'C' || spec->p_l)
		return (ft_wint_to_str(va_arg(*ap, unsigned int)));
	return (ft_ctoa(va_arg(*ap, unsigned int)));
}
