/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_proc_c.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 16:24:58 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 09:35:53 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_proc_c(t_param **spec, va_list *ap)
{
	unsigned int	c;

	if ((*spec)->type == 0)
		return (NULL);
	if ((*spec)->type == 'C' || (*spec)->p_l)
		return (ft_wint_to_str(va_arg(*ap, unsigned int)));
	c = va_arg(*ap, unsigned int);
	if (!c)
		return (ft_strdup("^@"));
	else
		return (ft_ctoa(c));
}
