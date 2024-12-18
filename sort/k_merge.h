#ifndef _K_MERGE_H_
#define _K_MERGE_H_

#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& a, int i, int j) {
    for (int k = i; k <= j; ++k) {
        for (int l = i; l < j - (k - i); ++l) {
            if (a[l] > a[l + 1]) {
                std::swap(a[l], a[l + 1]);
            }
        }
    }
}

template <typename T>
void MERGE(std::vector<T>& a, int i, int m, int j) {
    int n1 = m - i + 1; // Размер первой половины
    int n2 = j - m;     // Размер второй половины

    std::vector<T> b(j - i + 1); // Временный массив для слияния
    int i1 = i, i2 = m + 1; // Индексы для двух половин

    while (i1 + i2 < j + m + 2) {
        if ((i1 <= m && i2 < j + 1 && a[i1] <= a[i2]) || i2 == j + 1) {
            b[i1 + i2 - i - m - 1] = a[i1];
            i1++;
        }
        else {
            b[i1 + i2 - i - m - 1] = a[i2];
            i2++;
        }
    }

    // Копируем отсортированные элементы обратно в оригинальный массив
    for (int k = 0; k < b.size(); ++k) {
        a[i + k] = b[k];
    }
}
template <typename T>
void SORT_MERGE(std::vector<T>& a, int i, int j, int k) {
    if (j - i + 1 < k) {
        bubbleSort(a, i, j);
    }
    else {
        int step = (j - i + 1) / k;
        for (int numb = 0; numb < k; ++numb) {
            if (numb < k - 1) {
                SORT_MERGE(a, i + step * numb, i + step * (numb + 1) - 1, k);
            }
            else {
                SORT_MERGE(a, i + (k - 1) * step, j, k);
            }
        }
        for (int numb = 0; numb < k - 1; ++numb) {
            if (numb < k - 2) {
                MERGE(a, i, i + step * (numb + 1) - 1, i + step * (numb + 2) - 1);
            }
            else {
                MERGE(a, i, i + (k - 1) * step - 1, j);
            }
        }
    }
}

#endif