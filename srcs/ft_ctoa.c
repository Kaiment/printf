/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ctoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:21:04 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 13:36:10 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_ctoa(int c)
{
	char	*ascii;

	if (!c)
		return (ft_strdup(""));
	ascii = ft_memalloc(2);
	ascii[0] = c;
	return (ascii);
}
