#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	handler(int signal);
void	ft_pid(void);
void	ft_send_msg(pid_t pid, int c);
void	ft_error(char *str, int len);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(long n);

#endif
