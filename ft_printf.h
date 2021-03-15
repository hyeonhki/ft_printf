/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:33:39 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/14 16:09:48 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h> //지우는 거 잊지말기
# include "./libft/libft.h"

# define FLAG "0-*"
# define SPECIFIER "csdiupxX%"

typedef struct	s_info
{
	int				f_minus;//
	int				f_zero;//
	int				f_size;//
	int				f_presize;//
	int				width;//
	int				prec;//
	int				spec;//
	int				i;//
	int				int_d;//
	int				len;
	int				cnt; //c의 반환값
	char			*ret; //
	char			*str;
	char			*buf;//
	void			*void_p;//
}				t_info;

void			pt_char(int a);
int				pt_c(va_list ap, t_info *info);
void			pt_normal(char **str, int *ret);
void			pt_double(char **str, int *ret);
int				pt_s(va_list ap, t_info *info);
int				pt_d(va_list ap, t_info *info);
int				pt_plusd(t_info *info);
int				pt_minusd(t_info *info);
int				pt_u(t_info *info);
int				pt_p(va_list ap, t_info *info);
int				pt_buf(t_info *info);
int				pt_x(va_list ap, t_info *info);
int				pt_bigx(va_list ap, t_info *info);
void			pt_flagswap(int flag, char *s1, char *s2);

char			*ft_strndup(const char *src, int n);
char			*ft_dup_options(char *str, char *type, int *index);
void			ft_bewhat(void *ptr, int size, int what);
void			ft_check_flag(char **str, t_info *info);
int				ft_check_init(char c, const char *src);
void			ft_ptstr(char *str);
char			*ft_bufwhat(int size, int what);
void			ft_pt2str(char *s1, char *s2); //지워보자
void			ft_mvminus(char **str, int d);
char			**ft_putnbr_base(unsigned long nbr, char *base);
void			ft_multifree(char *p1, char *p2);

void			info_init(t_info *info);
void			save_info(t_info *info, char *str, va_list ap);

int				ft_printf(const char *input, ...);
#endif
