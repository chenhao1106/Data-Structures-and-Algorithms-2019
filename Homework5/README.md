## Problem description
Given a graph paper of size $N$ by $M$, each grid is either O or X.
In each step, we can only select a piece of graph paper with more than one column/row and choose one of the columns/rows filled with only O. Then delete the column/row. After performing a operation, that piece may become two pieces.
We can perform the operation as many times as we want.
The following demonstrates a viable way to tear the paper.
```
N = 4, M = 6
The graph paper looks like:
OOOOOO
OOOXXX
XXOOOO
OOOOOO

1. Choose the only piece, delete the third column, and there are two pieces now.
OO_OOO
OO_XXX
XX_OOO
OO_OOO

2. Choose the right piece, delete the third row of it, and there are three pieces now.
OO_OOO
OO_XXX
XX____
OO_OOO

3. Choose the upper right piece, delete the first row of it, and there are still three pieces.
OO____
OO_XXX
XX____
OO_OOO

......(perform more operations and stop at any time)

```
Calculate the number of ways to tear it.
(Two ways of tearing a graph paper are not regarded as the same if and only if there is a $i_{th}$ such that the grids we delete are not identical in $i_{th}$ step in two ways.)

## Input
The first line contains two integers $N$, $M$ which represent the size of the graph paper ( $1 \leq N, M \leq 10$).
Each of the next $N$ lines contains $M$ characters, which represents graph.

## Output
Print the number of ways to tear the graph paper modulo $10^9+7$.

## Sample
#### Sample Input 1
```
1 2
OO
```

#### Sample Output 1
```
3
```
#### Sample Input 2
```
2 2
OO
OX
```

#### Sample Output 2
```
5
```
#### Sample Input 3
```
5 5
OOOOO
OOOOO
OOOOO
OOOOO
OOOOO
```

#### Sample Output 3
```
582176824
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
