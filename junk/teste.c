// create a function that calculate the length of a argument array like this:
int ft_arglen(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
