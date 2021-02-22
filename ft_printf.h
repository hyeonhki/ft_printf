/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:33:39 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/15 15:33:42 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

# define SPECIFIER "csdiupxX"

typedef struct	s_options
{
	int 		flag;
	int			width;
	int			precise;
	char		specifier;
}				t_options;

void			pt_char(int a);
int				ft_printf(const char *input, ...);
#endif
