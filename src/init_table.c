#include "../includes/philo.h"

static t_args	*init_args(char *argv[])
{
	t_args	*args;

	args = ft_calloc(sizeof(t_args), 1);
	args->p_quantity = ft_atoi(argv[1]);
	args->p_die = ft_atoi(argv[2]);
	args->p_eat = ft_atoi(argv[3]);
	args->p_sleep = ft_atoi(argv[4]);
	args->p_eat_quantity = -1;
	pthread_mutex_init(&args->meals_lock, NULL);
	pthread_mutex_init(&args->last_meal_lock, NULL);
	pthread_mutex_init(&args->state_lock, NULL);
	pthread_mutex_init(&args->banquet_lock, NULL);
	if (argv[5])
		args->p_eat_quantity = ft_atoi(argv[5]);
	return (args);
}

static t_philo *init_philos(t_fork *forks, char *argv[])
{
	t_philo *philos;
	t_args  *args;
	int     index;
	long    sim_start;

	index = 0 ;
	sim_start = get_current_time();
	args = init_args(argv);
	philos = ft_calloc(sizeof(t_philo), ft_atoi(argv[1]));
	while (index < ft_atoi(argv[1]))
	{
		philos[index].args = args;
		philos[index].id = index + 1;
		philos[index].left_fork = &forks[index];
		philos[index].right_fork = &forks[(index + 1) % ft_atoi(argv[1])];
		philos[index].meals_done = 0;
		philos[index].last_meal = 0;
		philos[index].sim_start = sim_start;
		index++;
	}
	return (philos);
}

static t_fork *init_forks(int n)
{
	t_fork *forks;
	int    index;

	index = 0;
	forks = ft_calloc(sizeof(t_fork), n);
	while (index < n)
	{
		pthread_mutex_init(&forks[index], NULL);
		index++;
	}
	return (forks);
}

t_table *init_table(char *argv[])
{
	t_table *table;

	table = ft_calloc(sizeof(t_table), 1);
	table->forks = init_forks(ft_atoi(argv[1]));
	table->philos = init_philos(table->forks, argv);
}
