#include "philo.h"

void print_table(t_table *table)
{
    printf("Number of philosophers: %d\n", table->philo_nbr);
    printf("Time to die: %ld\n", table->time_to_die);
    printf("Time to eat: %ld\n", table->time_to_eat);
    printf("Time to sleep: %ld\n", table->time_to_sleep);
    //printf("Number of meal limits: %ld\n", table->nbr_limits_mails);
    //printf("Start simulation: %ld\n", table->start_simulation);
    //printf("End simulation: %d\n", table->end_simulation);
}
