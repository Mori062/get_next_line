#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	main(void){
	char	*test = NULL;

	printf("test: %s\n", test);
	printf("strlen: %zu\n", ft_strlen(test));
	printf("\n");
	return (0);
}