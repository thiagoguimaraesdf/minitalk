/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:42:47 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/23 15:08:14 by tguimara         ###   ########.fr       */
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
}	t_char;

#endif