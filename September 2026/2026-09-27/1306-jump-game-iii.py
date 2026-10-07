# 1306-jump-game-iii.py;math;help;leetcode;redo

class Solution:
    def check(self, start, arr, vis):
        mx = len(arr) - 1

        if start < 0 or start > mx:
            return False

        if arr[start] == 0:
            return True

        if vis[start]:
            return False

        vis[start] = True

        return (self.check(start + arr[start], arr, vis) or self.check(start - arr[start], arr, vis))

    def canReach(self, arr: list[int], start: int) -> bool:
        vis = [False] * len(arr)

        return self.check(start, arr, vis)