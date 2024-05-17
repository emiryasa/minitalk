/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:15 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/17 15:14:51 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_signal(int pid, int c)
{
	int	bit;

	bit = 6;
	while (bit != -1)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(77);
		bit--;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("exited with: %s\n", ERR_ARGUMENT);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		ft_printf("exited with: %s\n", PID_ERR);
		exit(1);
	}
	while (*argv[2])
		send_signal(pid, *argv[2]++);
	return (0);
}
