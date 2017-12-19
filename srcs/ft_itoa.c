/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:03 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 18:37:03 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		ft_nbdigits(int nb)
{
	int		nb_digits;

	nb_digits = 0;
	if (nb < 0)
	{
		nb *= -1;
		nb_digits++;
	}
	while (nb > 0)
	{
		nb /= 10;
		nb_digits++;
	}
	return (nb_digits);
}

static char		*ft_except(int n, char *a_nb)
{
	if (n == -2147483648)
		return (a_nb = ft_strdup("-2147483648"));
	else if (!n)
		return (a_nb = ft_strdup("0"));
	return (NULL);
}

char			*ft_itoa(int n)
{
	char	*a_nb;
	int		neg;
	int		i;

	neg = 1;
	if (!(a_nb = malloc((ft_nbdigits(n) + 1) * sizeof(char))))
		return (NULL);
	if (n == 0 || n == -2147483648)
		return (ft_except(n, a_nb));
	if (n < 0)
	{
		neg = -1;
		n *= -1;
	}
	i = 0;
	while (n > 0)
	{
		a_nb[i++] = '0' + (n % 10);
		n /= 10;
	}
	if (neg == -1)
		a_nb[i++] = '-';
	a_nb[i] = '\0';
	return (ft_strrev(a_nb));
}
