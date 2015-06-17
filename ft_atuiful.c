/*
 * connaitre les int max : bc puis limits
 */
#include "../libraire/libft.h"

int		count_int(int nbr)
{
	int i;
	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int		diviseur(int nbr)
{
	int i;
	i = 1;
	int j;
	j = 1;
	while (i < nbr)
	{
		j = j * 10;
		i++;
	}
	return (j);
}

char	*ft_itoa2(int nbr)
{
	if (nbr < -2147483648)
		return (NULL);
	if (nbr > 2147483647)
		return (NULL);
	int k;
	int is_neg;

	if (nbr < 0)
	{
		nbr = nbr * -1;
		k = count_int(nbr) + 1;
		is_neg = 1;
	}
	else
		k = count_int(nbr);

	char *s;
	s = (char *)malloc((sizeof(char) * k) + 1);
	if (s == NULL)
		return (NULL);
	int i;
	i = 0;
	int j;
	j = count_int(nbr);
	int result;
	result = 0;
	while (i < count_int(nbr) + is_neg)
	{
		if (result == 0)
			result = nbr;
		if (i == 0 && is_neg == 1)
		{
			s[0] = '-';
			i++;
		}
		s[i] = '0' + (result / diviseur(j));
		result = nbr - (diviseur(j) * (nbr / diviseur(j)));
		i++;
		j--;
	}
	s[k + 1] = '\0';
	return (s);
}

int		main(void)
{
	ft_putstr(ft_itoa2(12242343));
	return (0);
}
