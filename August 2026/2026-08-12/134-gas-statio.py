# 134-gas-statio.py;array;help

class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """

        totalGas = sum(gas)
        totalCost = sum(cost)
        if totalGas < totalCost:
            return -1

        currGas = 0
        start = 0

        for i in range(len(gas)):
            currGas += gas[i] - cost[i]

            if currGas < 0:
                start = i + 1
                currGas = 0

        return start
        