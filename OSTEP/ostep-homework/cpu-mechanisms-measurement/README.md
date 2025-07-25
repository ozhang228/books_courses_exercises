# Measurement of System Calls

1. Measuring the cost of a system call (reading a 0-byte read)

Timers:
  - gettimeofday()
    - precision / accuracy
      - returns time in microseconds since 1970 but need to see precision
      - it is not precise since it is affected by discontinous jumps in time 
    - rdtsc
      #include <x86intrin.h> and use it like __rdtsc() (compiler instrinsic means it gets replaced at compile time w optimized instructions)

2. Measuring the cost of a context-switching

- lmbench
  - runs two process on the same cpu and setting up two pipes between them
    - first one writes to the first pipe, then waits for the read on the second (blocks first process)
    - second reads from first pipe then writes to the second
  - chains together 
  - recreate somehow using pipes
  - needs sched_setaffinity() to make sure both processes are on the same processor

