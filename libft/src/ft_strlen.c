/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:27:13 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/03 14:27:14 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *theString)
{
	int	i;

	if (!theString)
		return (0);
	i = 0;
	while (theString[i])
		i++;
	return (i);
}
