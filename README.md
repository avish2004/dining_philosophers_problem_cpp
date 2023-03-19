# dining_philosophers_problem_cpp
Infamous FAANG Problems

The Dining Philosophers Problem is a classic synchronization problem in computer science that illustrates the challenge of avoiding deadlock and starvation while optimizing the usage of shared resources. In this problem, a group of philosophers sit around a table with a bowl of rice and chopsticks. The philosophers alternate between thinking and eating, but to eat, they need to use two chopsticks, one for each hand. However, there are only as many chopsticks as there are philosophers, so the philosophers must share the chopsticks without creating deadlocks or starving.

One solution to the Dining Philosophers Problem is to use a technique called "Reordering the fork pick-up." In this solution, the philosophers are numbered from 0 to N-1, where N is the number of philosophers. Each philosopher can pick up the chopstick on their left or their right, but they must pick up both chopsticks in a specific order, depending on their philosopher number.

In this implementation, each philosopher is represented by a thread. The forks array is an array of mutexes, where each index represents a chopstick. The philosopher function takes the philosopher's ID as an argument, calculates the indices of their left and right chopsticks, and then uses "Reordering the fork pick-up" to lock the chopsticks in the correct order.

After eating for a random amount of time and releasing the chopsticks, the philosopher thinks for a random amount of time before repeating the cycle. The main function creates a thread for each philosopher and joins them all at the end.

This implementation uses a mutex for each chopstick to ensure that only one philosopher can hold it at a time. By reordering the pick-up of the chopsticks, the implementation avoids the possibility of a deadlock.


Thanks for Reading! Hope my code helps!
