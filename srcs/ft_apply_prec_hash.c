/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_prec_hash.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 09:12:26 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 09:23:22 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		add_front(char **dest, char *src)
{
	int		full_len;
	char	*new;
	char	*tmp;

	full_len = ft_strlen(*dest) + ft_strlen(src);
	if (!(new = (char *)ft_memalloc((full_len + 1) * sizeof(char))))
		return (0);
	ft_strcat(new, src);
	ft_strcat(new, *dest);
	tmp = *dest;
	*dest = new;
	free(tmp);
	return (1);
}

int				ft_apply_prec_hash(char **str_spec, t_param *spec)
{
	char	type;

	type = spec->type;
	if (type != 'x' && type != 'X' && type != 'o' && type != 'O')
		return (1);
	if (spec->precision == 0)
		return (1);
	if (!spec->p_hash)
		return (1);
	if (type == 'o' || type == 'O')
		if (!add_front(str_spec, "0"))
			return (0);
	if (type == 'x')
		if (!add_front(str_spec, "0x"))
			return (0);
	if (type == 'X')
		if (!add_front(str_spec, "0X"))
			return (0);
	return (1);
}
