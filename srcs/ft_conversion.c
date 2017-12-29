/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_conversion.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 10:52:55 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:02:49 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		ft_analyze_convert(const char **format, t_param *spec)
{
	ft_check_flags(format, spec);
	ft_check_width(format, spec);
	ft_check_precision(format, spec);
	ft_check_size(format, spec);
	if (!(ft_get_type(format, spec)))
		return (0);
	return (1);
}

char			*ft_conversion(const char **format, va_list *ap)
{
	char		*str_spec;
	t_param		spec;

	*format += 1;
	ft_init_spec(&spec);
	if (!(ft_analyze_convert(format, &spec)))
		return (NULL);
	if (!(str_spec = ft_convert_spec(&spec, ap)))
		return (NULL);
	if (!(ft_apply_prec(&str_spec, &spec)))
		return (NULL);
	if (!(ft_apply_flags(&str_spec, &spec)))
		return (NULL);
	if (!(ft_apply_prec_hash(&str_spec, &spec)))
		return (NULL);
	if (!(ft_apply_width(&str_spec, &spec)))
		return (NULL);
	return (str_spec);
}
