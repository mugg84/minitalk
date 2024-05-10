/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:24:52 by mmughedd          #+#    #+#             */
/*   Updated: 2024/05/09 12:58:10 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	while (i--)
	{
		tmp = c >> i;
		if (tmp & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}
int	main(int argc, char *argv[])
{
	int		server_pid;
	int		i;
	char	*msg;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		msg = argv[2];
		i = 0;
		while (msg[i])
			send_bits(server_pid, msg[i++]);
	}
	else
		ft_printf("Wrong parameters. Client takes only two parameters: server PID and string to send\n");
	return (0);
}