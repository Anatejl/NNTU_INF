#include <iostream>

void find_longest_monotonic_increase(int D) {
    int tLi = 0, tLv = 0;
    int tRi = 0, tRv = 0;
    int fLi = -1, fLv = 0;
    int fRi = -1, fRv = 0;
    int tCS = 1, fCS = 1;
    bool isFirst = true;
    bool firstElement = true;
    int index = 0;

    int xn;
    while (std::cin >> xn) {
        if (firstElement) {
            tLv = tRv = xn;
            firstElement = false;
            continue;
        }

        // Check for first iteration
        if (isFirst) {
            isFirst = false;
            tLi = index - 1;
            tLv = tRv;
            tRi = index;
            tRv = xn;
            tCS = 2;
        } else {
            // Check if sequence is still increasing
            if (xn > tRv) {
                tRi = index;
                tRv = xn;
                tCS++;
            } else {
                // Sequence broke, reset to current element
                tLi = index;
                tLv = xn;
                tRi = index;
                tRv = xn;
                tCS = 1;
            }

            // Check if current sequence is the best so far and meets the difference criteria
            if (tCS > fCS && (tRv - tLv >= D)) {
                fLi = tLi;
                fLv = tLv;
                fRi = tRi;
                fRv = tRv;
                fCS = tCS;
            }
        }

        index++;

        // Output the best found so far if valid
        if (fLi != -1 && fRi != -1) {
            std::cout << "Current best segment: from " << fLi + 1 << " to " << fRi + 1 << std::endl;
        }
    }

}

int main() {
    int D;
    std::cout << "Enter the value of D: ";
    std::cin >> D;

    std::cin.ignore(); // Ignore the newline character after the integer input

    std::cout << "Enter the elements (end input with Ctrl+D or Ctrl+Z):\n";
    find_longest_monotonic_increase(D);

    return 0;
}