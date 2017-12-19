/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wint_to_str.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 11:26:29 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 11:14:17 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static char		*choose_mask(int nb_bytes)
{
	if (nb_bytes == 2)
		return (ft_strdup("xxxxx011"));
	else if (nb_bytes == 3)
		return (ft_strdup("xxxx0111"));
	else
		return (ft_strdup("xxx01111"));
}

static char		*one_byte(char *binary)
{
	char	*holder;
	char	*ret;
	char	*tmp;

	holder = ft_strdup("xxxxxxx0");
	tmp = holder;
	while (*binary)
		*holder++ = *binary++;
	while (*holder == 'x')
		*holder++ = '0';
	ft_strrev(tmp);
	if (!(ret = (char *)ft_memalloc(2 * sizeof(char))))
		return (NULL);
	ret[0] = ft_atoi_binary(tmp);
	return (ret);
}

static char		*multi_bytes(char *binary, int nb_bytes)
{
	char	**bytes;
	char	*str;
	int		i;
	int		j;

	if (!(bytes = (char **)ft_memalloc((nb_bytes + 1) * sizeof(char))))
		return (NULL);
	bytes[0] = choose_mask(nb_bytes);
	i = 1;
	while (i < nb_bytes)
		bytes[i++] = ft_strdup("xxxxxx01");
	if (!(str = (char *)ft_memalloc((nb_bytes + 1) * sizeof(char))))
		return (NULL);
	while (--i >= 0)
	{
		j = 0;
		while (*binary && (bytes[i][j] == 'x'))
			bytes[i][j++] = *binary++;
		while (bytes[i][j] == 'x')
			bytes[i][j++] = '0';
		str[i] = ft_atoi_binary(ft_strrev(bytes[i]));
		free(bytes[i]);
	}
	return (str);
}

char			*ft_wint_to_str(unsigned int character)
{
	char	*str;
	char	*tmp;
	int		nb_active_bits;

	str = ft_itoa_base(character, "01");
	tmp = str;
	while (*str != '1')
		str++;
	str = ft_strdup(str);
	free(tmp);
	nb_active_bits = ft_strlen(str);
	ft_strrev(str);
	if (nb_active_bits <= 7)
		return ((one_byte(str)));
	else if (nb_active_bits <= 11)
		return (multi_bytes(str, 2));
	else if (nb_active_bits <= 16)
		return (multi_bytes(str, 3));
	else if (nb_active_bits <= 21)
		return (multi_bytes(str, 4));
	else
		return (NULL);
}
