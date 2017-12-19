/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 17:20:33 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 18:07:29 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_itoa_base(unsigned long n, char *base)
{
	char	*ascii;
	short	nbase;
	short	i;

	i = 0;
	nbase = ft_strlen(base);
	ascii = ft_memalloc(16);
	ascii[i] = '0';
	while (n)
	{
		ascii[i] = base[n % nbase];
		n /= nbase;
		i++;
	}
	ft_strrev(ascii);
	return (ascii);
}
