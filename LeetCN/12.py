class Solution:
    def intToRoman(self, num: int) -> str:
        
        a = num // 1000
        num -= a*1000
        b = num // 100
        num -= b*100
        c = num // 10
        num -= c*10
        d = num
        res = ''
        for _ in range(a):
            res += "M"
        if b >=5:
            if b == 9:
                res += 'CM'
            else:
                res += 'D'
                res += 'C' *(b-5)
                
        else:
            if b == 4:
                res += 'CD'
            else:
                res += 'C' * b
        if c >= 5:
            if c == 9:
                res += "XC"
            else:
                res += 'L'
                res += 'X' * (c-5)
        else:
            if c == 4:
                res += "XL"
            else:
                res += "X" * c
        if d >= 5:
            if d == 9:
                res += 'IX'
            else:
                res+='V'
                res += "I" * (d-5)
        else:
            if d == 4:
                res += "IV"
            else:
                res += "I" * d
        return res
                
