/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:36:07 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/03 20:21:52 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static int	len_str(int num)
{
	int	i;

	i = 0;
	if (num < 1)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*new_str(char *str, int len, int n)
{
	int			i;
	long long	num;
	char		*nstr;

	i = len;
	num = n;
	nstr = str;
	if (n < 0)
	{
		nstr[0] = '-';
		num *= -1;
	}
	while (i--)
	{
		if (i > 0 || n >= 0)
		{
			nstr[i] = num % 10 + '0';
			num /= 10;
		}
	}
	nstr[len] = '\0';
	return (nstr);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = len_str(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result = new_str(result, len, n);
	return (result);
}

//int	main(void)
//{
//	char	*str;
//
//	str = ft_itoa(2147483647);
//	printf("MIN %s\n", str);
//	str = ft_itoa(-2147483648);
//	printf("MAX %s\n", str);
//	str = ft_itoa(0);
//	printf("0= %s\n", str);
//	str = ft_itoa('\0');
//	printf("NULL= %s\n", str);
//	return (0);
//}
