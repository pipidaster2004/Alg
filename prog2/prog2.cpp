#include <iostream>
#include <ctime>
#include <vector>
#include <chrono>
#include <fstream>
#include "d_heap.h"
#include "k_merge.h"

std::vector<int> generate_array(int n, int lower, int upper, int order) {
    std::vector<int> arr(n);
    if (order == 1) {
        for (int i = 0; i < n; i++) {
            arr[i] = lower + (rand() % (upper - lower + 1));
        }
    }
    else if (order == 2) {
        for (int i = 0; i < n; i++) {
            if (n == 1) arr[i] = lower + (upper - lower) * i / (n);
            else arr[i] = lower + (upper - lower) * i / (n - 1);
        }
    }
    else if (order == 3) {
        for (int i = 0; i < n; i++) {
            if (n == 1) arr[i] = upper - (upper - lower) * i / (n);
            else arr[i] = upper - (upper - lower) * i / (n - 1);
        }
    }
    return arr;
}

void measureSortTime(int n, int lower, int upper, const std::string& order, std::ofstream& outA, std::ofstream& outB,int giper) {
    std::vector<int> arr(n);

    // Заполнение массива в зависимости от порядка
    if (order == "random") {
        arr = generate_array(n, lower, upper, 1);
    }
    else if (order == "ascending") {
        arr = generate_array(n, lower, upper, 2);
    }
    else if (order == "descending") {
        arr = generate_array(n, lower, upper, 3);
    }
    std::vector<int> arr2 = arr;
    // Измерение времени для sortA
    auto startA = std::chrono::high_resolution_clock::now();
    SORT_MERGE(arr, 0, n - 1, 4);
    auto endA = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationA = endA - startA;
    outA << giper << "," << durationA.count() << std::endl;

    // Измерение времени для sortB
    auto startB = std::chrono::high_resolution_clock::now();
    DHeap<int> dh(3, arr2);
    dh.sort_d(3, arr2);
    auto endB = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationB = endB - startB;    
    outB << giper << "," << durationB.count() << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    int n, lower, upper;
    std::cout << "Enter the count elements in array (n): ";
    std::cin >> n;
    std::cout << "\nEnter the lower bound (l): ";
    std::cin >> lower;
    std::cout << "\nEnter the upper bound (u): ";
    std::cin >> upper;

    std::cout << "Enter the type of filling the array:\n";
    std::cout << "1. Pseudo-random\n";;
    std::cout << "2. Automatic non-decreasing\n";
    std::cout << "3. Automatic non-increasing\n";

    int choice;
    std::cout << "Your choice(1/2/3): ";
    std::cin >> choice;

    int d = 3;
    std::vector<int> arrMerge = generate_array(n, lower, upper, choice);
    std::vector<int> arrDheap = arrMerge;
    DHeap<int> dh(d, arrDheap);

    // Измеряем время работы сортировки 4 слиянием
    auto start = std::chrono::high_resolution_clock::now();
    SORT_MERGE(arrMerge, 0, n - 1, 4);
    auto end = std::chrono::high_resolution_clock::now();
    auto mergeDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    for (int i = 0; i < n; i++) {
        std::cout << arrMerge[i] << " ";
    }
    std::cout << std::endl;

    // Измеряем время работы сортировки бинарным деревом
    start = std::chrono::high_resolution_clock::now();
    dh.sort_d(3, arrDheap);
    end = std::chrono::high_resolution_clock::now();
    auto dheapDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    dh.print_heap();

    // Вывод результатов
    std::cout << "merge sort running time: " << mergeDuration << " ms" << std::endl;
    std::cout << "d-heap sort running time: " << dheapDuration << " ms" << std::endl;
     
  
    //std::ofstream outA1r("resultsA1rand.csv");
    //std::ofstream outB1r("resultsB1rand.csv");
    //std::ofstream outA1a("resultsA1ascending.csv");
    //std::ofstream outB1a("resultsB1ascending.csv");
    //std::ofstream outA1d("resultsA1descending.csv");
    //std::ofstream outB1d("resultsB1descending.csv");
    //std::ofstream outA2r("resultsA2rand.csv");
    //std::ofstream outB2r("resultsB2rand.csv");
    //std::ofstream outA2a("resultsA2ascending.csv");
    //std::ofstream outB2a("resultsB2ascending.csv");
    //std::ofstream outA2d("resultsA2descending.csv");
    //std::ofstream outB2d("resultsB2descending.csv");
    //outA1r << "n,TimeA" << std::endl;
    //outB1r << "n,TimeB" << std::endl;
    //outA1a << "n,TimeA" << std::endl;
    //outB1a << "n,TimeB" << std::endl;
    //outA1d << "n,TimeA" << std::endl;
    //outB1d << "n,TimeB" << std::endl;

    //outA2r << "w,TimeA" << std::endl;
    //outB2r << "w,TimeB" << std::endl;
    //outA2a << "w,TimeA" << std::endl;
    //outB2a << "w,TimeB" << std::endl;
    //outA2d << "w,TimeA" << std::endl;
    //outB2d << "w,TimeB" << std::endl;
    //for (int n = 1; n <= 1000000; n += 10000) {
    //    measureSortTime(n, 1, 1000000000, "random", outA1r, outB1r, n);
    //    measureSortTime(n, 1, 1000000000, "ascending", outA1a, outB1a, n);
    //    measureSortTime(n, 1, 1000000000, "descending", outA1d, outB1d, n);
    //}

    //for (int w = 1; w <= 100; ++w) {
    //    measureSortTime(1000000, 1, w, "random", outA2r, outB2r, w);
    //    measureSortTime(1000000, 1, w, "ascending", outA2a, outB2a, w);
    //    measureSortTime(1000000, 1, w, "descending", outA2d, outB2d, w);
    //}
    //outA1r.close();
    //outB1r.close();
    //outA1a.close();
    //outB1a.close();
    //outA1d.close();
    //outB1d.close();

    //outA2r.close();
    //outB2r.close();
    //outA2a.close();
    //outB2a.close();
    //outA2d.close();
    //outB2d.close();

    return 0;
}