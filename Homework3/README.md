## Problem description
Alice and Bob are playing a simple poker game with the following rules:
1. Each player gets $n$ cards from the deck, and all the cards are open to both players.
2. Alice moves first, and then they take turns to play cards.
3. At each move, the current player can only play a card that has the same suit or number as the previous one.
4. A player can pass if and only if there is no suitable card in his/her hand.
5. When a player passes, the next player can play any card in his/her hand.
6. The game stops when one of the players has no more card in his/her hand.
When the game ends, the loser still has some cards at hand, and the total points of these cards indicate how much the loser needs to pay the winner. (A card's points are defined by its number, as explain below.)

During the game, the winner wants to maximize the points of the loser's remaining cards, while the loser want to minimize it. Your mission is to design a stragegy for both players to play optimally, and find out who is the winner and the remaining points of the loser.

A card can be denoted by its suit and number:
1. A suit can be represented by C (club), D (diamond), H (heart), and S (spade).
2. A number can be represented by A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K.
Therefore a card can be represented by a two-character string, such as "DT" (diamond 10) or "SA" (spade A), etc.
Note that a card's points are denoted by its number, such that A -> 1, 2 -> 2, 3 -> 3, ..., 9 -> 9, T -> 10, J -> 11, Q -> 12, K -> 13.

## Input
The first line is a single integer $n$ ( $n \leq 17$), which is the number of cards for each player initially.
The second line lists Alice's cards with $n$ distinct space-separated two-character string.
The third line lists Bob's cards.

## Output
The first line prints the winner, "Alice" or "Bob", without quotes.
The second line is the total remaining points of the loser.

## Sample
#### Sample Input 1
```
3
DQ H2 HA
H3 D6 S3
```

#### Sample Output 1
```
Alice
9
```
#### Sample Input 2
```
15
SJ H9 DT H2 SA D9 S9 H5 SK S6 D8 DA CT S7 H6
C5 CK HQ H8 C9 HK DK S8 SQ CA C4 CQ DJ S4 CJ
```

#### Sample Output 2
```
Alice
11
```
#### Sample Input 3
```
15
SK S5 H4 DT DK H5 H3 SQ S9 D9 C5 C4 CJ H6 C8
D2 SA CQ S3 S2 H7 C6 S8 S7 D6 C7 H2 DQ D3 D5
```

#### Sample Output 3
```
Bob
3
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
