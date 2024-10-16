def modulus_difference(list):
    if not list:
        return None  # IF LIST IS EMPTY
    max_num = max(list)
    min_num = min(list)
    return abs(max_num - min_num)

def main():
    list = input("Enter a list of numbers separated by spaces: ").split()
    list = [int(num) for num in list]  # TO INTS
    result = modulus_difference(list)
    if result is not None:
        print(f"The modulus of the difference of maximum and minimum numbers is: {result}")
    else:
        print("No numbers were entered.")

if __name__ == "__main__":
    main()