/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:01 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 18:37:01 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	result;
	long	neg;
	char	*cursor;

	result = 0;
	neg = 1;
	cursor = (char *)str;
	while (((*cursor >= 9) && (*cursor <= 13)) || (*cursor == ' '))
		cursor++;
	if (*cursor == '-' || *cursor == '+')
	{
		if (*cursor == '-')
			neg = -1;
		cursor++;
	}
	while (*cursor >= '0' && *cursor <= '9')
	{
		result = 10 * result + (*cursor - '0');
		cursor++;
	}
	return ((int)(result * neg));
}
