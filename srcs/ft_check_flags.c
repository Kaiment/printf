/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_flags.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 14:01:56 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 09:09:38 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_check_flags(const char **format, t_param *spec)
{
	while (ft_isflag(**format))
	{
		if (**format == '#')
			spec->p_hash = 1;
		if (**format == '0')
			spec->p_zero = 1;
		if (**format == '-')
			spec->p_minus = 1;
		if (**format == '+')
			spec->p_plus = 1;
		if (**format == ' ')
			spec->p_space = 1;
		*format += 1;
	}
}
