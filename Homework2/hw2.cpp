#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Node {
    // binary lifting, the maximum depth will not exceed 200000 -> ceil(log2(200000)) = 18
    Node (int depth=0)
        : depth{depth}, parIdx(18, -1), child(26, -1) {}  

    int depth;
    vector<int> parIdx;
    vector<int> child;
};


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n;
    vector<Node> trie;  // Vector implementation of trie.
    vector<int> strLast(n + 1);  // Trie node of the last character of the string.
    trie.push_back(Node());  // Trie root.
    strLast[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int idx;
        char c;
        cin >> idx >> c;
        if (trie[strLast[idx]].child[c - 'a'] == -1) {
            trie[strLast[idx]].child[c - 'a'] = trie.size();
            trie.push_back(Node(trie[strLast[idx]].depth + 1));

            // Set 2^i-th ancestor in parIdx of the node. (binary lifting)
            trie.back().parIdx[0] = strLast[idx];
            for (int cnt = 1; cnt <= log2(trie.back().depth); ++cnt)
                trie.back().parIdx[cnt] = trie[trie.back().parIdx[cnt - 1]].parIdx[cnt - 1];
        }
        strLast[i] = trie[strLast[idx]].child[c - 'a'];
    }

    cin >> q;
    int s1, s2;
    for (int i = 0; i < q; ++i) {
        cin >> s1 >> s2;
        s1 = strLast[s1];
        s2 = strLast[s2];
        if (trie[s1].depth < trie[s2].depth) swap(s1, s2);

        // Let s1 jump to the same depth with s2.
        int cnt = log2(trie[s1].depth);
        while (cnt >= 0) {
            if (trie[trie[s1].parIdx[cnt]].depth >= trie[s2].depth) {
                s1 = trie[s1].parIdx[cnt];
                cnt = log2(trie[s1].depth);
                --cnt;
            }
            else --cnt;
        }

        // Trivial method. (Jump to parent each time.)
        // while (s1 != s2) {
        //     s1 = trie[s1].parIdx[0];
        //     s2 = trie[s2].parIdx[0];
        // }

        while (s1 != s2) {
            // Binary search on 2^i-th ancestor.
            // Jump to the farthest 2^i-th ancestor that is not the common ancestor.
            int l = 0, r = log2(trie[s1].depth);
            while (l <= r) {
                int mid = (l + r) / 2;
                if (trie[s1].parIdx[mid] == trie[s2].parIdx[mid]) r = mid - 1;
                else l = mid + 1;
            }
            // LCA is their parent.
            if (l == 0) {
                s1 = trie[s1].parIdx[0];
                s2 = trie[s2].parIdx[0];
                break;
            }
            s1 = trie[s1].parIdx[l - 1];
            s2 = trie[s2].parIdx[l - 1];
        }

        cout << trie[s1].depth << "\n";
    }
}
