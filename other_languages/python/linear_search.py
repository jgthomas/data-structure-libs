import sys
from shared_sort import int_array


def main(args):
    try:
        to_find = int(args[0])
        linear_search(int_array, to_find)
    except IndexError:
        print("usage: python linear_search.py n")
        sys.exit(1)


def linear_search(sequence, target):
    print("Linear Search")
    for index, value in enumerate(sequence):
        print(f"Checking position {index}")
        if value == target:
            print(f"Found at position {index}")
            return
    print(f"{target} not found at any position")


if __name__ == '__main__':
    main(sys.argv[1:])
