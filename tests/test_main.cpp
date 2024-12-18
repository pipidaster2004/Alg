#include "gtest.h"
#include "k_merge.h"
#include "d_heap.h"


TEST(mergesort, test_ints) {
    const int size = 10;
    std::vector<int> sortArr = { 5, 32, 15, 3, 76, 23, 54, 100, 1000, 7 };
    std::vector<int> rightArr = { 3, 5, 7, 15, 23, 32, 54, 76, 100, 1000 };
    SORT_MERGE(sortArr, 0, size-1, 4);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(sortArr[i], rightArr[i]);
    }
}

TEST(mergesort, test_floats) {
    const int size = 10;
    std::vector<float> arr = { 3.14f, 1.41f, 2.71f, 0.577f, 1.618f, 4.669f, 2.236f, 3.162f, 1.732f, 0.301f };
    std::vector<float> rightArr = { 0.301f, 0.577f, 1.41f, 1.618f, 1.732f, 2.236f, 2.71f, 3.14f, 3.162f, 4.669f };
    SORT_MERGE(arr, 0, size - 1, 4);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(mergesort, test_sorted_100) {
    const int size = 100;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
        rightArr[i] = i;
    }
    SORT_MERGE(arr, 0, size - 1, 4);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(mergesort, test_unsorted_100) {
    const int size = 100;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
        rightArr[i] = i;
    }
    SORT_MERGE(arr, 0, size - 1, 4);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(mergesort, test_sorted_1000) {
    const int size = 1000;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
        rightArr[i] = i;
    }
    SORT_MERGE(arr, 0, size - 1, 4);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(mergesort, test_unsorted_1000) {
    const int size = 1000;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
        rightArr[i] = i;
    }
    SORT_MERGE(arr, 0, size - 1, 4);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(mergesort, test_sorted_100000) {
    const int size = 100000;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
        rightArr[i] = i;
    }
    SORT_MERGE(arr, 0, size - 1, 4);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(mergesort, test_unsorted_100000) {
    const int size = 100000;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
        rightArr[i] = i;
    }
    SORT_MERGE(arr, 0, size - 1, 4);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(dheapsort, test_ints) {
    const int size = 10;
    std::vector<int> sortArr = { 5, 32, 15, 3, 76, 23, 54, 100, 1000, 7 };
    std::vector<int> rightArr = { 3, 5, 7, 15, 23, 32, 54, 76, 100, 1000 };
    DHeap<int> dh(3, sortArr);
    sortArr = dh.sort_d(3, sortArr);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(sortArr[i], rightArr[i]);
    }
}

TEST(dheapsort, test_floats) {
    const int size = 10;
    std::vector<float> arr = { 3.14f, 1.41f, 2.71f, 0.577f, 1.618f, 4.669f, 2.236f, 3.162f, 1.732f, 0.301f };
    std::vector<float> rightArr = { 0.301f, 0.577f, 1.41f, 1.618f, 1.732f, 2.236f, 2.71f, 3.14f, 3.162f, 4.669f };
    DHeap<float> dh(3, arr);
    arr = dh.sort_d(3, arr);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(dheapsort, test_sorted_100) {
    const int size = 100;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
        rightArr[i] = i;
    }
    DHeap<int> dh(3, arr);
    arr = dh.sort_d(3, arr);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(dheapsort, test_unsorted_100) {
    const int size = 100;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
        rightArr[i] = i;
    }
    DHeap<int> dh(3, arr);
    arr = dh.sort_d(3, arr);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(dheapsort, test_sorted_1000) {
    const int size = 1000;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
        rightArr[i] = i;
    }
    DHeap<int> dh(3, arr);
    arr = dh.sort_d(3, arr);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(dheapsort, test_unsorted_1000) {
    const int size = 1000;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
        rightArr[i] = i;
    }
    DHeap<int> dh(3, arr);
    arr = dh.sort_d(3, arr);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(dheapsort, test_sorted_100000) {
    const int size = 100000;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
        rightArr[i] = i;
    }
    DHeap<int> dh(3, arr);
    arr = dh.sort_d(3, arr);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

TEST(dheapsort, test_unsorted_100000) {
    const int size = 100000;
    std::vector<int> arr(size);
    std::vector<int> rightArr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
        rightArr[i] = i;
    }
    DHeap<int> dh(3, arr);
    arr = dh.sort_d(3, arr);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], rightArr[i]);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}