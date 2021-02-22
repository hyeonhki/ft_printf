/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:33:39 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/22 16:19:21 by hyeonhki         ###   ########.fr       */
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

typedef struct	s_info
{
	int			buf_size;
	
	int 		flag;
	int			width;
	int			precise;
	int			specifier;
}				t_info;

void			pt_char(int a);
void			pt_normal(char **str, int *ret);
void			pt_double(char **str, int *ret);

char			*ft_strndup(const char *src, int n);
char			*ft_dup_options(char *str, char *type, int *index);

void			info_init(t_info *info);
void			save_info(t_info *info, char *str);

int				ft_printf(const char *input, ...);
#endif
