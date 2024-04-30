//
// Created by Anatejl on 30.04.2024.
//
#ifndef INDUCTANCE_V2_APPLICATION_TESTS_CPP
#define INDUCTANCE_V2_APPLICATION_TESTS_CPP

#include "E:\Git\NNTU_INF\googletest\googlemock\include\gmock\gmock.h"
#include "E:\Git\NNTU_INF\googletest\googletest\include\gtest\gtest.h"
#include "application.h"

using namespace std;

Application init_application(std::vector<unsigned> &&init_values, unsigned D) {
    Application test_application;
    test_application.constD = D;
    test_application.valueArray.counter = init_values.size();
    test_application.valueArray.value.reserve(init_values.size());
    test_application.indexArray.counter = init_values.size();
    test_application.indexArray.value.resize(init_values.size());
    for (int i = 0; i < init_values.size(); ++i) {
        test_application.indexArray.value[i] = i;
    }
    for (auto &val: init_values) {
        test_application.valueArray.value.push_back(val);
    }

    return test_application;
}

TEST(IndexFindCorrectly, Simple_1) {
Application test_app = init_application(std::vector<unsigned>{1, 2, 3, 4, 5}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(4, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_2) {
Application test_app = init_application(std::vector<unsigned>{1}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(0, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_3) {
Application test_app = init_application(std::vector<unsigned>{1, 123}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(1, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_4) {
Application test_app = init_application(std::vector<unsigned>{11, 12, 11}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(1, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_5) {
Application test_app = init_application(std::vector<unsigned>{1, 4, 1, 3, 6}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(2, test_app.finalLeft);
ASSERT_EQ(4, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_6) {
Application test_app = init_application(std::vector<unsigned>{4, 3, 2, 1}, 0);
ASSERT_FALSE(appProcessDataIntoFinalResult(test_app));

//ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));
//ASSERT_TRUE(test_app.finalLeft == 0 || test_app.finalLeft == 4 || test_app.finalLeft == INT_MAX);
//ASSERT_TRUE(test_app.finalRight == 0 || test_app.finalRight == 4 || test_app.finalRight == INT_MAX);
}

TEST(IndexFindCorrectly, Simple_7) {
Application test_app = init_application(std::vector<unsigned>{4, 3, 2, 1, 3, 2}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(4, test_app.finalLeft);
ASSERT_EQ(5, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_8) {
Application test_app = init_application(std::vector<unsigned>{1, 2, 3, 1, 1, 1, 1, 2, 1}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(3, test_app.finalLeft);
ASSERT_EQ(7, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_9) {
Application test_app = init_application(std::vector<unsigned>{1, 2, 3, 3, 2, 1, 1}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(4, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_10) {
Application test_app = init_application(std::vector<unsigned>{6, 4, 2, 1, 5, 8, 2, 3, 7, 9, 2, 3, 4, 2}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(6, test_app.finalLeft);
ASSERT_EQ(10, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_11) {
Application test_app = init_application(std::vector<unsigned>{1, 2, 3, 2}, 0);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(2, test_app.finalRight);
}

TEST(CannotFindIndex, D_Bigger_1) {
Application test_app = init_application(std::vector<unsigned>{1, 2, 3, 4, 5}, 10);
ASSERT_FALSE(appProcessDataIntoFinalResult(test_app));

}

TEST(CannotFindIndex, D_Bigger_2) {
Application test_app = init_application(std::vector<unsigned>{16, 1, 3, 4, 5, 1, 9}, 10);
ASSERT_FALSE(appProcessDataIntoFinalResult(test_app));
}


TEST(CannotFindIndex, D_Bigger_3) {
Application test_app = init_application(std::vector<unsigned>{5, 4, 3, 2}, 1);
ASSERT_FALSE(appProcessDataIntoFinalResult(test_app));
}

TEST(IndexWithD, Filttered_by_D_1) {
Application test_app = init_application(std::vector<unsigned>{1, 2, 3, 4, 5, 1, 12, 13}, 10);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(5, test_app.finalLeft);
ASSERT_EQ(8, test_app.finalRight);
}

TEST(IndexWithD, Filttered_by_D_2) {
Application test_app = init_application(std::vector<unsigned>{1, 2, 2, 2, 2, 2, 1, 5, 2, 3, 3, 3, 4, 4, 5, 2, 2}, 1);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(8, test_app.finalLeft);
ASSERT_EQ(14, test_app.finalRight);
}

TEST(IndexWithD, Filttered_by_D_3) {
Application test_app = init_application(std::vector<unsigned>{5, 1, 9, 1, 2, 3, 10}, 7);
ASSERT_TRUE(appProcessDataIntoFinalResult(test_app));

ASSERT_EQ(3, test_app.finalLeft);
ASSERT_EQ(6, test_app.finalRight);
}

TEST(NegativeUInt, NegativeUInt) {
    unsigned int huy = -1;
    ASSERT_EQ(-1, huy);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}


#endif //INDUCTANCE_V2_APPLICATION_TESTS_CPP
