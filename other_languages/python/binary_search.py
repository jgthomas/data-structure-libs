import sys
from shared_sort import sorted_array


def main(args):
    try:
        to_find = int(args[0])
        binary_search(sorted_array, to_find)
    except IndexError:
        print("usage: python binary_search.py n")
        exit(1)


def binary_search(sequence, target):
    low = 0
    high = len(sequence) - 1
    while (high >= low):
        mid = (high + low) // 2
        print(f"Checking position {mid}")
        if target < sequence[mid]:
            high = mid - 1
        elif target > sequence[mid]:
            low = mid + 1
        else:
            print(f"{target} found at position {mid}")
            return
    print(f"{target} not found at any position")


if __name__ == '__main__':
    main(sys.argv[1:])
