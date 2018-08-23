def fibonacci(number):
    a = 1
    b = 1
    print(a)
    print(b)
    for i in range(int(number) - 2):
        c = a + b
        a = b
        b = c
        print(c)

number = input('enter the length of series : ')
fibonacci(number)