

from shared_sort import int_array


def counting_sort(array):
    counter = [0 for x in range(max(array) + 1)]
    sorted_array = []

    for index, value in enumerate(array):
        counter[value] += 1

    for index, value in enumerate(counter):
        while value > 0:
            sorted_array.append(index)
            value -= 1
    return sorted_array


def main(array):
    counter = [0 for x in range(max(array) + 1)]
    print(f"Original array {array}")
    for index, value in enumerate(array):
        counter[value] += 1
    print(f"Map of array: {counter}")
    print(f"Sorted array: {counting_sort(array)}")


if __name__ == '__main__':
    main(int_array)
