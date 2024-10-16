def calculate_remainder(number, divisor):
    return number % divisor

def main():
    try:
        number = int(input("Enter a number to be divided: "))
        divisor = int(input("Enter the divisor: "))
        
        remainder = calculate_remainder(number, divisor)
        
        print(f"The remainder when {number} is divided by {divisor} is: {remainder}")
    
    except ValueError:
        print("Invalid input.")
    except ZeroDivisionError:
        print("The divisor cannot be zero.")

if __name__ == "__main__":
    main()