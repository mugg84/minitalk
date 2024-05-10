/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:24:48 by mmughedd          #+#    #+#             */
/*   Updated: 2024/05/09 13:24:14 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int	signal, siginfo_t *siginfo, void *context)
{
	unsigned char	c;
	static int		i = -1;

	i = -1;
	c = 0;
	if (signal == SIGUSR1)
		printf("\nIntercepted SIGURS1!\n");
	else if (signal == SIGUSR2)
		printf("\nIntercepted SIGURS2!\n");
}

void	set_signal_action(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &sigusr_handler;
	act.sa_flags = SA_SIGINFO; 
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(int argc, char *argv[])
{
	int	pid;

	set_signal_action();
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		usleep(100);
	}
	return (0);
}
