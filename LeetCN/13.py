class Solution:
    def romanToInt(self, s: str) -> int:
        k = 0
        res = 0
        while k<len(s):
            
            if s[k] == 'M':
                res += 1000
            elif  s[k] == 'D':
                res += 500
            elif s[k] == 'C':
                if k == len(s) - 1:
                    return res + 100
                if s[k+1] in ('D', 'M'):
                    res -= 100
                else:
                    res += 100
            elif s[k] == "L":
                res += 50
            elif s[k] == 'X':
                if k == len(s) -1:
                    return res + 10
                if s[k+1] in ("L", "C"):
                    res -= 10
                else:
                    res += 10
            elif s[k] == 'V':
                res += 5
            else:
                if k == len(s) -1:
                    return res +1
                if s[k+1] in ("V", "X"):
                    res -=1
                else:
                    res+=1
            k+=1
        return res

