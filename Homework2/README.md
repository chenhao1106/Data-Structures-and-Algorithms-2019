## Problem description
The length of the longest common prefix of two strings $a[0..m)$ and $b[0..n)$, denoted by $LCP(a, b)$, is the largest integer $k \leq \min\{m,n\}$ such that $a[0..k) = b[0..k)$. In this homework, we need to build a data structure that can compute LCP efficiently.

First of all, we need to construct a large set of strings, as follows.
1. We define that the $0_{th}$ string is a empty string.
2. For the $i_{th}$ string, it is one of previous strings (the $p_{th}$ string where $0 \leq p < i$) with a lower case english letter appended to it.
For example:
1. the first string is “a”, which is the $0_{th}$ string with ‘a’ appended to it.
2. the second string is “ab” , which is the first string with ‘b’ appended to it.
3. the third string is “abc”, which is the second string with ‘c’ appended to it.
4. the forth string is “abd”, which is the second string with ‘d’ appended to it.
Then we have to answer $q$ questions. for every question, we are given two positive integers $i$, $j$, we need to output the $LCP( i_{th} string, j_{th} string )$ in a line.

## Input
The first line contain a single integer $n$ ($n \leq 2 \times 10^5$), which denotes the number of strings.
For the next $n$ line, the $i_{th}$ line decribes the $i_{th}$ string. in $i_{th}$ line , there are an integer $l$ and a character $c$, which means that the $i_{th}$ string is the $l_{th}$ string with $c$ appended to it.
The next line contain a single integer $q$ ($q \leq 5 \times 10^5$), which denotes the number of questions.
in each of next $q$ line, there are two integers $i$, $j$, which means that we are asked to output the $LCP( i_{th}\ string, j_{th}\ string )$.

## Output
For each question, output the answer of it in a line.

## Sample
#### Sample Input
```
10
0 e
0 f
2 f
2 f
2 e
0 e
3 e
2 f
1 f
6 f
10
1 1
8 10
10 9
1 3
10 2
7 2
7 4
1 6
1 5
6 3
```

#### Sample Output
```
1
0
2
0
0
1
2
1
0
0
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
