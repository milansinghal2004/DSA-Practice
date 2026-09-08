29-divide-2-int;math;help;leetcode

class Solution {
public:
    int divide(int dividend, int divisor) {
        const long long INT_MAX_VAL = 2147483647;
        const long long INT_MIN_VAL = -2147483648LL;

        long long a = dividend;
        long long b = divisor;
        bool negative = (a < 0) ^ (b < 0);

        a = abs(a);
        b = abs(b);
        long long quotient = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (temp <= a - temp) {
                temp += temp;
                multiple += multiple;
            }

            a -= temp;
            quotient += multiple;
        }

        if (negative)
            quotient = -quotient;

        if (quotient > INT_MAX_VAL)
            return INT_MAX;

        if (quotient < INT_MIN_VAL)
            return INT_MIN;

        return (int)quotient;
    }
};