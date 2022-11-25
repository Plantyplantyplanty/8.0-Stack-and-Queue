#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct node {
    T _item; //The item
    node<T>* _next; //Ptr to the next node
    node<T>* _prev;  //Ptr to the previous node

    //Constructor setting the item, next node, and previous node of this node
    node(const T& item = T(), node<T>* next = nullptr, node<T>* prev = nullptr) :_item(item), _next(next), _prev(prev){}

    friend ostream& operator <<(ostream& outs, const node<T>& n) {
        outs << "[" << n._item << "]->";
        return outs;
    }
};

//--------------------------------------------------------------------
//      prototypes
//--------------------------------------------------------------------
//Insert at the beginning of the list:
template<typename T>
node<T>* _insert_head(node<T>*& head, const T& item);

//Print the list and return "outs"
template<typename T>
ostream& _print_list(const node<T>* head, ostream& outs = cout);

//Initializes head to NULL
template <class T>
node<T>* init_head(node<T>*& head);

//Deletes all the nodes in the list
template<class T>
void delete_all(node<T>*& head);

//True if head is nullptr, false otherwise.
template <class T>
bool empty(const node<T>* head);

//Makes a copy of the list and returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>*& cpy);

//If after is NULL, inserts at head, otherwise inserts after "after"
template <class T>
node<T>* insert_after(node<T>*& head, node<T>* after, const T& item);

//Delete the node at the head of the list, returning its item:
template <class T>
T delete_head(node<T>*& head);

//Returns the item in the head to avoid pointer references
template <class T>
T return_item(node<T>*& head);
//--------------------------------------------------------------------
//  Definitions:
//--------------------------------------------------------------------
template<typename T>
node<T>* _insert_head(node<T>*& head, const T& item) {
    //Three steps:
    //1. make a new node:
    node<T>* temp = new node<T>(item);
    //2. point this node to where head is pointing:
    temp->_next = head;

    if (head != nullptr) {
        head->_prev = temp;
    }
    //3. point head to this new node:
    head = temp;

    return head;
}

template<typename T>
ostream& _print_list(const node<T>* head, ostream& outs) {
    //h->>[ ]->[ ]->[ ]->|||
    outs << "H->";
    //Walk through the list and print out each item
    for (const node<T>* walker = head; walker != nullptr; walker = walker->_next) {
        outs << *walker;
    }
    outs << "|||";
    return outs;
}

//Initializes head to NULL
template <class T>
node<T>* init_head(node<T>*& head) {
    head = nullptr;
    return head;
}

//Deletes all the nodes in the list
template<class T>
void delete_all(node<T>*& head) {
    //Loops through the whole list
    while (head != nullptr) {
        delete_head(head);
    }
}

//True if head is NULL, false otherwise.
template <class T>
bool empty(const node<T>* head) {
    return head == nullptr;
}

//If after is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>*& head, node<T>* after, const T& item) {
    if (after == nullptr) {
        _insert_head(head, item);
        return head;
    }
    else {
        assert(head != nullptr);
        //Create a new node with the item, after BEFORE it and after->next AFTER it
        node<T>* new_node = new node<T>(item, after->_next, after);

        after->_next = new_node;
        return new_node;
    }
}

//Deletes the node at the head of the list and returns the item:
template <class T>
T delete_head(node<T>*& head) {
    assert(head != nullptr && "Delete_head: head is null");

    T to_return = head->_item;
    node<T>* temp = head->_next;

    if (temp != nullptr) {
        temp->_prev = nullptr;
    }

    delete head;
    head = temp;
    return to_return;
}

template <class T>
node<T>* copy_list(const node<T>* src, node<T>*& dest) {
    delete_all(dest);
    node<T>* next_node = nullptr; 

   for (const node<T>* walker = src; walker != nullptr; walker = walker->_next) {
            //insert a copy of the node after, save it, insert the next one after it...
            next_node = insert_after(dest, next_node, walker->_item);
   }
  
    
    return next_node;
}

//Returns the item in the head to avoid pointer references
template <class T>
T return_item(node<T>*& head) {
    assert(head != nullptr);
    return head ->_item;
}
//--------------------------------------------------------------------
//  test functions:
//--------------------------------------------------------------------

void test_node() {
    cout << "testing node: printing three nodes: " << endl;
    node<int> n1;           //0, nullptr
    node<int> n2(5);        //5, nullptr
    node<int> n3(6, &n1);   //6, address of n1
    cout << n1 << n2 << n3 << endl;
}

void test_insert_head() {
    cout << "testing insert_head: inserting 0..9 at head and printing: " << endl;
    node<int>* head = nullptr;
    for (int i = 0; i < 10; i++) {
        _insert_head(head, i);
    }
    _print_list(head);

    node<int>* head2 = nullptr;
    node<int>* tail2 = copy_list(head, head2);

    cout << "\ntesting copy list" << endl;
    _print_list(head2);

    cout << "\nPrinting backwards" << endl;
    cout << "H->";
    for (node<int>* walker = tail2; walker != nullptr; walker = walker->_prev) {
            cout << *walker;
    }
    cout << "|||\n";

    cout << "\nDeleting All" << endl;
    delete_all(head);
    cout << "Printing List" << endl;
    _print_list(head);
    cout << "\nIs List Empty?" << endl;
    cout << empty(head);

    cout << endl;
}

void test_delete_head() {
    cout << "\ntesting insert_head: inserting 0..9 at head and printing: " << endl;
    node<int>* head = nullptr;
    for (int i = 0; i < 10; i++) {
        _insert_head(head, i);
    }
    _print_list(head);
    cout << "\nDeleting head" << endl;

    while (head != nullptr) {
        cout << "Deleting " << delete_head(head) << " ";   
    }
    cout << endl;
}

void test_insert_after() {
    cout << "testing insert_after: " << endl;
    node<int>* head = nullptr;
    node<int>* temp = nullptr;

    head = insert_after(head, temp, 1);
    temp = insert_after(head, head, 2);

    insert_after(head, head, 3);

    _print_list(head);
}
#endif // LIST_FUNCTIONS_H