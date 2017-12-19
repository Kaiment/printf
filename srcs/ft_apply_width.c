/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_width.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 16:35:12 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 18:40:35 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		fill_it(char **field, int nb_c, int c)
{
	int		i;

	i = 0;
	while (i < nb_c)
		(*field)[i++] = c;
	(*field)[i] = '\0';
}

int				ft_apply_width(char **str_spec, t_param *spec)
{
	int		len;
	char	*new;
	char	*tmp;

	len = ft_strlen(*str_spec);
	if (len >= spec->field_size)
		return (1);
	if (!(new = (char *)ft_memalloc((spec->field_size + 1) * sizeof(char))))
		return (0);
	new[spec->field_size + 1] = '\0';
	if (spec->p_zero && spec->precision == -1)
		fill_it(&new, (spec->field_size - len), '0');
	else
		fill_it(&new, (spec->field_size - len), ' ');
	tmp = *str_spec;
	if (spec->p_minus)
		*str_spec = ft_strjoin(*str_spec, new);
	else
		*str_spec = ft_strjoin(new, *str_spec);
	free(tmp);
	return (1);
}
