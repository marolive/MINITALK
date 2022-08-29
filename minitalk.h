/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:14:18 by marolive          #+#    #+#             */
/*   Updated: 2022/08/28 15:53:49 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	sig_handler(int signal);
void	send_msg(pid_t pid, char *msg);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);

#endif
