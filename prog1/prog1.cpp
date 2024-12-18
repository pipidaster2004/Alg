#include <iostream>
#include <fstream>
#include <chrono>
#include "k_merge.h"
#include "d_heap.h"




int main() {
    // Чтение данных из файла
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cout << "ERROR IN input.txt OR output.txt\n";
        return 1;
    }

    int n;
    inputFile >> n;
    int d = 3;
    std::vector<int> arrMerge(n);
    std::vector<int> arrDheap(n);

    for (int i = 0; i < n; i++) {
        inputFile >> arrMerge[i];
        arrDheap[i] = arrMerge[i];
    }
    inputFile.close();
    DHeap<int> dh(d, arrDheap);

    // Сортировка с помощью быстрой сортировки
    auto startQuick = std::chrono::high_resolution_clock::now();
    SORT_MERGE(arrMerge, 0, n - 1, 4); // Вызов вашей функции быстрой сортировки
    auto endQuick = std::chrono::high_resolution_clock::now();
    auto durationQuick = std::chrono::duration_cast<std::chrono::microseconds>(endQuick - startQuick).count();

    // Сортировка с помощью бинарного дерева
    auto startTree = std::chrono::high_resolution_clock::now();
    arrDheap = dh.sort_d(3, arrDheap); // Вызов вашей функции сортировки бинарным деревом
    auto endTree = std::chrono::high_resolution_clock::now();
    auto durationTree = std::chrono::duration_cast<std::chrono::microseconds>(endTree - startTree).count();

    // Запись результатов в файл
    outputFile << "Отсортированный массив (сортировка 4 слиянием): ";
    for (int i = 0; i < n; i++) {
        outputFile << arrMerge[i] << " ";
    }
    outputFile << "\nВремя работы (сортировка 4 слиянием): " << durationQuick << " микросекунд\n";

    outputFile << "Отсортированный массив (сортировка 3 кучей): ";
    for (int i = 0; i < n; i++) {
        outputFile << arrDheap[i] << " ";
    }
    outputFile << "\nВремя работы (сортировка 3 кучей): " << durationTree << " микросекунд\n";

    outputFile.close();
    return 0;
}