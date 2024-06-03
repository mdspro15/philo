# Philosophers
The dining philosophers problem is a famous problem in computer science used to illustlate common issues in concurrent programming.  
For this project we must learn abour concurrent programming and find solution to solve this problem using threads and mutex for mandatory part.<br>

# General rules
+ One or more philosophers sit at round table.
+ There is a large bowl of spaghetti in the middle of table.
+ The spaghetti can only be taken with two forks.
+ There are only as many forks as there are philosophers.
+ Each philosopher eats, sleeps, and thinks.
+ If a philosopher hasn't eaten in a certain timeframe, he will die.
+ Philosphers cannot communicate with each other.

We must keep all philosophers alive, avoid starvation and deadlock.<br>
This program must take some parameters.
+ ```**number_of_philosophers**``` : a number of philosophers and forks.
+ ```**time_to_die**``` : a number representing the time in milliseconds a philosopher has to live after a meal. If a philosopher hasn’t started eating time_to_die milliseconds after the beginning of his last meal or the beginning of the simulation, he will die.
+ **time_to_eat** : a number representing the time in milliseconds a philosopher takes to finish his meal. During that time, the philosopher keeps his two forks in hand.
+ **time_to_sleep** : the time in milliseconds that a philosopher spends sleeping.
+ **number_of_times_each_philosopher_must_eat(optional)** : an optional argument that allows the program to stop if all the philosophers have eaten at least that many times. If this argument is not specified, the simulation carries on unless a philosopher dies.

The programs outputs a message each time a philosopher takes an action, which is formatted this way <br>
```
[timestamp_in_ms] [X] has taken a fork
[timestamp_in_ms] [X] is eating
[timestamp_in_ms] [X] is sleeping
[timestamp_in_ms] [X] is thinking
[timestamp_in_ms] [X] died
```
