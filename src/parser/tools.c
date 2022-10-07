int split_len(char **sp)
{
	int i;

	i = 0;
	while (sp[i])
		i++;
	return (i);
}
