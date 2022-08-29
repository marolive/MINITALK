/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:56:11 by marolive          #+#    #+#             */
/*   Updated: 2022/08/28 15:14:24 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	nbrlen(int n)
{
	int			len;
	long int	aux;

	len = 0;
	aux = n;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (aux != 0)
	{
		aux = aux / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	aux;
	char		*mall;
	int			len;

	len = nbrlen(n);
	mall = malloc((len + 1) * sizeof(char));
	if (!mall)
		return (NULL);
	aux = 1;
	if (n < 0)
		aux = -1;
	mall[len] = '\0';
	if (n == 0)
	{
		mall[0] = '0';
		return (mall);
	}
	while (n != 0)
	{
		mall[--len] = aux * (n % 10) + 48;
		n = n / 10;
	}
	if (aux < 0)
		mall[0] = '-';
	return (mall);
}

void	sig_handler(int signal)
{
	static int	byte;
	static int	i;

	if (signal == SIGUSR1)
		byte += 0b10000000 >> i;
	i++;
	if (i == 8)
	{
		write(1, &byte, 1);
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	char	*pidd;

	pidd = ft_itoa(getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	write(1, "PID: ", 5);
	write(1, pidd, ft_strlen(pidd));
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
