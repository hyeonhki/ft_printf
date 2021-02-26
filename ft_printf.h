/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:33:39 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/22 16:56:59 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

# define FLAG "0-*"
# define SPECIFIER "csdiupxX" //u,xX, 1. di(-) 2. p(0x) 3. cs -> 2.22 !
//c 
//s width flag

typedef struct	s_info
{
	int			buf_size;
	int 		minus;
	int			flag;
	int			zero;
	int			ch;
	int			width;
	int			precise;
	int			spec;
}				t_info;

void			pt_char(int a);
int				pt_c(va_list ap, t_info *info);
void			pt_normal(char **str, int *ret);
void			pt_double(char **str, int *ret);
int				pt_string(va_list ap, t_info *info);

char			*ft_strndup(const char *src, int n);
char			*ft_dup_options(char *str, char *type, int *index);
void			ft_bewhat(void *ptr, int size, int what);
int				ft_check_init(char c, const char *src);
void			ft_ptstr(char *str);

void			info_init(t_info *info);
void			save_info(t_info *info, char *str, va_list ap);

int				ft_printf(const char *input, ...);
#endif
