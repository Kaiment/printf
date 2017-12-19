/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_flags.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 14:54:19 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 15:49:10 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		add_front(char **dest, char *src)
{
	int		full_len;
	int		i;
	char	*new;
	char	*tmp;

	full_len = ft_strlen(*dest) + ft_strlen(src);
	if (!(new = (char *)ft_memalloc(full_len + 1)))
		return (0);
	i = 0;
	ft_strcat(new, src);
	ft_strcat(new, *dest);
	tmp = *dest;
	*dest = new;
	free(tmp);
	return (1);
}

static int		a_is_not_neg(char type, char *str_spec)
{
	int		i;

	i = 0;
	if (type != 'd' && type != 'D' && type != 'i' && type != 'u' &&
			type != 'U')
		return (0);
	while (!ft_isdigit(str_spec[i]))
	{
		if (str_spec[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int				ft_apply_flags(char **str_spec, t_param *spec)
{
	char	type;

	type = spec->type;
	if (spec->p_space && !(spec->p_plus) && a_is_not_neg(type, *str_spec))
		if (!(add_front(str_spec, " ")))
			return (0);
	if (spec->p_plus && a_is_not_neg(type, *str_spec))
		if (!(add_front(str_spec, "+")))
			return (0);
	if (spec->p_hash && (spec->type == 'o' || spec->type == 'O'))
		if (!(add_front(str_spec, "0")))
			return (0);
	if (spec->p_hash && spec->type == 'x')
		if (!(add_front(str_spec, "0x")))
			return (0);
	if (spec->p_hash && spec->type == 'X')
		if (!(add_front(str_spec, "0X")))
			return (0);
	return (1);
}
