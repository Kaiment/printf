/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_size.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 14:04:48 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 10:51:34 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		fill_size(const char **format, t_param *spec)
{
	if (**format == 'h')
		spec->p_h++;
	else if (**format == 'l')
		spec->p_l++;
	else if (**format == 'j')
		spec->p_j++;
	else
		spec->p_z++;
	*format += 1;
}

void			ft_check_size(const char **format, t_param *spec)
{
	if (**format == 'h')
	{
		fill_size(format, spec);
		if (**format == 'h')
			fill_size(format, spec);
		return ;
	}
	if (**format == 'l')
	{
		fill_size(format, spec);
		if (**format == 'l')
			fill_size(format, spec);
		return ;
	}
	if (**format == 'j')
		fill_size(format, spec);
	if (**format == 'z')
		fill_size(format, spec);
}
