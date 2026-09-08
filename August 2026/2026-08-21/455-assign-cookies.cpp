// 455-assign-cookies.cpp;2p;help-syntaxx;leetcode

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int child = 0;
    int cookie = 0;
    int count = 0;

    while (child < g.size() && cookie < s.size()) {

        if (s[cookie] >= g[child]) {
            count++;
            child++;
            cookie++;
        }
        else {
            cookie++;
        }
    }

    return count;
}

int main() {

    int n, m;

    cin >> n;

    vector<int> g(n);

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    cin >> m;

    vector<int> s(m);

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    cout << findContentChildren(g, s);

    return 0;
}