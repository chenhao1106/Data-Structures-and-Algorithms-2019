#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    multiset<int> s;
    for (int i = 0; i < M; ++i) s.insert(a[i]);

    multiset<int>::iterator k = next(s.begin(), K - 1);
    cout << *k << "\n";
    for (int i = M; i < N; ++i) {
        s.insert(a[i]);
        if (a[i] < *k) --k;
        if (a[i - M] <= *k) ++k;
        s.erase(s.lower_bound(a[i - M]));

        cout << *k << "\n";
    }

    return 0;
}
