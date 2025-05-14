# Philosophers - 42 Amman Concurrency Project

A multithreaded simulation of the classic Dining Philosophers problem focusing on synchronization, timing accuracy, and thread-safe resource sharing.

## Project Overview
Philosophers is a concurrency-based simulation where multiple philosophers sit at a round table with a shared bowl of spaghetti and forks. Each philosopher alternates between thinking, eating, and sleeping. The challenge lies in properly synchronizing their access to forks (shared resources) to avoid deadlocks and starvation while ensuring thread safety.

## Key Features
- Thread-based simulation using `pthread`
- Strict timing constraints and death detection
- No use of global variables
- Accurate, non-overlapping logging system
- Optional argument to define eating quotas
- Bonus version with more advanced concurrency models

## What I Learned 🧠

### Concurrency Fundamentals
- Implemented multithreaded behavior using POSIX threads
- Managed simultaneous access to shared resources (forks)
- Understood the risk of deadlocks and how to prevent them
- Used mutexes for mutual exclusion and thread safety

### Synchronization Techniques
- Ensured ordered and atomic log printing
- Managed timing-sensitive operations for realistic simulation
- Implemented precise delay control using `usleep` or `nanosleep`

### Time & State Management
- Tracked philosopher states across eating, sleeping, and thinking cycles
- Detected starvation within a `time_to_die` threshold
- Recorded and formatted timestamps in milliseconds

### Program Design Constraints
- Avoided use of global variables by structuring clean and modular code
- Handled optional arguments gracefully for simulation customization
- Ensured simulation termination conditions were met accurately

### Debugging & Race Condition Avoidance
- Verified no data races through mutex-protected structures
- Debugged timing inaccuracies and overlap in logs
- Ensured the death message appears within 10 ms of actual death
