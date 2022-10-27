#include <iostream>
#include <unordered_map>
using namespace std;

#define ull unsigned long long

typedef struct card{
    int suit = 0;
    int num = 0;
}Card;

inline int setSuit(char c) {
    switch (c) {
        case 'C': return 0;
        case 'D': return 1;
        case 'H': return 2;
        case 'S': return 3;
    }
    return 0;
}

inline int setNum(char c) {
    switch(c) {
        case 'A': return 1;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        default: return c - '0';
    }
    return 0;
}

bool cmpSuit(ull state, int c) {
    state = (state >> 22) & 0b11;
    return static_cast<int>(state) == c;
}

bool cmpNum(ull state, int n) {
    state = (state >> 18) & 0b1111;
    return static_cast<int>(state) == n;
}

inline ull changeTurn(ull state) {
    return state ^ (1 << 24);
}

inline ull setPrevCard(ull state, int suit, int num) {
    state &= ~(0x3F << 18);
    state |= (suit << 22) | (num << 18);
    return state;
}

int dfs(ull state, int alpha, int beta, Card cards[2][17], unordered_map<ull, int>& memo) {
    int score = 0, nscore;
    if (((state >> 42) & 0x1FFFF) == 0) {
        for (int i = 0; i < 17; ++i)
            if ((state & (1ull << (41 - i))) != 0)
                score += cards[1][i].num;
        return score;
    }
    if (((state >> 25) & 0x1FFFF) == 0) {
        for (int i = 0; i < 17; ++i)
            if ((state & (1ull << (58 - i))) != 0)
                score -= cards[0][i].num;
        return score;
    }
    if (memo.find(state) != memo.end()) return memo[state];

    if ((state & (1ull << 24)) == 0) {
        score = -230;
        bool play = false;
        for (int i = 0; i < 17; ++i) {
            if ((state & (1ull << (58 - i))) != 0 && ((state & (0xF << 18)) == 0 || cmpSuit(state, cards[0][i].suit) || cmpNum(state, cards[0][i].num))) {
                play = true;
                ull tmp = state;
                tmp &= ~(1ull << (58 - i));  // Unset used card.

                tmp = setPrevCard(tmp, cards[0][i].suit, cards[0][i].num);
                tmp = changeTurn(tmp);

                // Update alpha in state.
                tmp &= ~(0x1FFull << 9);
                tmp |= ((alpha & 0x1FFull) << 9);
                nscore = dfs(tmp, alpha, beta, cards, memo);
                if (nscore > score) score = nscore;
                if (score > alpha) alpha = score;
                if (alpha >= beta) break;
            }
        }

        if (!play) {
            ull tmp = state;
            tmp = setPrevCard(tmp, 0, 0);
            tmp = changeTurn(tmp);
            score = dfs(tmp, alpha, beta, cards, memo);
        }
        memo[state] = score;
    }
    else {
        score = 230;
        bool play = false;
        for (int i = 0; i < 17; ++i) {
            if ((state & (1ull << (41 - i))) != 0 && ((state & (0xFull << 18)) == 0 || cmpSuit(state, cards[1][i].suit) || cmpNum(state, cards[1][i].num))) {
                play = true;
                ull tmp = state;
                tmp &= ~(1ull << (41 - i));

                tmp = setPrevCard(tmp, cards[1][i].suit, cards[1][i].num);
                tmp = changeTurn(tmp);

                tmp &= ~(0x1FFull);
                tmp |= (beta & 0x1FFull);
                nscore = dfs(tmp, alpha, beta, cards, memo);
                if (nscore < score) score = nscore;
                if (score < beta) beta = score;
                if (alpha >= beta) break;
            }
        }

        if (!play) {
            ull tmp = state;
            tmp = setPrevCard(tmp, 0, 0);
            tmp = changeTurn(tmp);
            score = dfs(tmp, alpha, beta, cards, memo);
        }
        memo[state] = score;
    }
    return memo[state];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Each player has less than or equal to 17 cards.
    Card cards[2][17];

    int n;
    cin >> n;
    // state compresstion with using unsigned long long
    // | 58                  42 | 41 25 | 24   | 23     18 | 17  9 | 8  0 |
    // |Alice's remaining cards | Bob's | turn | prev card | alpha | beta |
    ull state = 0;
    char suit, num;
    for (int p = 0; p < 2; ++p) {
        for (int i = 0; i < n; ++i) {
            cin >> suit >> num;
            cards[p][i].suit = setSuit(suit);
            cards[p][i].num = setNum(num);
            state |= (1ull << (((p == 0) ? 58 : 41) - i));
        }
    }
    state |= ((-230 & 0x1FF) << 9) | 230;  // Set alpha & beta.
    
    unordered_map<ull, int> memo;  // memoization
    int score = dfs(state, -230, 230, cards, memo);
    if (score >= 0) cout << "Alice\n" << score;
    else cout << "Bob\n" << -score;

    return 0;
}
