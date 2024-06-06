//
// Created by l3t on 07.05.2024.
//

#include <iostream>
#include <vector>

// Function to generate the sequence 'a' using mathematical induction
std::vector<int> generateSequenceA(int va, int a0, int size, int n = 0) {
    if (n == size) {
        return {};
    }
    int term = va * n + a0;
    std::vector<int> rest = generateSequenceA(va, a0, size, n + 1);
    rest.insert(rest.begin(), term);
    return rest;
}

// Function to generate the sequence 'b' based on 'a' using mathematical induction
std::vector<int> generateSequenceB(int vb, int b0, const std::vector<int>& sequenceA, int n = 0) {
    if (n == sequenceA.size()) {
        return {};
    }
    int term = vb * n + b0;
    std::vector<int> rest = generateSequenceB(vb, b0, sequenceA, n + 1);
    rest.insert(rest.begin(), term);
    return rest;
}

// Function to filter sequence 'a' based on sequence 'b' using mathematical induction
std::vector<int> filterSequence(const std::vector<int>& sequenceA, const std::vector<int>& sequenceB, int n = 0) {
    if (n == sequenceA.size()) {
        return {};
    }
    if (sequenceA[n] >= sequenceB[n] && sequenceA[n] <= (sequenceB[n] + n)) {
        std::vector<int> rest = filterSequence(sequenceA, sequenceB, n + 1);
        rest.insert(rest.begin(), sequenceA[n]);
        return rest;
    }
    return filterSequence(sequenceA, sequenceB, n + 1);
}

int main() {
    // Parameters for sequence 'a'
    int va = 2;
    int a0 = 3;
    int size = 20; // Size of the sequence

    // Generate sequence 'a' using mathematical induction
    std::vector<int> sequenceA = generateSequenceA(va, a0, size);

    // Parameters for sequence 'b'
    int vb = 1;
    int b0 = 5;

    // Generate sequence 'b' using mathematical induction
    std::vector<int> sequenceB = generateSequenceB(vb, b0, sequenceA);

    // Filter sequence 'a' based on sequence 'b' using mathematical induction
    std::vector<int> filteredSequence = filterSequence(sequenceA, sequenceB);

    // Print the filtered sequence
    std::cout << "Filtered Sequence: ";
    for (int num : filteredSequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}