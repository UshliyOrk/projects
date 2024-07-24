def send_message(message):
    letters = {" ":"0", ".":"1", ",":"11", "?":"111", "!":"1111","'":"*", "-":"**", "+":"***", "=":"****", "*":"*-", "#":"#-"}
    numberMessage = " "
    n = 1
    k = 2
    for key in range(10):
        letters[str(key)] = f"{key}-"

    for key in range(26):
        if k == 7 or k == 9:
            if n > 4: 
                n = 1
                k += 1
        else:
            if n > 3 : 
                n = 1
                k += 1
        letters[chr(key+97)] = f"{k}"*n
        n+=1

    flag = False
    for c in message:
        if c.isupper() and not flag:
            flag = True
            numberMessage += "#"
        if flag:
            if c.islower():
                numberMessage += "#"
                flag = False
                numberMessage += letters[c.lower()]
            else:
                if numberMessage[-1] == letters[c.lower()][0]:
                    numberMessage += " "
                numberMessage += letters[c.lower()]
        else:
            if numberMessage[-1] == letters[c.lower()][0]:
                numberMessage += " "
            numberMessage += letters[c.lower()]
            
    return numberMessage[1:]
messages = [
["hey", "4433999"],
["one two three", "666 6633089666084477733 33"],
["Hello World!", "#44#33555 5556660#9#66677755531111"],
["Def Con 1!", "#3#33 3330#222#666 6601-1111"],
["A-z", "#2**#9999"],
["1984", "1-9-8-4-"],
["Big thanks for checking out my kata", "#22#444 4084426655777703336667770222443322255444664066688 806999055282"]
]

for message, answer in messages:
    print(message, send_message(message), answer, sep=" == ")
