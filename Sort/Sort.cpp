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
