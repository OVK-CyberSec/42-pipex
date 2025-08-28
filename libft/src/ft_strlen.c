#include "../inc/libft.h"

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
