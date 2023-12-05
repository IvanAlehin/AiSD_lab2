
#include <iostream>
#include "Node/Node.cpp"

using namespace std;

int main() {
	auto list1 = LinkedList<int>();
	list1.push_head(1, 4);
	list1.push_head(3, 3);
	list1.push_head(7, 2);
	list1.push_head(-2, 1);
	list1.push_head(3, 0);
	cout << list1 << endl;
	cout << list1.compute(1) << endl;
	list1.pop_head();
	list1.delete_node(3);
	cout << list1 << endl;

	auto list2 = LinkedList<int>();
	list2.push_tail(-2, 1);
	list2.push_tail(3, 3);
	list2.push_head(list1);
	list2.pop_tail();
	cout << list2 << endl;

	auto list3 = LinkedList<int>(list2);
	cout << list3 << endl;
	cout << list3[1] << endl;
	list3[1] = 5;
	cout << list3 << endl;
	cout << list3[1] << endl;
	list3.push_tail(list1);
	cout << list3 << endl;
	list3 = list1;
	cout << list3 << endl;
	
	auto list_random = LinkedList<int>(5, 14);
	cout << list_random << endl;
}