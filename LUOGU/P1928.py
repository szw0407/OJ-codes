def process(s):

    num = []
    alpha = []

    for c in s:

        if c.isdigit():
            num.append(c)

        else:
            alpha.append(c)

    num = "".join(num) or "1"
    alpha = "".join(alpha)

    return alpha * int(num)

def decode(s):

    stack = []

    for i, c in enumerate(s):
        if c == "[":
            stack.append(i)
        elif c == "]":
            left = stack.pop()
            s = s[:left] + decode(s[left + 1 : i]) + s[i + 1 :]
            return decode(s)

    return process(s)

if __name__ == "__main__":
    print(decode(input()))
