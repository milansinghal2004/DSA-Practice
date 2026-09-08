// 123-best-tym-to-but-sell-stock-iii.cpp;array;help;leetcode

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int b1 = INT_MIN;
    int b2 = INT_MIN;
    int s1 = 0, s2 = 0;

    for(price : prices) {
        b1 = max(b1, -price);
        s1 = max(s1, b1 + price);

        b2 = max(b2, sell - price);
        s2 = max(s2, b2 + price);
    }

    return s2;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices) << endl;

    return 0;
}