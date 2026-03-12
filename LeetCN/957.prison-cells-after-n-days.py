# @lcpr-before-debug-begin
from python3problem957 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=957 lang=python3
# @lcpr version=30204
#
# [957] N 天后的牢房
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from typing import Literal
class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        log:dict[tuple[int], int] = {}
        log2:list[list[int]] = []
        log[tuple(cells)] = 0
        log2.append(cells)
        s = len(cells)
        for i in range(1, n+1, 1):
            new_cells = [0] * s
            for j in range(1, s-1, 1):
                new_cells[j] = (1 if cells[j-1] == cells[j+1] else 0)
            # log[tuple(new_cells)] = i
            cells = new_cells
            if k:=log.get(tuple(cells)):
                l = n - i
                return log2[k + l%(i - k)]
                
            log[tuple(cells)] = i

            log2.append(cells)
        return cells





        
# @lc code=end



#
# @lcpr case=start
# [0,1,0,1,1,0,0,1]\n7\n
# @lcpr case=end

# @lcpr case=start
# [1,0,0,1,0,0,1,0]\n1000000000\n
# @lcpr case=end

#

