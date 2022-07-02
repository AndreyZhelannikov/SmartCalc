from random import randrange, uniform, choice
from math import *

min_number = 0
max_number = 10

list_operator = [
    '+',
    '-',
    '/',
    '**',
    'mod',
]

list_func = [
    'cos(',
    # 'acos(',
    # 'asin(',
    'sin(',
    # 'atan(',
    'tan(',
    # 'sqrt(',
    # 'ln(',
    # 'log(',
]


def get_string(goa=5):
    finaly_string = ''
    for i in range(0, randrange(goa)):
        rand_int = randrange(2)

        if rand_int == 0:
            finaly_string += '' if (randrange(2)) else " "
            finaly_string += str(round(uniform(min_number, max_number), 4))

        elif rand_int == 1:
            finaly_string += str(choice(list_func))
            finaly_string += '' if (randrange(2)) else " "
            finaly_string += get_string(max(goa - 1, 1))
            finaly_string += '' if (randrange(2)) else " "
            finaly_string += ')'
            finaly_string += '' if (randrange(2)) else " "

        finaly_string += '' if (randrange(2)) else " "
        finaly_string += str(choice(list_operator))
        finaly_string += '' if (randrange(2)) else " "

        last = rand_int

    rand_int = randrange(2)
    if rand_int == 0:
        finaly_string += '' if (randrange(2)) else " "
        finaly_string += str(round(uniform(min_number, max_number), 4))

    elif rand_int == 1:
        finaly_string += str(choice(list_func))
        finaly_string += '' if (randrange(2)) else " "
        finaly_string += get_string(max(goa - 1, 1))
        finaly_string += '' if (randrange(2)) else " "
        finaly_string += ')'
        finaly_string += '' if (randrange(2)) else " "

    return finaly_string


def main():
    gopa = get_string()[:255]

    pr_gopa = gopa.replace('**', '^')
    gopa = gopa.replace('mod', '%')

    print(pr_gopa)
    try:
        gopa = eval(gopa)
        print(gopa)
    except Exception as e:
        print("ERROR", e)


if __name__ == '__main__':
    for i in range(1, 100):
        main()
