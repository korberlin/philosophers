# philosophers

![philosophers Cover](img/cover-philosophers.png)

Welcome, curious thinkers and concurrency enthusiasts! I’m excited to share my journey through the **philosophers** project at 42 Berlin. This endeavor explores the intricate world of concurrent programming, synchronization, and timing, all wrapped in a classic scenario: philosophers sitting around a table, pondering existence, and trying not to starve.

![philosophers Passed with Bonus](img/philosopherse.png)

---

## About

**philosophers** isn’t just another coding assignment; it’s a dive into the complexities of threads, mutexes, and resource-sharing protocols. By simulating a group of philosophers who eat, think, and sleep, I’ve enhanced my understanding of:

- **Thread Management & Synchronization:** Creating a thread for each philosopher and ensuring safe access to shared resources (forks) using mutexes.
- **Timing & Scheduling:** Applying rules like `time_to_die`, `time_to_eat`, and `time_to_sleep` to keep each philosopher’s lifecycle in harmony.
- **Deadlock Prevention & Resource Allocation:** Avoiding conditions where no one can eat, ensuring philosophers always have a chance to survive.
- **Data Race Avoidance:** Designing the program to run cleanly without data races, thanks to careful locking of shared data.

All this logic comes to life on **Linux** systems, ensuring portability and reliability.

---

## Project Highlights

- **Program Name:** `philo`
- **Files Submitted:** Makefile, *.h, *.c (in the `philo/` directory)
- **Makefile Rules:** `NAME`, `all`, `clean`, `fclean`, `re`
- **Input Arguments:**
  - `number_of_philosophers`: Number of philosophers (and forks)
  - `time_to_die (ms)`: Time before a philosopher who hasn’t eaten dies
  - `time_to_eat (ms)`: Eating duration
  - `time_to_sleep (ms)`: Sleeping duration
  - `[number_of_times_each_philosopher_must_eat]` (optional): End condition if all eat this many times
  
- **Allowed Functions:** `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- **Libft:** Not authorized

---

## Core Mechanics

Your mission is both philosophical and practical:
1. **Initialize Philosophers & Forks:** Each philosopher is a thread, and each fork is protected by a mutex.
2. **Simulate Life Cycles:** Philosophers cycle through eating, sleeping, and thinking states.
3. **Maintain Balance:** Ensure no philosopher starves and that resources (forks) are fairly allocated.
4. **Termination Conditions:** The simulation ends if a philosopher dies from not eating in time, or if all have eaten the required number of times (if specified).

**Log Format:**
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

---

## Bonus Features

For those who seek deeper challenges, implementing refined synchronization or alternative approaches can earn you bonus points. Exploring these extras enhances your understanding of concurrency subtleties.

---

## Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/korberlin/philosophers.git
   cd philosophers
   ```

2. **Build the Project:**
   ```bash
   make
   ```
   After compilation, you’ll have the `philo` executable ready to run.

3. **Run the Simulation:**
   ```bash
   ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
   ```
   
   Example:
   ```bash
   ./philo 5 800 200 200
   ```
   Under these conditions, no philosopher should die.

---

## Sample Test Cases

Try out these scenarios to validate the behavior of the simulation:

| Command                     | Expected Outcome                          |
|-----------------------------|--------------------------------------------|
| `./philo 5 800 200 200`     | No philosopher should die                 |
| `./philo 1 800 200 200`     | Philosopher will die (only one fork)      |
| `./philo 5 800 200 200 7`   | Ends after all have eaten 7 times (no die)|
| `./philo 4 310 200 100`     | A philosopher should die due to timing     |
| `./philo -5 600 200 200`    | Invalid input, should error and not run    |

These tests give a quick overview of different edge cases, from invalid inputs to scenarios where philosophers survive indefinitely or fail due to stringent timings.

---

## Contributing

Have ideas to improve the logic or enhance the simulation? Contributions are always welcome! Open an issue or submit a pull request. Let’s refine **philosophers** together and push the boundaries of concurrent programming.

---

**Thank you for exploring my philosophers project!** May this journey into concurrency, resource sharing, and timing deepen your understanding of what it takes to keep philosophical minds (and empty stomachs) in perfect harmony. 🥢
