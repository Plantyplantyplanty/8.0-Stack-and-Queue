/*
 * Author: Marisa Persaud
 * Project: Stack and Queue
 * Purpose: Create a stack and queue with iterators based on a doubly linked list 
 * Notes: I hope that the fact that the output does not completely match the formatting on 
          canvas is not a big deal. I would ask you but you wouldn't like that.
 *
 */

#include "list_functions.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
	cout << "_____________________________________\n";
	cout << "_____________LIST___________________\n";
	cout << "_____________________________________\n";
	test_insert_head();
	test_node();
	cout << endl;
	test_delete_head();
	cout << endl;
	test_insert_after();
	cout << "\n_____________________________________\n";
	cout << "_____________STACK___________________\n";
	cout << "_____________________________________\n";
	test_stack_push();
	cout << "\n_____________________________________\n";
	cout << "_____________QUEUE___________________\n";
	cout << "_____________________________________\n";
	test_queue();

	//test_stack_pop_empty();
	//test_stack_top_empty();
	//test_queue_pop_empty();
	//test_queue_top_empty();
	cout << "\nEND";
	return 0;
}