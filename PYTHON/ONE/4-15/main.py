def merge_sort(arr):
    if len(arr) > 1:
        # Finding the middle of the array
        mid = len(arr) // 2

        # Dividing the array into two halves
        left_half = arr[:mid]
        right_half = arr[mid:]

        # Recursively sort both halves
        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        # Merge the sorted halves
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def main():
    # Getting input from the user
    user_input = input("Enter numbers separated by spaces: ")
    
    # Converting the input string into a list of integers
    arr = list(map(int, user_input.split()))
    
    print("Given array is:", arr)
    
    # Sorting the array using merge sort
    merge_sort(arr)
    
    print("Sorted array is:", arr)

if __name__ == "__main__":
    main()