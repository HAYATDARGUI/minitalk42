/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:23:14 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/10 11:34:24 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/_types/_pid_t.h>
# include <unistd.h>

typedef struct s_help
{
	int		bit_array[8];
	int		bit_count;
	pid_t	last_client_pid;
}			t_help;

#endif