// 739 leetcode daily-temperatures.cpp;stack;array;complete-help-restudy

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *stack = (int*)malloc(temperaturesSize* sizeof(int));
    int *answer = (int*)malloc(temperaturesSize* sizeof(int));
    int top = -1;
    for(int i = 0; i < temperaturesSize; i++) {
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int pre = stack[top--];
            answer[pre] = i - pre;
        }
        stack[++top] = i;
    }
    while(top >= 0) {
        answer[stack[top--]] = 0;
    }
    *returnSize = temperaturesSize;
    return answer;
}
