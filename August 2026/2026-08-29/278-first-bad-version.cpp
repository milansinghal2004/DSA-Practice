// 278-first-bad-version.cpp;binary-search;self-leetcode

int firstBadVersion(int n) {
    int left = 1, right = n;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}