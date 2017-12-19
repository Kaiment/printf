/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_proc_s_maj.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 15:59:25 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 14:52:33 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_proc_s_maj(t_param *spec, va_list *ap)
{
	if (spec->type == 'f')
		return (NULL);
	return (ft_strtoupper(va_arg(*ap, char *)));
}
