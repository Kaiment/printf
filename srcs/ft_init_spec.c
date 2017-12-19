/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_spec.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 12:30:33 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 10:51:16 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_init_spec(t_param *spec)
{
	spec->p_hash = 0;
	spec->p_zero = 0;
	spec->p_minus = 0;
	spec->p_plus = 0;
	spec->p_space = 0;
	spec->field_size = 0;
	spec->precision = -1;
	spec->p_h = 0;
	spec->p_l = 0;
	spec->p_j = 0;
	spec->p_z = 0;
	spec->type = 0;
}
