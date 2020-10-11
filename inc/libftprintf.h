/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 18:21:14 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 15:38:16 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct		s_flag {
	int				width;
	int				zero;
	int				dot;
	int				star;
	int				is_width;
	int				is_zero;
	int				is_dot;
}					t_flag;

typedef struct		s_var {
	struct s_flag	flag;
	int				i;
	char			type;
	char			*res;
	int				moove;
	int				*ret;
}					t_var;

struct s_flag		detect_flags(char *str);
struct s_flag		initialise();
struct s_var		init();
char				*ft_itoa3(unsigned long n);
void				print_x_zero_and_dot(struct s_var v, unsigned long nb,
						char c, char *nb2);
void				print_x(struct s_var v, unsigned long nb, char c);
void				print_x_width_and_dot(struct s_var v, unsigned long nb,
						char c, char *nb2);
void				print_x_zero(struct s_var v, unsigned long nb, char c,
						char *nb2);
void				print_x_width(struct s_var v, unsigned long nb, char c,
						char *nb2);
void				print_u_zero_and_dot(struct s_var v, unsigned long nb,
						char *nb2);
void				print_u(struct s_var v, unsigned long nb);
void				print_u_width_and_dot(struct s_var v, unsigned long nb,
						char *nb2);
void				print_u_zero(struct s_var v, unsigned long nb, char *nb2);
void				print_u_width(struct s_var v, unsigned long nb, char *nb2);
void				ft_putnbr2(unsigned long nb, struct s_var v);
int					ft_printf(const char *format, ...);
void				print_pointer(struct s_var v, unsigned long nb);
void				print_string(struct s_var v, char *value);
void				print_percent(struct s_var v);
int					is_star(char *str);
void				print_char(struct s_var v, int value);
int					detect_percent(char c);
char				*make_sub_str(const char *format, int i);
char				*replace_star(char *str, int value);
char				detect_type(char *str);
void				print_zero(int nb, struct s_var v);
void				print_space(int nb, struct s_var v);
char				*ft_itoa2(unsigned long nb);
char				*ft_itoa(unsigned long nb);
void				ft_putstrn(char *str, int max, struct s_var v);
int					ft_isdigit2(int c);
int					ft_isdigit(int c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
void				ft_putstr(char *str, struct s_var v);
void				ft_putnbr(int nb, struct s_var v);
void				ft_putnbr_hex(unsigned long nb, char c, struct s_var v);
void				ft_putchar(char c);
void				print_int_zero_and_dot(struct s_var v, int nb, char *nb2);
void				print_int(struct s_var v, int nb);
void				print_int_width_and_dot(struct s_var v, int nb, char *nb2);
void				print_int_zero(struct s_var v, int nb, char *nb2);
void				print_int_width(struct s_var v, int nb, char *nb2);
int					check_multi_flag(char *str);
int					check_multi_flag2(char *str);
#endif
