/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:30 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/17 15:13:45 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static char	c;
	static int	check_b = 0;

	if (signal == SIGUSR1)
		c = c | 1;
	check_b++;
	if (check_b == 7)
	{
		ft_printf("%c", c);
		c = 0;
		check_b = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("procces_id -> %d", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
}
