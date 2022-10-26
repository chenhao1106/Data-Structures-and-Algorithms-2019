#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#define MUL1 127
#define MUL2 139
#define ull unsigned long long
#define sz 100000

ull hashval1[sz + 1], hashval2[sz + 1];  // Hash value of s[1..i + 1]
ull ptable1[sz + 1], ptable2[sz + 1];  // Record MUL ^ i to avoid recomputations.

// Hash value of s[i..i+len]
inline ull hashv(ull hashval[], ull ptable[], int i, int len) {
    return hashval[i + len] - hashval[i] * ptable[len];
}


int main(void) {
    // Precompute MUL ^ i.
    ptable1[0] = ptable2[0] = 1;
    for (int i = 1; i <= sz; ++i) {
        ptable1[i] = ptable1[i - 1] * MUL1;
        ptable2[i] = ptable2[i - 1] * MUL2;
    }

    int m;
    string s;
    cin >> m;
    while (m != 0) {
        cin >> s;
        int n = s.length();  // Length of input string.

        // Precompute hash value of prefix.
        hashval1[0] = hashval2[0] = 0;
        for (int i = 1; i <= n; ++i) {
            hashval1[i] = MUL1 * hashval1[i - 1] + s[i - 1];
            hashval2[i] = MUL2 * hashval2[i - 1] + s[i - 1];
        }

        string ret;
        int start;  // Start index of the rightmost substring which satisfies the condition.
        if (m == 1) {
            ret = s;
            start = 0;
        }
        else {
            // Binary search on the length of substring.
            int l = 1, r = n - 1;
            while (l <= r) {
                int len = (l + r) / 2;

                bool longer = false;
                unordered_map<ull, pair<int, int> > stat;  // key: hash value, value: {count, rightmost start index}
                for (int i = 0; i < n - len + 1; ++i) {
                    ull val = hashv(hashval1, ptable1, i, len);
                    if (stat.find(val) != stat.end()) {
                        unordered_map<ull, pair<int, int> >::iterator iter = stat.find(val);
                        int idx = iter->second.second;
                        // double hash to avoid collision
                        if (hashv(hashval2, ptable2, idx, len) == hashv(hashval2, ptable2, i, len)) {
                            ++iter->second.first;
                            iter->second.second = i;
                            if (iter->second.first >= m) {
                                longer = true;
                                ret = s.substr(i, len);
                                start = i;
                            }
                        }
                    }
                    else stat.insert({val, {1, i}});
                }

                if (longer) l = len + 1;
                else r = len - 1;
            }
        }
        if (!ret.empty()) cout << ret.length() << " " << start << "\n";
        else cout << "none\n";

        ret.clear();

        // Find all the lengths that the prefix substring with the length is also the suffix of string.
        vector<int> v;
        for (int i = 1; i < n; ++i) {
            ull prefix = hashval1[i], suffix = hashv(hashval1, ptable1, n - i, i);
            if (prefix == suffix && hashval2[i] == hashv(hashval2, ptable2, n - i, i))
                v.push_back(i);
        }

        // Binary search on the length of substring.
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int len = v[mid];
            bool longer = false;

            ull prefix = hashval1[len];
            for (int i = 1; i < n - len; ++i) {
                ull val = hashv(hashval1, ptable1, i, len);
                if (prefix == val && hashval2[len] == hashv(hashval2, ptable2, i, len)) {
                    ret = s.substr(i, len);
                    longer = true;
                    break;
                }
            }
            if (longer) l = mid + 1;
            else r = mid - 1;
        }

        if (!ret.empty()) cout << ret << "\n";
        else cout << "Just a legend\n";

        cin >> m;
    }
}
