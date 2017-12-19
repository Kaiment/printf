/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isflag.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 09:52:43 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 09:10:58 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		ft_isflag(int c)
{
	int		i;
	char	flags[6];

	ft_strcpy(flags, "#0-+ ");
	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}
