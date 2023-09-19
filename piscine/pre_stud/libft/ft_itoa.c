#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{

}

int	main(void)
{
	char	*s;
	int	pos = 422489;
	int neg = -9978425;

	s = ft_itoa(pos);
	printf("%s", s);
	//free(s);
	return (0);
}