/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_binary.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 17:21:25 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:53:28 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char		ft_atoi_binary(char *binary)
{
	int		*bits;
	int		i;
	int		j;
	int		result;

	if (strlen(binary) != 8)
	{
		ft_putstr("Error : incorrect byte\n");
		return (-1);
	}
	if (!(bits = (int *)ft_memalloc(8 * sizeof(int))))
		return (-1);
	i = -1;
	while (++i < 8)
		bits[i] = ft_pow(2, i);
	ft_strrev(binary);
	result = 0;
	j = 0;
	while (j < 8)
		result += (*binary++ - '0') * bits[j++];
	return (result);
}
