/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprime.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:49:04 by ihering-       #+#    #+#                */
/*   Updated: 2020/01/06 14:49:37 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_isprime(int number)
{
	int		prime;
	float	remain;

	remain = 0;
	prime = 2;
	while (prime < number)
	{
		remain = number % prime;
		if (remain == 0)
			return (0);
		prime++;
	}
	return (1);
}
