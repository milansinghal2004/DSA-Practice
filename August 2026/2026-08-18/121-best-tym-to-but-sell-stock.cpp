// 121-best-tym-to-but-sell-stock.cpp;array;fun-alone;leetcode

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minP = INT_MAX;
    int maxP = 0;

    for(int price : prices) {
        if(price < prices) {
            minP = price;
        } else if(price - minP > maxP) {
            maxP = price - minP;
        }
    }

    return maxP;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices) << endl;

    return 0;
}
