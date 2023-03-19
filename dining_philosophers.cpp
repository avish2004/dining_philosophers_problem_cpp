//by AV

#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

const int N = 5; // number of philosophers
mutex forks[N]; // array of mutexes for chopsticks

void philosopher(int id)
{
    int left = id;
    int right = (id + 1) % N;

    // reorder the fork pick-up
    if (id % 2 == 0) {
        forks[left].lock();
        forks[right].lock();
    } else {
        forks[right].lock();
        forks[left].lock();
    }

    // eat for a random amount of time
    cout << "Philosopher " << id << " is eating." << endl;
    this_thread::sleep_for(chrono::milliseconds(rand() % 1000));

    // release the chopsticks
    forks[left].unlock();
    forks[right].unlock();

    // think for a random amount of time
    cout << "Philosopher " << id << " is thinking." << endl;
    this_thread::sleep_for(chrono::milliseconds(rand() % 1000));

    // repeat the cycle
    philosopher(id);
}

int main()
{
    // create threads for each philosopher
    thread philosophers[N];
    for (int i = 0; i < N; i++) {
        philosophers[i] = thread(philosopher, i);
    }

    // join the threads
    for (int i = 0; i < N; i++) {
        philosophers[i].join();
    }

    return 0;
}
