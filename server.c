/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:24:48 by mmughedd          #+#    #+#             */
/*   Updated: 2024/05/10 12:02:52 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Depending on the signal it updates the character
 * 
 * Arguments:
 * - signal: SIGUSR1 for 1, SIGUSR2 for 0
 * 
 * Returns:
 * - Nothing
 */
void	sigusr_handler(int signal)
{
	static unsigned char	c = 0;
	static int				i = -1;

	if (i == -1)
		i = 7;
	if (signal == SIGUSR1)
		c |= (1 << i);
	if (--i < 0 && c)
	{
		ft_printf("%c", c);
		c = 0;
	}
}

/* Set actions for SIGUSR1 and SIGUSR2 signals
 * 
 * Arguments:
 * - None
 * 
 * Returns:
 * - Nothing
 */
void	set_signal_action(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &sigusr_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		perror("Sigaction SIGUSR1 error");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		perror("Sigaction SIGUSR2 error");
		exit(EXIT_FAILURE);
	}
}

/* Main server function
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
	int	pid;

	set_signal_action();
	pid = getpid();
	ft_printf("SERVER PID: %d\n", pid);
	while (1)
		usleep(100);
	return (EXIT_SUCCESS);
}
