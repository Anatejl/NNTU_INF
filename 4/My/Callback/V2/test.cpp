//
// Created by Anatejl on 30.04.2024.
//
#ifndef CALLBACK_V1_APPLICATION_TESTS_CPP
#define CALLBACK_V1_APPLICATION_TESTS_CPP

//#include "E:\Git\NNTU_INF\googletest\googlemock\include\gmock\gmock.h"
//#include "E:\Git\NNTU_INF\googletest\googletest\include\gtest\gtest.h"
#include "C:\Users\l3t\Documents\GitHub\NNTU_INF\googletest\googlemock\include\gmock\gmock.h"
#include "C:\Users\l3t\Documents\GitHub\NNTU_INF\googletest\googletest\include\gtest\gtest.h"

#include "application.h"

using namespace std;

Application init_application(std::vector<int> &&init_values, int D) {
    Application test_application;
    test_application.constD = D;
    //test_application.temp_data.processIterator = init_values.size()-1;
    test_application.temp_data.cin_read.value.reserve(init_values.size());
    for (auto &val: init_values) {
        test_application.temp_data.cin_read.value.push_back(val);
    }

    return test_application;
}

TEST(IndexFindCorrectly, Simple_1) {
Application test_app = init_application(std::vector<int>{1, 2, 3, 4, 5}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(4, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_2) {
Application test_app = init_application(std::vector<int>{1}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(0, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_3) {
Application test_app = init_application(std::vector<int>{1, 123}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(1, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_4) {
Application test_app = init_application(std::vector<int>{11, 12, 11}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(1, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_5) {
Application test_app = init_application(std::vector<int>{1, 4, 1, 3, 6}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(2, test_app.finalLeft);
ASSERT_EQ(4, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_6) {
Application test_app = init_application(std::vector<int>{4, 3, 2, 1}, 0);
ASSERT_FALSE(appProcessData(&test_app));

//ASSERT_TRUE(appProcessData(test_app));
//ASSERT_TRUE(test_app.finalLeft == 0 || test_app.finalLeft == 4 || test_app.finalLeft == INT_MAX);
//ASSERT_TRUE(test_app.finalRight == 0 || test_app.finalRight == 4 || test_app.finalRight == INT_MAX);
}

TEST(IndexFindCorrectly, Simple_7) {
Application test_app = init_application(std::vector<int>{4, 3, 2, 1, 3, 2}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(3, test_app.finalLeft);
ASSERT_EQ(4, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_8) {
Application test_app = init_application(std::vector<int>{1, 2, 3, 1, 1, 1, 1, 2, 1}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(3, test_app.finalLeft);
ASSERT_EQ(7, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_9) {
Application test_app = init_application(std::vector<int>{1, 2, 3, 3, 2, 1, 1}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(3, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_10) {
Application test_app = init_application(std::vector<int>{6, 4, 2, 1, 5, 8, 2, 3, 7, 9, 2, 3, 4, 2}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(6, test_app.finalLeft);
ASSERT_EQ(9, test_app.finalRight);
}

TEST(IndexFindCorrectly, Simple_11) {
Application test_app = init_application(std::vector<int>{1, 2, 3, 2}, 0);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(0, test_app.finalLeft);
ASSERT_EQ(2, test_app.finalRight);
}

TEST(CannotFindIndex, D_Bigger_1) {
Application test_app = init_application(std::vector<int>{1, 2, 3, 4, 5}, 10);
ASSERT_FALSE(appProcessData(&test_app));

}

TEST(CannotFindIndex, D_Bigger_2) {
Application test_app = init_application(std::vector<int>{16, 1, 3, 4, 5, 1, 9}, 10);
ASSERT_FALSE(appProcessData(&test_app));
}


TEST(CannotFindIndex, D_Bigger_3) {
Application test_app = init_application(std::vector<int>{5, 4, 3, 2}, 1);
ASSERT_FALSE(appProcessData(&test_app));
}

TEST(IndexWithD, Filttered_by_D_1) {
Application test_app = init_application(std::vector<int>{1, 2, 3, 4, 5, 1, 12, 13}, 10);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(5, test_app.finalLeft);
ASSERT_EQ(7, test_app.finalRight);
}

TEST(IndexWithD, Filttered_by_D_2) {
Application test_app = init_application(std::vector<int>{1, 2, 2, 2, 2, 2, 1, 5, 2, 3, 3, 3, 4, 4, 5, 2, 2}, 1);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(8, test_app.finalLeft);
ASSERT_EQ(14, test_app.finalRight);
}

TEST(IndexWithD, Filttered_by_D_3) {
Application test_app = init_application(std::vector<int>{5, 1, 9, 1, 2, 3, 10}, 7);
ASSERT_TRUE(appProcessData(&test_app));

ASSERT_EQ(3, test_app.finalLeft);
ASSERT_EQ(6, test_app.finalRight);
}

TEST(NegativeUInt, NegativeUInt) {
    unsigned int huy = -1;
    ASSERT_EQ(-1, huy);
}

TEST(NegativeUInt, Negative_unit_becomes_false) {
    int huy = -1;
    int huy2 = 1;
    //ASSERT_FALSE(huy);
    ASSERT_TRUE(huy2);
}

TEST(Custom, One) {
    Application test_app = init_application(std::vector<int>{1, 2, 3, 4, 1, 3, 1, INT_MAX - 5, INT_MAX  - 4, INT_MAX  - 3, INT_MAX  - 2, INT_MAX - 1}, 0);
    ASSERT_TRUE(appProcessData(&test_app));

    ASSERT_EQ(6, test_app.finalLeft);
    ASSERT_EQ(11, test_app.finalRight);
}

TEST(Custom, Two) {
    Application test_app = init_application(std::vector<int>{-4, -3, -2, -1, -3, -2, -6, INT_MIN + 5, INT_MIN + 6, INT_MIN + 7, INT_MIN + 8, INT_MIN + 9, INT_MIN + 12, INT_MIN + 25}, 0);
    ASSERT_TRUE(appProcessData(&test_app));

    ASSERT_EQ(7, test_app.finalLeft);
    ASSERT_EQ(13, test_app.finalRight);
}

TEST(Custom, Three) {
    Application test_app = init_application(std::vector<int>{INT_MIN + 3, INT_MIN + 3, INT_MIN + 3, INT_MIN + 3, INT_MIN + 3, INT_MIN + 3, INT_MIN + 3, INT_MIN + 3}, -1);
    ASSERT_TRUE(appProcessData(&test_app));

    ASSERT_EQ(0, test_app.finalLeft);
    ASSERT_EQ(7, test_app.finalRight);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}


#endif //CALLBACK_APPLICATION_TESTS_CPP
