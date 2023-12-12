#pragma once

#include <vector>
#include <iostream>
#include <stdexcept> 
#include <random>

using namespace std;


struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

template <typename T>
void Swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

class MyClass {
private:
    int value;
public:
    MyClass() :value(0) {};
    MyClass(const int value) :value(value) {};
    int get_value() const {
        return this->value;
    }
    bool operator>(const MyClass& rhs) const {
        return this->value > rhs.value;
    }

    bool operator<(const MyClass& rhs) const {
        return this->value < rhs.value;
    }
};

ostream& operator<<(std::ostream& os, stats& stat){
    os << "comparison_count = " << stat.comparison_count << " copy_count = " << stat.copy_count;
    return os;
}

template<typename T>
stats& BubbleSort(vector<T>& vec) {
    stats sort_stats;
    for (int i(0); i < (vec.size() - 1); ++i) {
        for (int j(0); j < (vec.size() - i - 1); ++j) {
            sort_stats.comparison_count += 1;
            if (vec[j] > vec[j + 1]) {
                Swap(vec[j], vec[j + 1]);
                sort_stats.copy_count += 3;
            }
        }
    }
    return sort_stats;
}

template<typename T>
stats& ShellSort(vector<T>& vec) {
	stats sort_stats;
	for (int i(int(vec.size())/2); i > 0; i /= 2) {
		for (int j(i); j < (vec.size()); ++j) {
			for (int k(j); (k >= 0) && (vec[k-j] > vec[k]); k -= i) {
				sort_stats.comparison_count += 1;
				Swap(vec[k-j], vec[k]);
				sort_stats.copy_count += 3;
			}
		}
	}
	return sort_stats;
}


template <typename T>
void Heapify(vector<T>& vec, int size, int i, stats& sort_stats) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && vec[left] > vec[max]) {
        sort_stats.comparison_count++;
        max = left;
    }

    if (right < size && vec[right] > vec[max]) {
        sort_stats.comparison_count++;
        max = right;
    }

    if (max != i) {
        Swap(vec[i], vec[max]);
        sort_stats.copy_count += 3;
        Heapify(vec, size, max, sort_stats);
    }
}

template <typename T>
stats& HeapSort(vector<T>& vec) {
    stats sort_stats;
    int size = vec.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(vec, size, i, sort_stats);
    }

    for (int i = size - 1; i >= 0; i--) {
        Swap(vec[0], vec[i]);
        sort_stats.copy_count += 3;
        Heapify(vec, i, 0, sort_stats);
    }
    return sort_stats;
}


template <typename T>
vector<T> RandomVec(size_t size) {
    vector<T> vec(size);
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < size; ++i) {
        vec[i] = rand();
    }
    return vec;
}

template <typename T>
vector<T> SortedVec(size_t size) {
    vector<T> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = i;
    }
    return vec;
}

template <typename T>
vector<T> ReverseSortedVec(size_t size) {
    vector<T> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = size - i;
    }
    return vec;
}

template <typename T>
void PrintVec(vector<T> vec) {
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}
