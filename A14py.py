#  Jūlija Tatarinceva, jt22005
#  A14. Dots naturāls skaitlis n. Noteikt, vai n ir pirmskaitlis.
#  Programma izveidota: 2022/09/11

while True:
    isPrime: bool = True #it changes to False if number is not prime and will stay True if no factors are found
    while True:     #protection against incorrect (not int) input | (is it even needed?)
        try:
            n = int(input("Please enter a natural number \n"))
        except ValueError:     #Run this loop in case of incorrect input
            print("Sorry, this isn't a number. Please try again.\n") 
            continue
        else:
            break
    if n < 2:   #prime numbers are greater than one
        print(n, "is not considered prime.")
    else:
        for i in range(2, n):
            if (n % i) == 0:    #if n is divisible by any number between 2 and n, it is not prime
                isPrime = False
                break
        if isPrime:
            print(n, "is a prime number")
        else:
            print (n, "is not a prime number")
    redo = int(input("Would you like to continue(1) or stop(any number) testing? \n"))
    if redo == 1:
        continue
    else:
        print("Testing ended.")
        break

#               Testa plāns
#____________________________________________
#|Ievads|  Rezultāts |Vai pareizs rezultāts?|
#-------|------------|----------------------|
#|  0   |nav pirmsk. |          +           |
#-------|------------|----------------------|
#|  2   |ir pirmsk   |          +           |
#-------|------------|----------------------|
#|  4   |nav pirmsk. |          +           |
#|------|------------|----------------------|
#|  -3  |nav pirmsk. |          +           |
#¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯