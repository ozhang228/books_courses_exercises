
1. `./fork.py -s 10` and predict

```sh
Process Tree:
  a

Action: a forks b
Process Tree?
  a
  └─b

Action: a forks c
Process Tree?
  a
  └─b
  └─c

Action: c EXITS
Process Tree?
  a
  └─b

Action: a forks d
Process Tree?
  a
  └─b
  └─b

Action: a forks e
Process Tree?
  a
  └─b
  └─d
  └─e
```

2. Fork Percentage (higher means more likely for it to be a fork vs exit), as it increases, how will the tree look?

The tree will have a heigher height as FP increases. It will be shorter for exit.

3. -t for the opposite
```sh
Process Tree:
  a

Action? a fork b
                               a
                               └── b
Action? b fork c
                               a
                               └── b
                                   └── c
Action? c fork d
                               a
                               └── b
                                   └── c
                                       └── d
Action? d exits
                               a
                               └── b
                                   └── c
Action? a fork e
                               a
                               ├── b
                               │   └── c
                               └── e
```

4. What happens when a child exits? What happens to its children processes? 
`./fork.py -A a+b,b+c,c+d,c+e,c-.` 
This example has process ’a’ create ’b’, which in turn creates ’c’, which then creates ’d’ and ’e’. However, then, ’c’ exits. What do you think the process tree should like after the exit? What if you use the -R flag (reparent to local parent)? Learn more about what happens to orphaned processes on your own to add more context.

It would just leave them orphaned there. In that case I assume they would die off without a parent. -R would make it so they get put to the next closest.

They actually get reassigned to the root. Then I would assume -R would make it the parent of the exited process.


5. Try with -F

```sh
        Process Tree:
              a

Action: a forks b
Action: a forks c
Action: c EXITS
Action: a forks d
Action: a forks e

                        Final Process Tree?

        a
        - b
        - d
        - e
```

6. -F and -t. There are times when you can't really determine. For example when processes die, they reassigne their orphaned children to the root. So it would be hard to tell if a forked a process or if it was a reassigned orphan.

```sh
                           Process Tree:
                               a

Action? a forks b
Action? b forks c 
Action? b forks d 
Action? b forks e
Action? a forks f

                        Final Process Tree:
                               a
                               ├── b
                               │   ├── c
                               │   ├── d
                               │   └── e
                               └── f

```
