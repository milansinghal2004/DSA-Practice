// 223-rectangle-area.cpp;math;leetcode

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);

        int area2 = (bx2 - bx1) * (by2 - by1);

        int overlapLeft = max(ax1, bx1);
        int overlapRight = min(ax2, bx2);

        int overlapBottom = max(ay1, by1);
        int overlapTop = min(ay2, by2);

        int overlap = 0;

        if (overlapLeft < overlapRight &&
            overlapBottom < overlapTop) {

            overlap = (overlapRight - overlapLeft) * (overlapTop - overlapBottom);
        }

        return area1 + area2 - overlap;
    }
};