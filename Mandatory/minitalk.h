/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:23:14 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/07 17:21:35 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <sys/_types/_pid_t.h>
# include <unistd.h>

typedef struct s_help
{
	int	bit_array[8];
	int	bit_count;
}		t_help;

#endif