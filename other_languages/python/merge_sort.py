# MERGE SORT
#
# recursively implemented, divide and conquer
#
# on input of n elements
#   if n < 2
#     return
#   else
#     sort left half of elements      # by applying merge sort
#     sort right half of elements     # by applying merge sort
#     merge sorted halves
#
#
# ## Worst case: O(n log n)
#
# (At each stage the problem is halved: log(n)
# But each stage also involves a number of comparisons
# that round to O(n))
#


arr = [42, 15, 31, 23, 78, 9, 32, 22]


def merge(left, right):
    left_index = 0
    right_index = 0
    result = []
    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            result.append(left[left_index])
            left_index += 1
        else:
            result.append(right[right_index])
            right_index += 1
    result += left[left_index:]
    result += right[right_index:]
    print(f"merge left and right: {result}")
    return result


def merge_sort(array):
    print(f"array {array}")
    if len(array) <= 1:
        return array
    half = len(array) // 2
    left = merge_sort(array[:half])
    print(f"left = {left}")
    right = merge_sort(array[half:])
    print(f"right = {right}")
    return merge(left, right)
