#include <iostream>
#include <fstream>
#include <chrono>
#include "k_merge.h"
#include "d_heap.h"




int main() {
    // ������ ������ �� �����
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

    // ���������� � ������� ������� ����������
    auto startQuick = std::chrono::high_resolution_clock::now();
    SORT_MERGE(arrMerge, 0, n - 1, 4); // ����� ����� ������� ������� ����������
    auto endQuick = std::chrono::high_resolution_clock::now();
    auto durationQuick = std::chrono::duration_cast<std::chrono::microseconds>(endQuick - startQuick).count();

    // ���������� � ������� ��������� ������
    auto startTree = std::chrono::high_resolution_clock::now();
    arrDheap = dh.sort_d(3, arrDheap); // ����� ����� ������� ���������� �������� �������
    auto endTree = std::chrono::high_resolution_clock::now();
    auto durationTree = std::chrono::duration_cast<std::chrono::microseconds>(endTree - startTree).count();

    // ������ ����������� � ����
    outputFile << "��������������� ������ (���������� 4 ��������): ";
    for (int i = 0; i < n; i++) {
        outputFile << arrMerge[i] << " ";
    }
    outputFile << "\n����� ������ (���������� 4 ��������): " << durationQuick << " �����������\n";

    outputFile << "��������������� ������ (���������� 3 �����): ";
    for (int i = 0; i < n; i++) {
        outputFile << arrDheap[i] << " ";
    }
    outputFile << "\n����� ������ (���������� 3 �����): " << durationTree << " �����������\n";

    outputFile.close();
    return 0;
}