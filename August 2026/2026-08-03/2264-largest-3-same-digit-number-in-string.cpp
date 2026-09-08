// 2264-largest-3-same-digit-number-in-string.cpp;string;help

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans= "";
        for(int i = 0;i<=n-3;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                string curr = num.substr(i,3);
                ans = max(ans,curr);                
            }
        }
        return ans;
        
    }
};