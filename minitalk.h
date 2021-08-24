/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:42:47 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/24 13:09:42 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h> 
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"

typedef struct s_char {
	char	c;
	int		cur_bit;
	int		get_response;
}	t_char;

static t_char	g_char;

#endif