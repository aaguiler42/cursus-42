/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:57:19 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/22 00:01:59 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static void	ft_check(int c, int signo, int *total, int *error)
{
	if (error && c != '\0')
	{
		*error = 1;
		return ;
	}
	if (signo == 1 && *total < 0)
	{
		if (error)
			*error = 1;
		*total = -1;
	}
	else if (signo == -1 && *total > 0)
	{
		if (error)
			*error = 1;
		*total = 0;
	}
}

int ft_atoic(const char *str, int *error)
{
	int	i;
	int	total;
	int	signo;

	i = 0;
	total = 0;
	signo = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		signo = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	total *= signo;
	ft_check(str[i], signo, &total, error);
	return (total);
}