/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_type.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 14:05:30 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 11:36:57 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	is_valid_type(int c)
{
	char	types[16];
	int		i;

	i = 0;
	ft_strcpy(types, "sSpdDioOuUxXcC%");
	while (types[i])
	{
		if (types[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_get_type(const char **format, t_param *spec)
{
	if (is_valid_type(**format))
	{
		spec->type = **format;
	}
	else
	{
		ft_putstr("Incorrect conversion specification\n");
		ft_putstr("Please follow this template : %[flags][width]");
		ft_putstr("[precision][size]type\n");
		return (0);
	}
	*format += 1;
	return (1);
}
