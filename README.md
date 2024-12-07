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
- **Makefile Rules:** NAME, all, clean, fclean, re
- **Input Arguments:**
  - `number_of_philosophers`: Number of philosophers and forks.
  - `time_to_die (ms)`: If a philosopher doesn’t eat in this time span, they die.
  - `time_to_eat (ms)`: Time it takes for a philosopher to eat.
  - `time_to_sleep (ms)`: Time a philosopher spends sleeping.
  - `[number_of_times_each_philosopher_must_eat]` (optional): If all philosophers eat this many times, the simulation ends.
  
- **Allowed Functions:** `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- **Libft:** Not authorized

---

## Core Mechanics

Your mission is both philosophical and practical:
1. **Initialize Philosophers & Forks:** Each philosopher is a thread, and each fork is a shared resource protected by a mutex.
2. **Simulate Life Cycles:** Philosophers continuously cycle through eating, sleeping, and thinking states.
3. **Avoid Starvation:** Ensure that all philosophers get to eat in a timely manner.
4. **Detect Death or Completion:** If a philosopher fails to eat before `time_to_die` expires, the simulation ends. If a certain number of meals is reached by all philosophers (if specified), the simulation also concludes.

Log messages appear as:
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

These timestamps and philosopher IDs keep you informed of every crucial event.

---

## Bonus Features

For those who go above and beyond, the bonus part of the project may include refined synchronization techniques or alternative solutions to ensure an even more robust and efficient simulation. By tackling these bonuses, I’ve further enriched the learning experience and honed my understanding of concurrency challenges.

---

## Getting Started

**Ready to explore the minds and stomachs of philosophers?** Here’s how:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/korberlin/philosophers.git
   cd philosophers
   ```

2. **Build the Project:**
   ```bash
   make
   ```
   Once compiled, you’ll have the `philo` executable ready to run.

3. **Run the Simulation:**
   ```bash
   ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
   ```
   
   Example:
   ```bash
   ./philo 5 800 200 200
   ```
   This starts a simulation with 5 philosophers, who die if they don’t eat within 800 ms, spend 200 ms eating, and 200 ms sleeping, continuing until one dies.

---

## Contributing

Have ideas for improvements or new strategies to handle concurrency pitfalls? Contributions are always welcome! Feel free to open issues, propose enhancements, or submit pull requests. Together, let’s make **philosophers** even more insightful and efficient.

---

**Thank you for exploring my philosophers project!** May your journey into concurrency be filled with enlightenment, careful timing, and profound insights. Enjoy observing this delicate balance and learn from these philosophical diners! 🥢
