n=int(input())

class file:
    def __init__(self, path, size):
        self.path = path
        self.size = size  # 0: dir, else: file
        self.son = set()  # all attrs
        self.ldd = 0  # files below this dir
        self.lrd = 0  # all attrs below
        self.used_size = size  # this folder and files right below this
        self.attr_size = size  # all attr files including used_size

files = {'': file('', 0)}   # root path

for _ in range(n):
    opr = input().split()
    if opr[0] == 'C':
        path = opr[1].split('/')
        full_path = '/'.join(path[:-1])  # the folder path
        size = int(opr[2])
        f = files.get(opr[1])   # if the file already exists
        if f is not None:
            if f.size == 0:  # is a dir not file
                print('N')
                continue
            size -= f.size   # the delta_size
        f = files.get(full_path)  # the final folder
        if f and f.ldd and size + f.used_size > f.ldd:
            print('N')
            continue
        full_path = ''
        err = False
        # check size, check valid path (all folders in path)
        for depth in range(len(path) - 1):  # the path
            full_path += path[depth]
            try:
                f = files[full_path]
            except:
                # create folders afterwards
                files[full_path] = file(full_path, 0)
                s = full_path.split('/')
                s_path = ''
                for j in s[:-1]:
                    s_path += j
                    files[s_path].son.add(full_path)
                    s_path+='/'
                
            else:
                if f.size:
                    # file inside path, not folder
                    err = True
                    break
                if f.lrd and f.attr_size + size > f.lrd:
                    err = True
                    break
            finally:
                full_path += '/'


        if err:
            print('N')
            continue

        f = file(opr[1], int(opr[2]))
        print('Y')
        files[opr[1]] = f
        folder = ''
        for folder_name in path[:-1]:
            folder += folder_name
            files[folder].attr_size += size
            files[folder].son.add(opr[1])
            folder += '/'
        folder = folder[:-1]  # remove final '/'
        files[folder].used_size += size


    elif opr[0] == 'R':
        print('Y')
        if files.get(opr[1]):
            size = files[opr[1]].attr_size
            sons = files[opr[1]].son.copy()
            sons.add(opr[1])
        else:
            continue

        path = opr[1].split('/')
        path.pop()
        full_path = '/'.join(path)
        files[full_path].used_size -= files[opr[1]].size
        while path:
            full_path = '/'.join(path)
            files[full_path].attr_size -= size
            files[full_path].son -= sons
            path.pop()
        for item in sons:
            files.pop(item)
            
    elif opr[0] == 'Q':
        if opr[1] == '/':
            opr[1] = ''
        try:
            f = files[opr[1]]
        except:
            print('N')
            continue
        ld = int(opr[2])
        lr = int(opr[3])
        if (lr and lr < f.attr_size) or (ld and ld < f.used_size) or f.size:
            print('N')
            continue
        else:
            print('Y')
            f.ldd = ld
            f.lrd = lr