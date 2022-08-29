/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:36:22 by marolive          #+#    #+#             */
/*   Updated: 2022/08/28 15:15:34 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long			resul;
	unsigned int	i;
	long			neg;

	neg = 1;
	resul = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resul = resul * 10 + str[i] - '0';
		i++;
	}
	return ((int)resul * neg);
}

void	send_msg(pid_t pid, char *msg)
{
	size_t	i;
	int		j;

	i = 0;
	while (msg[i])
	{
		while (j < 8)
		{
			if (msg[i] & (0b10000000 >> j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			j++;
		}
		j = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	n_pid;

	if (argc != 3)
	{
		write(1, "error, ARG MIN/MAX 3\n", 21);
		return (1);
	}
	n_pid = ft_atoi(argv[1]);
	send_msg(n_pid, argv[2]);
	return (0);
}
