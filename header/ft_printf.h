/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <kbedene@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 10:04:20 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:16:48 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wctype.h>
# include <stdio.h>

typedef struct		s_param
{
	char			p_hash;
	char			p_zero;
	char			p_minus;
	char			p_plus;
	char			p_space;
	int				field_size;
	int				precision;
	char			p_h;
	char			p_l;
	char			p_j;
	char			p_z;
	char			type;
	char			is_null;
}					t_param;

void				print_spec(t_param *spec);

typedef struct		s_proc_type
{
	char			type;
	char			*(*func) (t_param **spec, va_list *ap);
}					t_proc_type;

/*
 ** main function
*/
int					ft_printf(const char *format, ...);

/*
 ** Control functions
*/
int					ft_print_convert(char **format, va_list *ap);
int					ft_putcstr(const char *s, int c);
char				*ft_convert_spec(t_param *spec, va_list *ap);

/*
 ** Secondary functions
*/
char				*ft_itoa_base(unsigned int n, char *base);
char				*ft_itoa_base_long(unsigned long n, char *base);
size_t				ft_strclen(const char *s, int c);
char				*ft_strcdup(const char *s, int c);
char				*ft_ctoa(int c);
int					ft_apply_flags(char **str_spec, t_param *spec);
int					ft_apply_prec(char **str_spec, t_param *spec);
int					ft_apply_prec_hash(char **str_spec, t_param *spec);
int					ft_apply_width(char **str_spec, t_param *spec);
void				ft_init_spec(t_param *spec);
char				ft_atoi_binary(char *binary);
char				*ft_wint_to_str(unsigned int character);
char				*ft_wchart_to_str(unsigned int *characters);

/*
 ** Process functions
*/
char				*ft_proc_s(t_param **spec, va_list *ap);
char				*ft_proc_p(t_param **spec, va_list *ap);
char				*ft_proc_d(t_param **spec, va_list *ap);
char				*ft_proc_x(t_param **spec, va_list *ap);
char				*ft_proc_c(t_param **spec, va_list *ap);

/*
 ** Checker functions
*/
void				ft_check_flags(const char **format, t_param *spec);
void				ft_check_width(const char **format, t_param *spec);
void				ft_check_precision(const char **format, t_param *spec);
void				ft_check_size(const char **format, t_param *spec);
int					ft_get_type(const char **format, t_param *spec);
int					ft_isflag(int c);
int					ft_isize(int c);

/*
 ** libft functions
*/
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlen(const char *s);
void				ft_putnbr_long(long n, int fd);
void				*ft_memalloc(size_t size);
char				*ft_strrev(char *s);
void				ft_bzero(void *s, size_t n);
void				ft_swap(char *a, char *b);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_conversion(const char **format, va_list *ap);
char				*ft_itoa(long n);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strtoupper(char *s);
int					ft_toupper(int c);
int					ft_islower(char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_isdigit(int c);
int					ft_pow(int n, int pow);

#endif
