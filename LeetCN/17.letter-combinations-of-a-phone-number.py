#
# @lc app=leetcode.cn id=17 lang=python
# @lcpr version=30204
#
# [17] 电话号码的字母组合
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    d = {
        '2':['a', 'b', 'c'],
        '3':['d', 'e', 'f'],
        '4':['g','h','i'],
        '5':['j', 'k', 'l'],
        '6':['m', 'n', 'o'],
        '7':['p', 'q', 'r', 's'],
        '8':['t', 'u', 'v'],
        '9':['w','x','y','z']
    }
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        digits = str(digits)
        res = ['']
        for k in digits:
            tmp = []
            for item in res:
                for ch in self.d[k]:
                    tmp.append(item+ch)
            res = tmp
        return res

        
# @lc code=end



#
# @lcpr case=start
# "23"\n
# @lcpr case=end

# @lcpr case=start
# "2"\n
# @lcpr case=end

#

