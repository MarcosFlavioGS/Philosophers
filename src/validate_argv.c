#include "../includes/philo.h"

static int check_max(char *argv[])
{
	int	max;
	int	min;
	int	index;

	max = 2147483647;
	min = -2147483648;
	index = 0;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) > max || ft_atoi(argv[index]) < min)
			return (0);
		index++;
	}
	return (1);
}

static int check_for_words(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int validate_argv(int argc, char *argv[])
{
	(void)argv;
	if (argc < 5 || argc > 6)
		return (0);
	if (!check_for_words(argv))
		return (0);
	if (check_max(argv))
		return (0);
	return (0);
}
