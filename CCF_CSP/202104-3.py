N,Tdef, Tmax, Tmin, H = input().split()
N = int(N)
Tmax = int(Tmax)
Tmin = int(Tmin)
Tdef = int(Tdef)

n = int(input())

OCCUPIED = 1
RESERVED = 2
FREE = 0


occupation = [None] * (N+1)
timeout = [0] * (N+1)
status = [FREE] * (N+1)


for _ in range(n):
    line = input().split()
    if line[2] != H and line[2] != '*' and line[3] != 'REQ':
        continue
    if line[3] != 'DIS' and line[3] != 'REQ':
        continue
    if line[2] == '*' and line[3] != 'DIS':
        continue
    if line[2] == H and line[3] == 'DIS':
        continue

    time = int(line[0])
    
    if line[3] == 'DIS':
        ip = None
        if line[1] in occupation:
            ip = occupation.index(line[1])
        else:
            for _ip in range(1,N+1):
                if status[_ip] == RESERVED and timeout[_ip] <= time:
                    ip = _ip
                    status[_ip] = FREE
                    timeout[_ip] = 0
                    occupation[_ip] = None
                    break
                if occupation[_ip] is None:
                    ip = _ip
                    break
            if ip is None:
                for _ip in range(1,N+1):
                    if timeout[_ip] <= time:
                        ip = _ip
                        break
            if ip is None:
                continue
        occupation[ip] = line[1]
        status[ip] = RESERVED
        timeout_exp = int(line[-1])
        if timeout_exp == 0:
            timeout[ip] = Tdef + time
        elif timeout_exp - time > Tmax:
            timeout[ip] = Tmax + time
        elif timeout_exp - time < Tmin:
            timeout[ip] = Tmin + time
        else:
            timeout[ip] = timeout_exp
        print(f'{H} {line[1]} OFR {ip} {timeout[ip]}')
    elif line[3] == 'REQ':
        ip = int(line[4])
        if line[2] != H:
            if line[1] in occupation:
                _ip = occupation.index(line[1])
                if status[_ip] == RESERVED:
                    status[_ip] = FREE
                    timeout[_ip] = 0
                    occupation[_ip] = None
            continue
        
        if ip not in range(1, 1+N) or occupation[ip] != line[1] or occupation[ip] == line[1] and status[ip] == RESERVED and timeout[ip] <= time:
            print(f'{H} {line[1]} NAK {ip} 0')
            continue
        status[ip] = OCCUPIED
        timeout_exp = int(line[-1])
        if timeout_exp == 0:
            timeout[ip] = Tdef + time
        elif timeout_exp - time > Tmax:
            timeout[ip] = Tmax + time
        elif timeout_exp - time < Tmin:
            timeout[ip] = Tmin + time
        else:
            timeout[ip] = timeout_exp
        print(f'{H} {line[1]} ACK {ip} {timeout[ip]}')
    