def next_smaller(n):
    number = str(n)
    if len(number) == 1:
        return -1
    flag = True
    for i in range(len(number)-1):
        if int(number[i]) > int(number[i+1]):
            flag = False
            break
    if flag:
        return -1
    
        
    result = -1
    for i in range(n-1, 10**(len(number)-1), -1):
        preRes = str(i)
        for digit in number:
            preRes = preRes.replace(digit, "", 1)
        if len(preRes) == 0:
            result = i
            break
        
    return result

#slow(((
print(next_smaller(1023456789))
