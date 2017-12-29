/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_spec.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 14:41:14 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 09:47:38 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static t_proc_type		new_func(char type, char *(*func)(t_param **spec,
			va_list *ap))
{
	t_proc_type		new;

	new.type = type;
	new.func = func;
	return (new);
}

static void				fill_funcs(t_proc_type **funcs)
{
	(*funcs)[0] = new_func('s', &ft_proc_s);
	(*funcs)[1] = new_func('S', &ft_proc_s);
	(*funcs)[2] = new_func('p', &ft_proc_p);
	(*funcs)[3] = new_func('d', &ft_proc_d);
	(*funcs)[4] = new_func('D', &ft_proc_d);
	(*funcs)[5] = new_func('i', &ft_proc_d);
	(*funcs)[6] = new_func('o', &ft_proc_x);
	(*funcs)[7] = new_func('O', &ft_proc_x);
	(*funcs)[8] = new_func('u', &ft_proc_x);
	(*funcs)[9] = new_func('U', &ft_proc_x);
	(*funcs)[10] = new_func('x', &ft_proc_x);
	(*funcs)[11] = new_func('X', &ft_proc_x);
	(*funcs)[12] = new_func('c', &ft_proc_c);
	(*funcs)[13] = new_func('C', &ft_proc_c);
}

char					*ft_convert_spec(t_param *spec, va_list *ap)
{
	int				i;
	char			*percent;
	t_proc_type		*funcs;

	if (spec->type == '%')
	{
		percent = (char *)ft_memalloc(1);
		ft_strcpy(percent, "%");
		return (percent);
	}
	if (!(funcs = (t_proc_type *)malloc(15 * sizeof(t_proc_type))))
		return (NULL);
	fill_funcs(&funcs);
	i = 0;
	while (i < 15)
	{
		if (spec->type == funcs[i].type)
			return (funcs[i].func(&spec, ap));
		i++;
	}
	return (NULL);
}
