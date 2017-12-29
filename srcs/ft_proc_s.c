/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_proc_s.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 15:27:36 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 10:03:06 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_proc_s(t_param **spec, va_list *ap)
{
	char	*ret;

	if ((*spec)->p_l || (*spec)->type == 'S')
		return (ft_wchart_to_str(va_arg(*ap, unsigned int *)));
	ret = va_arg(*ap, char *);
	if (ret)
		return (ft_strdup(ret));
	else
	{
		(*spec)->is_null = 1;
		return (ft_strdup("(null)"));
	}
}
