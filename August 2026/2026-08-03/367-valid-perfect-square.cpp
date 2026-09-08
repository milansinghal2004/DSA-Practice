// 367 leetcode valid-perfect-square.cpp;maths;help

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(num>0){
            num -= i;      
            i +=2;         
            if(!num) return true;
        }
        return false;
    }
};