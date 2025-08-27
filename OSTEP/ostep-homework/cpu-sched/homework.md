# Homework

1. Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers.

Job 0 ( length = 200)
Job 1 ( length = 200)
Job 2 ( length = 200)

# FIFO 

- Turnaround Time

(200 + 400 + 600) / 3 == 400

- Response Time

(0 + 200 + 400) / 3 == 200

# SJF

- Turnaround Time

(200 + 400 + 600) / 3 == 400

- Response Time

(0 + 200 + 400) / 3 == 200

2. Now do the same but with jobs of different lengths: 100, 200, and 300.

# FIFO 
  Job 0 ( length = 100)
  Job 1 ( length = 200)
  Job 2 ( length = 300)

- Turnaround Time

(100 + 300 + 600) / 3 == 333.3

- Response Time

(0 + 100 + 300) / 3 == 133.3

# SJF

- Turnaround Time

(100 + 300 + 600) / 3 == 333.3

- Response Time

(0 + 100 + 300) / 3 == 133.3

3. Now do the same, but also with the RR scheduler and a time-slice of 1.

# 200, 200, 200

- Turnaround time
   
(598 + 599 + 600) / 3 == 599

- Response Time

(0 + 1 + 2) / 3 == 1

# 100, 200, 300 

- Turnaround time
   
(298 + 499 + 600) / 3 == (1397 / 3)

- Response Time

(0 + 1 + 2) / 3 == 1

4. For what types of workloads does SJF deliver the same turnaround times as FIFO?

For workloads that either come in sorted (shortest first) which also includes those that have the same process time.

5. For what types of workloads and quantum lengths does SJF deliver the same response times as RR?
  
When the average running time of a process in SJF is equal to the quantum length

6. What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend?

Response time goes down.

7. What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?

It goes down.

q = quantum length
N = number of jobs 

((n / 2) * q) / n




