#pragma once

#include <iostream>
#include <stdexcept> 
#include <random>

using namespace std;



template<typename T>
class Node {
public:
	T value;
	Node<T>* next;
	Node<T>* prev;
	Node<T>(const T& value) :value(value), next(nullptr), prev(nullptr) {};
};


template<typename T>
class LinkedList {
private:
	Node<T>* head;

public:
	LinkedList() {
		head = nullptr;
	}
	LinkedList(const LinkedList<T>& other) {
		head = nullptr;
		Node<T>* tmp_other = other.head;
		while (tmp_other) {
			this->push_tail(tmp_other->value);
			tmp_other = tmp_other->next;
		}
	}

	LinkedList(const int size, const int rand_max) {
		head = nullptr;
		int count = 0;
		while (count != size) {
			this->push_tail((int)(rand()) * rand_max / RAND_MAX + 1);
			count ++;
		}
	}
	LinkedList(const int size, const float rand_max) {
		head = nullptr;
		int count = 0;
		while (count != size) {
			this->push_tail((float)(rand()) * (rand_max - 0.0001f) / RAND_MAX + 0.0001f);
			count ++;
		}
	}

	~LinkedList() {
		while (head) {
			Node<T>* tmp = head;
			head = head->next;
			delete tmp;
			tmp = nullptr;
		}
	}

	void operator=(const LinkedList<T>& other) {
		while (head) {
			pop_head();
		}
		Node<T>* tmp_other = other.head;
		while (tmp_other) {
			this->push_tail(tmp_other->value);
			tmp_other = tmp_other->next;
		}
	}

	Node<T>* get_head() const {
		return head;
	}

	void push_tail(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node<T>* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			newNode->prev = current;
			current->next = newNode;

		}
	}
	void push_tail(const LinkedList<T>& other) {
		if (other.head != nullptr) {
			Node<T>* tmp_other = other.head;
			while (tmp_other) {
				this->push_tail(tmp_other->value);
				tmp_other = tmp_other->next;
			}
		}
	}

	void push_head(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node<T>* current = head;
			head = newNode;
			head->next = current;
			current->prev = head;
		}
	}
	void push_head(const LinkedList<T>& other) {
		LinkedList<T> new_list;
		if (other.head != nullptr) {
			Node<T>* tmp_other = other.head;
			while (tmp_other) {
				new_list.push_tail(tmp_other->value);
				tmp_other = tmp_other->next;
			}
		}
		if (this->head != nullptr) {
			Node<T>* tmp_this = this->head;
			while (tmp_this) {
				new_list.push_tail(tmp_this->value);
				tmp_this = tmp_this->next;
			}
		}
		while (head) {
			Node<T>* tmp = head;
			head = head->next;
			delete tmp;
			tmp = nullptr;
		}
		this->head = new_list.head;
		new_list.head = nullptr;
	}

	void pop_head() {
		if (head == nullptr) {
			throw length_error("Empty list");
		}
		else {
			if (head->next == nullptr) {
				delete head;
				head = nullptr;
			}
			else {
				Node<T>* tmp = head;
				head = head->next;
				head->prev = nullptr;
				delete tmp;
				tmp = nullptr;
			}
		}
	}
	void pop_tail() {
		if (head == nullptr) {
			throw length_error("Empty list");
		}
		else {
			Node<T>* last = head;
			while (last->next != nullptr) {
				last = last->next;
			}
			Node<T>* prev_last = last->prev;
			if (prev_last != nullptr) {
				prev_last->next = nullptr;
			}
			else {
				head = nullptr;
			}
			delete last;
			last = nullptr;


		}
	}
	
	void delete_node(const T& x) {
		if (head != nullptr) {
			Node<T>* current = head;
			Node<T>* tmp = nullptr;
			while (current != nullptr) {
				tmp = current->next;
				if (current->value == x) {
					if (current->prev == nullptr) {
						this->pop_head();
					}
					else {
						if (current->next == nullptr) {
							this->pop_tail();
						}
						else {
							current->next->prev = current->prev;
							current->prev->next = current->next;
							delete current;
						}
					}
				}
				current = tmp;
			}
		}
		else {
			throw length_error("Empty list");
		}
	}

	T& operator[](const int index) {
		Node<T>* tmp = head;
		int count = 0;
		while (tmp != nullptr) {
			if (count == index) {
				return tmp->value;
			}
			else {
				tmp = tmp->next;
				count ++;
			}
		}
		throw out_of_range("Index out of range");
	}

	T operator[](const int index) const {
		Node<T>* tmp = head;
		int count = 0;
		while (tmp != nullptr) {
			if (count == index) {
				return tmp->value;
			}
			else {
				tmp = tmp->next;
				count ++;
			}
		}
		throw out_of_range("Index out of range");
	}
};