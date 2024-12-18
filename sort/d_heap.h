#ifndef _D_HEAP_H_
#define _D_HEAP_H_

#include <iostream>
#include <vector>
template<class T>
class DHeap {
private:
    std::vector<T> heap{};
    int d{};

    //operations for heap
    int father(int id);
    int first_child(int id);
    int last_child(int id);
    int min_child(int id);


public:
    DHeap();
    DHeap(const int& d_, const std::vector<T>& keys); // ~build_heap
    void sift_down(int id);
    void sift_up(int id);
    void insert(T elem);
    T extract_min();
    std::vector<T> sort_d(const int& d_, const std::vector<T>& a);
    void print_heap();
};

template<class T> DHeap<T>::DHeap()
{
    d = 2;
}

template<class T>
inline DHeap<T>::DHeap(const int& d_, const std::vector<T>& keys) : d(d_), heap(keys)
{
    for (int i = heap.size() - 1; i >= 0; i--) {
        sift_down(i);
    }
}

template<class T> int DHeap<T>::father(int id)
{
    return (id - 2) / d - 1;
}

template<class T> int DHeap<T>::first_child(int id)
{
    int k = (id - 1) * d + 2;
    if (k > heap.size()) return 0;
    return k;
}

template<class T> int DHeap<T>::last_child(int id)
{
    int n = heap.size();
    int k = first_child(id);
    if (k == 0)
        return 0;
    return std::min(k + d - 1, n);
}

template<class T> int DHeap<T>::min_child(int id)
{
    int n = heap.size();
    int last_id = std::min(n, d * id + d);
    int min_id = d * id + 1;
    for (int i = d * id + 2; i <= last_id && i < n; i++)
    {
        if (heap[i] < heap[min_id])
        {
            min_id = i;
        }
    }
    return min_id;
}

template<class T> void DHeap<T>::sift_down(int id)
{
    int n = heap.size();
    while (d * id + 1 < n)
    {
        int min_id = min_child(id);
        if (heap[id] <= heap[min_id]) break;
        std::swap(heap[id], heap[min_id]);
        id = min_id;
    }
}

template<class T> T DHeap<T>::extract_min()
{
    T min = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.resize(heap.size() - 1);
    sift_down(0);
    return min;
}
template<class T> std::vector<T> DHeap<T>::sort_d(const int& d_, const std::vector<T>& a)
{
    //  DHeap(d_, a);
    int n = heap.size();
    std::vector<T> sort_a;

    while (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            sort_a.push_back(extract_min());
            n = heap.size();
        }
    }
    heap = sort_a;
    return sort_a;
}

template<class T> void DHeap<T>::sift_up(int id)
{
    while (id > 1 && heap[id] < heap[id / d]) {
        std::swap(heap[id], heap[id / d]);
        id /= d;
    }
}

template<class T> void DHeap<T>::insert(T elem)
{
    heap.resize(heap.size() + 1);
    heap[heap.size() - 1] = elem;
    sift_up(heap.size() - 1);
}

template<class T> void DHeap<T>::print_heap()
{
    int level = 0;
    int elements_in_level = 1;
    int idx = 0;
    std::cout << "Heap" << std::endl;
    while (idx < heap.size()) {
        for (int i = 0; i < elements_in_level && idx < heap.size(); i++) {
            std::cout << heap[idx++] << " ";
        }
        level++;
        elements_in_level *= d;
    }
    std::cout << std::endl;
}

#endif
