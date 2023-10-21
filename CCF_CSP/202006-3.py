import sys


w=int(input())
a=[i[:-1] for i in sys.stdin]
a.append("")
num = 0
# LINE=1
# LIST=2
inList = False
# EMPTY_LINE=3
element= ""

def count(e, w=w):
    c=0
    while(len(e)>w):
        # print(e[:w])                   # debug
        e=e[w:].strip()
        c+=1
    # print(e)                           # debug
    if e != "":
        c+=1
    return c

def count_list(e):
    c=0
    for j in e:
        if j != "":
            c+=count(j, w-3)
        else:
            c+=1
    return c

# only when there is an empty line do we count the paragraph/list above

for i in a:
    if inList:
        if i.startswith("  "):  # follow the last line, ignore 2 spaces
            if i.strip() == "":
                inList = False
                num += count_list(element)
                num += 1
                element = ""
            # add behind
            elif element[-1] == "":
                element[-1] = i[2:].strip()
            else:
                element[-1] += " "+i[2:].strip()
        elif i.startswith("* "):  # another item, also ignore 2 chars
            # add a new line
            element.append(i[2:].strip())
        else:  # a paragraph follows
            inList = False  # list ends
            num += count_list(element)  # count the list above
            num += 1  # add an empty line
            element = i.strip()  # deal with this line
    else:
        if i.startswith("* "):  # start a list
            inList = True
            if element != "":  # not an empty line above
                num += count(element)  # count the paragraph above
                num += 1 # add a line below
            element = [i[2:].strip()]  # save element
            continue
        i=i.strip()  # clear spaces in front
        if i=="":  # an empty line
            if element != "":  # former line is not empty
                num += count(element)
                num += 1
                element = i 
        else:  # add behind the same line
            if element != "":
                element += " "+i
            else:
                element = i
if num == 0:
    print(0)
else:
    print(num-1)