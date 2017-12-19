/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_spec.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 10:18:31 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 10:32:45 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <stdio.h>

void	print_spec(t_param *spec)
{
	printf("hash : %d\nzero : %d\n", spec->p_hash, spec->p_zero);
	printf("minus : %d\nplus : %d\n", spec->p_minus, spec->p_plus);
	printf("space : %d\nmin width : %d\n", spec->p_space, spec->field_size);
	printf("precision : %d\nh : %d\n", spec->precision, spec->p_h);
	printf("l : %d\nj : %d\n", spec->p_l, spec->p_j);
	printf("z : %d\ntype : %c\n", spec->p_z, spec->type);
}
