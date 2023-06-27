#include <stdio.h>

int	newline_ex(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	if (s[i] == c)
		return (0);
	return (1);
}

int	main(void){
	char	*test = "";

	printf("test: %s\n", test);
	printf("strlen: %d\n", newline_ex(test, '\n'));
	printf("\n");
	return (0);
}