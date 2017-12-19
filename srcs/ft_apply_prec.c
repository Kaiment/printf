/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_prec.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 17:21:30 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 14:48:19 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static char		*free_join(char *s1, char *s2)
{
	char	*tmp1;
	char	*tmp2;
	char	*new;

	tmp1 = s1;
	tmp2 = s2;
	new = ft_strjoin(s1, s2);
	free(tmp1);
	free(tmp2);
	return (new);
}

static char		*prec_numbers(char *str_spec, int precision)
{
	char	*new;
	char	*ret;
	char	sign;
	int		nb_digits;
	int		nb_zero;

	sign = 0;
	if (*str_spec == '-' || *str_spec == '+' || *str_spec == ' ')
		sign = 1;
	nb_digits = ft_strlen(str_spec + sign);
	if (nb_digits >= precision)
		return (str_spec);
	nb_zero = precision - nb_digits - sign;
	if (!(new = (char *)ft_memalloc((sign + nb_zero + nb_digits + 1) *
					sizeof(char))))
		return (NULL);
	ret = new;
	if (sign)
		*new++ = *str_spec++;
	while (nb_zero-- > 0)
		*new++ = '0';
	ret = free_join(ret, str_spec);
	return (ret);
}

static char		*prec_string(char *str_spec, int precision)
{
	char	*new;

	if (strlen(str_spec) <= (unsigned long)precision)
		return (str_spec);
	if (!(new = (char *)ft_memalloc((precision + 1) * sizeof(char))))
		return (NULL);
	ft_strncpy(new, str_spec, precision);
	return (new);
}

int				ft_apply_prec(char **str_spec, t_param *spec)
{
	int		precision;
	char	numbers[10];

	ft_strcpy(numbers, "dDiuUoOxX");
	precision = spec->precision;
	if (ft_strchr(numbers, spec->type))
		if (!(*str_spec = prec_numbers(*str_spec, precision)))
			return (0);
	if (spec->type == 's' || spec->type == 'S')
		if (!(*str_spec = prec_string(*str_spec, precision)))
			return (0);
	return (1);
}
