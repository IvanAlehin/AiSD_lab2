#pragma once

#include <iostream>
#include <stdexcept> 

using namespace std;



template<typename T>
class Node {
public:
	T value;
	Node<T>* next;
	Node<T>* prev;
	Node<T>(const T& value) :value(value), next(nullptr), prev(nullptr) {};
};

