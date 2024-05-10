/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:24:52 by mmughedd          #+#    #+#             */
/*   Updated: 2024/05/10 12:19:06 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Sends a char info bit by bit
 * 
 * Arguments:
 * - S: PID
 * 
 * Returns:
 * - If valid, it returns PID converted to int, EXIT_FAILURE otherwise
 */
static void	send_bits(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	while (i--)
	{
		tmp = c >> i;
		if (tmp & 1)
		{
			if(kill(pid, SIGUSR1) == -1)
			{
				perror("SIGUSR1 error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if(kill(pid, SIGUSR2) == -1)
			{
				perror("SIGUSR2 error");
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
	}
}

/* Checks if PID provided is valid
 * 
 * Arguments:
 * - S: PID
 * 
 * Returns:
 * - If valid, it returns PID converted to int, EXIT_FAILURE otherwise
 */
static int	check_pid(char *s)
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	while (++i)
	{
		if (!ft_isdigit(s[i]))
		{
			perror("Invalid PID, only digits accepted");
			exit(EXIT_FAILURE);
		}
	}
	res = ft_atoi(s);
	return (res);
}

/* Main client function
 * 
 * Arguments:
 * - Argc: number of args
 * - Argv: strings of args
 * 
 * Returns:
 * - EXIT_SUCCESS
 */
int	main(int argc, char *argv[])
{
	int		server_pid;
	int		i;
	char	*msg;

	if (argc == 3)
	{
		server_pid = check_pid(argv[1]);
		msg = argv[2];
		i = 0;
		while (msg[i])
			send_bits(server_pid, msg[i++]);
		send_bits(server_pid, '\n');
	}
	else
	{
		ft_printf("Wrong parameters. Client takes only two parameters: ");
		ft_printf("server PID and string to send\n");
	}
	return (EXIT_SUCCESS);
}
