## Problem description
Given a sequence of integers, identify the $K$-th smallest integer in a running window of size $M$.

## Input
The first line contains three integers $N$, $M$, $K$ seperated by space.
1. $N$: the total length of the input sequence ( $1 \leq N \leq 200000$).
2. $M$: the size of the running whindow ( $1 \leq M \leq 100000$, $M \leq N$).
3. $K$: we should find the $K$-th smallest integer in the running window ( $1 \leq K \leq M$).
The second line contains a sequence of $N$ integers $a_1$, $a_2$, ..., $a_n$ ( $1 \leq a_i \leq 2137383647$).

## Output
Output the $K$-th smallest integer of each window in one line when the running window is moving from let to right.
There should be $N - M + 1$ integer.

## Sample
#### Sample Input
```
9 5 3
3 4 2 1 5 5 1 1 5
```

#### Sample Output
```
3
4
2
1
5
```

## Usage
#### Compile program
```shell
$ make
```
#### Remove program
```shell
$ make clean
```
