/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_proc_s.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 15:27:36 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 12:26:35 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_proc_s(t_param *spec, va_list *ap)
{
	if (spec->p_l || spec->type == 'S')
		return (ft_wchart_to_str(va_arg(*ap, unsigned int *)));
	return (ft_strdup(va_arg(*ap, char *)));
}
