#include "philo.h"

void *routine(void *arg)
{
    t_philo *philo;
   
    philo = (t_philo *)arg;
    printf("HELLO PHILO: %d THREAD_ID: %ld\n", philo->id, philo->thread_id);
    return (NULL);
}
