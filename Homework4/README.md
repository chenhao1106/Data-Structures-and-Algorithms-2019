## Problem description
Given a string $s$ and an integer $m$, solve the following problems,
1. Find a longest string $t$, so that $t$ is a substring of $s$, and it appears at least $m$ times in $s$.
2. Find a longest string $r$, such that $r$ is a prefix and also a suffix of $s$. Besides, $r$ need to be able to be located somewhere inside the $s$.

## Input
The input contains several test cases.
Each case consists of a line with an integer $m$ ( $m \geq 1$), the minimum number of repetitions, followed by a line containing a string $s$.
All characters in s are lowercase characters from 'a' to 'z'. The last case is denoted by $m = 0$ and should not be processed.

## Output
For each test case, we need to print two lines of answers.
For problem 1, if there is no solution, output "none" without the quotes.
Otherwise, print two integers in a line, separated by a space. The first integer denotes the maximum length of a substring appearing at least m times; the second integer is the right most possible starting position of such a substring.

For problem 2, print the string that meets the requirements. If a suitable string does not exist, then print “Just a legend” without the quotes.

## Sample
#### Sample Input
```
3
abcdabcabc
4
abcdabcabc
3
abcdabcabcd
1
aaaaaaa
2
btcbtcetheth
0
```

#### Sample Output
```
3 7
abc
none
abc
3 7
Just a legend
7 0
aaaaa
3 9
Just a legend
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
