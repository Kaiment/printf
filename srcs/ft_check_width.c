/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_width.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 14:02:56 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 09:05:19 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_check_width(const char **format, t_param *spec)
{
	spec->field_size = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		*format += 1;
}
