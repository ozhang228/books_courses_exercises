# Homework 1

1. Run process-run.py with the following flags: -l 5:100,5:100. What should the CPU utilization be (e.g., the percent of time the CPU is in use?) Why do you know this? Use the -c and -p flags to see if you were right.

**Since both of them are only using the CPU and not using the io, it would be 100%. First there would be 5 cycles of P0 then 5 cycles of P1.**

2. Now run with these flags: ./process-run.py -l 4:100,1:0. These flags specify one process with 4 instructions (all to use the CPU), and one that simply issues an I/O and waits for it to be done. How long does it take to complete both processes? Use -c and -p to find out if you were right.

**First it would complete the first process which would take 4 cycles. Then it would do io, 1 cycle for RUN:io, time waiting for io (ended up being 5), 1 cycle for DONE:io. So at least 6 cycles + however long it takes io.**

3. Switch the order of the processes: -l 1:0,4:100. What happens now? Does switching the order matter? Why? (As always, use -c and -p to see if you were right)

**It should reduce because as the P0 is blocked, the scheduler can run the P1. So it would be P0-RUN:io (1), P1-RUN:cpu(4), P0-BLOCKED(1), P0-DONE:io(1) for a total of 1+4+1+1=7.**

4. We’ll now explore some of the other flags. One important flag is -S, which determines how the system reacts when a process issues an I/O. With the flag set to SWITCH ON END, the system will NOT switch to another process while one is doing I/O, instead waiting until the process is completely finished. What happens when you run the following two processes (-l 1:0,4:100 -c -S SWITCH ON END), one doing I/O and the other doing CPU work?

**It would take the full 11 cycles instead of 7.**

5. Now, run the same processes, but with the switching behavior set to switch to another process whenever one is WAITING for I/O (-l 1:0,4:100 -c -S SWITCH ON IO). What happens now? Use -c and -p to confirm that you are right.

**It would do what happened in question 3 and only take 7 cycles.**

6. One other important behavior is what to do when an I/O completes. With -I IO RUN LATER, when an I/O completes, the process that issued it is not necessarily run right away; rather, whatever was running at the time keeps running. What happens when you run this combination of processes? (./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH ON IO -c -p -I IO RUN LATER) Are system resources being effectively utilized?

**It prioritizes the processes that were ready faster so its actually not being effectively utilized because if IO could be done right after it was completed, we could have done IO at the same tame as P2 and P3 cpu instructions.**

7. Now run the same processes, but with -I IO RUN IMMEDIATE set,
   which immediately runs the process that issued the I/O. How does
   this behavior differ? Why might running a process that just completed an I/O again be a good idea?

**We shorten the amount of cycles needed by 10 (by doing 10 IO waiting blocks at the same time as P2 and P3). We also get 100% utilization of CPU and much higher IO usage. Running a process that completed an I/O again is a good idea because generally if a process is doing I/Os it is more likely they will do so in the future.**

8. Now run with some randomly generated processes using flags -s 1 -l 3:50,3:50 or -s 2 -l 3:50,3:50 or -s 3 -l 3:50, 3:50. See if you can predict how the trace will turn out. What happens when you use the flag -I IO_RUN_IMMEDIATE versus that flag -I IO_RUN_LATER? What happens when you use the flag -S SWITCH_ON_IO versus -S SWITCH_ON_END?

# ./process-run.py -s 1 -l 3:50,3:50 
P0: cpu, io, io
P1: cpu, cpu, cpu

## -I Immediate vs Later

**Immediate**
CPU IO
 P0  -
 P0  -
 P1 P0
 P1 P0
 P1 P0
  - P0
  - P0 
 P0  -
 P0  -
  - P0
  - P0
  - P0
  - P0
  - P0
 P0  -

15 Cycles
8/15 CPU 
10/15 IO

## -S On IO vs On End
- on IO will save three cycles vs end because of the three that are parallel processed (3-5).

# -s 2 -l 3:50,3:50 
- P0: io, io, cpu
- P1: cpu, io, io

Got this one wrong because you can have more than 1 IO every cycle. The only thing that changes cycle number is switch on end because there is a lot of parallel processing that is possible here.





