//
// Created by Anatejl on 16.05.2024.
//
#include <iostream>
#include <vector>
#include <utility>


struct SequenceHolder {
    std::vector<int> values = {};
    int d;
    int min_ind = 0, max_ind = -1, left_ind = 0, right_ind = 0;
};

typedef bool (*Callback)(void *object);

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool fill_sequence(void *sequence_holder) {
    SequenceHolder &sh = *(SequenceHolder *) sequence_holder;
    int tmp;
    if (std::cin.eof()) {
        return false;
    }
    std::cin >> tmp;
    sh.values.push_back(tmp);
    return true;
}

bool get_max_len(void *sequence_holder) {
    SequenceHolder &sh = *(SequenceHolder *) sequence_holder;
    if (sh.values.empty()) {
        return true;
    }
    if (sh.right_ind >= 1 && sh.right_ind < sh.values.size()) {
        if (sh.values[sh.right_ind] < sh.values[sh.right_ind - 1]) {
            if (sh.values[sh.right_ind - 1] - sh.values[sh.left_ind] > sh.d
                && sh.max_ind - sh.min_ind < sh.right_ind - sh.left_ind - 1) {
                sh.max_ind = sh.right_ind - 1;
                sh.min_ind = sh.left_ind;
            }
            sh.left_ind = sh.right_ind;
        }
    }

    if (sh.max_ind - sh.min_ind < static_cast<int>(sh.values.size()) - 1 - sh.left_ind &&
        sh.values.back() - sh.values[sh.left_ind] > sh.d) {
        sh.max_ind = static_cast<int>(sh.values.size()) - 1;
        sh.min_ind = sh.left_ind;
    }

    ++(sh.right_ind);
    return true;
}

std::pair<int, int> getMinMaxIndx(std::vector<int> &values, int d) {
    int minIndx = 0, maxIndx = -1, leftIndx = 0;
    if (values.empty()) {
        return {minIndx, maxIndx};
    }
    for (int i = 1; i < values.size(); ++i) {
        if (values[i] < values[i - 1]) {
            if (values[i - 1] - values[leftIndx] > d && maxIndx - minIndx < i - leftIndx - 1) {
                maxIndx = i - 1;
                minIndx = leftIndx;
            }
            leftIndx = i;
        }
    }
    if (maxIndx - minIndx < static_cast<int>(values.size()) - 1 - leftIndx &&
        values.back() - values[leftIndx] > d) {
        maxIndx = static_cast<int>(values.size()) - 1;
        minIndx = leftIndx;
    }

    return {minIndx, maxIndx};
}

int main() {
    int n, d;
    std::cout << "Print len of vector and D" << std::endl;
    std::cin >> n >> d;
    SequenceHolder sequence_holder;
    sequence_holder.d = d;
    std::vector<std::pair<int, int>> results(n);
    for (int i = 0; i < n; ++i) {
        bool res = operation(&fill_sequence, &sequence_holder);
        if (!res) {
            return 0;
        }
        operation(&get_max_len, &sequence_holder);
    }

    std::cout << "Output" << std::endl;
    std::cout << sequence_holder.min_ind << ", " << sequence_holder.max_ind << std::endl;

    return 0;
}