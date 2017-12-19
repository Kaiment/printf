/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:06 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 16:31:17 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, int pow)
{
	long	result;
	int		i;

	i = 0;
	if (pow == 0)
		return (1);
	result = n;
	while (i < pow - 1)
	{
		result *= n;
		i++;
	}
	return ((int)result);
}
