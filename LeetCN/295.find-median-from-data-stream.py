#
# @lc app=leetcode.cn id=295 lang=python3
# @lcpr version=30204
#
# [295] 数据流的中位数
#

# @lc code=start
from math import ceil
class MedianFinder:

    def __init__(self):
        self.nums:list[int] = []
        
        

    def addNum(self, num: int) -> None:
        self.nums.append(num)
        self.nums.sort()
        
        

    def findMedian(self) -> float:
        a = len(self.nums)
        if (a %2):
            return self.nums[ceil(a/2)-1]
        else:
            return (self.nums[a/2-1] + self.nums[a/2])/2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
# @lc code=end



