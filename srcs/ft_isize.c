/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isize.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 11:41:50 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/10 11:45:53 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		ft_isize(int c)
{
	char	sizes[5];
	int		i;

	i = 0;
	ft_strcpy(sizes, "hljz");
	while (sizes[i] != c)
		i++;
	return (sizes[i]);
}
