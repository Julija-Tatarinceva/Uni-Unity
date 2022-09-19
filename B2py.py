#  Jūlija Tatarinceva, jt22005
#  B2. Dots naturāls skaitlis n < 1000. Izdrukāt doto skaitli romiešu pierakstā.
#  Programma izveidota: 2022/09/13
romanNumber: str = "" #this will be filled with roman symbols
RomanSymbols = ["CDM", "XLC", "IVX"] #first str is used to convert hundreds, second - dozens and the last one - units

def Converter(numToConvert, symbolsUsed):
    romanPart: str = "" #needs to be cleared each time the function is called
    if numToConvert == "5":
        romanPart = symbolsUsed[1]
    elif numToConvert == "4":
        romanPart = symbolsUsed[0] + symbolsUsed[1]
    elif numToConvert == "9":
        romanPart = symbolsUsed[0] + symbolsUsed[2]
    elif int(numToConvert) < 5:
        for i in range(1, int(numToConvert)+1):
            romanPart = romanPart + symbolsUsed[0]
    elif (int(numToConvert) > 5):
        romanPart = symbolsUsed[1]
        for i in range(1, int(numToConvert)-4):
            romanPart = romanPart + symbolsUsed[0]
    return romanPart

while True:
        romanNumber = ""
        while True: #protection against logically incorrect input
            n = int(input("Please enter a natural number \n"))
            if n > 0 and n < 1000: 
                break
            else:
                print ("Can not be converted")
        numberOfChars = len(str(n))
        for i in range(0, numberOfChars): #converter is called to convert every symbol separately
            if numberOfChars == 2:
                useSymbols = RomanSymbols[i+1] #skipping hundreds
            elif numberOfChars == 1:
                useSymbols = RomanSymbols[i+2] #skipping dozens
            else:
                useSymbols = RomanSymbols[i]
            romanNumber = romanNumber + Converter(str(n)[i], useSymbols)
        print(romanNumber)
        redo = input("Would you like to continue(1) or stop(any key) testing? \n")
        if redo == "1":
            continue
        else:
            break
#                   Testa plāns
#_________________________________________________
#|Ievads|      Rezultāts       |Vai pareizs rez.?|
#-------|----------------------|-----------------|
#|  0   | can not be converted |        +        |
#-------|----------------------|-----------------|
#|  8   | VIII                 |        +        |
#-------|----------------------|-----------------|
#|  25  | XXV                  |        +        |
#-------|----------------------|-----------------|
#| 999  | CMXCIX               |        +        |
#¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
