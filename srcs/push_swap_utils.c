long long	ft_atol(const char *nptr)
{
	unsigned long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] == '0')
		i++;
	while (nptr[i])
	{
		num *= 10;
		num = num + nptr[i] - '0';
		i++;
	}
	
	return (num * sign);
}
