/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_precision.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 14:04:11 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 11:48:10 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_check_precision(const char **format, t_param *spec)
{
	if (**format != '.')
		return ;
	*format += 1;
	spec->precision = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		*format += 1;
}
