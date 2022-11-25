
#ifndef MY_STACK_H
#define MY_STACK_H

#include "list_functions.h"

template <typename T>
class Stack {
public:
    class Iterator {
        friend class Stack;
    public:
        Iterator(node<T>* p = nullptr) :_ptr(p) {}

        Iterator next()                     //return an iterator to the
        {
            assert(_ptr);                               //next location in the list
            return Iterator(_ptr->_next);
        }

        Iterator prev()                     //return an iterator to the
        {
            assert(_ptr);                                //previous location in the list
            return Iterator(_ptr->_prev);
        }

        /*You should not be able to change items inside the queue*/

        const T* operator->()const {                    //dereference operator
            assert(_ptr);
            return &(_ptr->_item);
        }

        const T& operator *()const {        //dereference operator
            assert(_ptr);
            return _ptr->_item;
        }

        friend Iterator operator ++(Iterator& it, int unused) {
            Iterator hold;
            hold = it;
            it = it.next();
            return hold;
        }

        Iterator& operator ++() {                        //++it
            assert(_ptr);
            _ptr = _ptr->_next;
            return *this;
        }

        friend Iterator operator --(Iterator& it, int unused) {
            Iterator hold;
            hold = it;
            it = it.prev();
            return hold;
        }

        Iterator& operator --() {
            assert(_ptr);
            _ptr = _ptr->_prev;
            return *this;
        }


        friend bool operator !=(const Iterator& left, const Iterator& right) {
            return left._ptr != right._ptr;
        }


        friend bool operator ==(const Iterator& left, const Iterator& right) {
            return left._ptr == right._ptr;
        }

        bool ifNull() {
            if (_ptr == nullptr) {
                return true;
            }
            else
                return false;
        }
    private:
        node<T>* _ptr;
    };

    Stack();

    //big three functions:
    Stack(const Stack& other);
    Stack& operator=(const Stack& rhs);
    ~Stack();

    void push(const T& item);
    T pop();
    bool empty();
    T top();
    Iterator begin();

    friend ostream& operator <<(ostream& outs, const Stack& s) {
        _print_list(s._top, outs);
        return outs;
    }
private:
    node<T>* _top;
};

template <typename T>
Stack<T>::Stack<T>() {
    init_head(_top);
}
//big three functions:
template <typename T>
Stack<T>::Stack(const Stack& other) {
    init_head(_top);
    copy_list(other._top, _top);
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) {
    //check for self-reference
    if (&rhs != this) {
        delete_all(_top);
       //call function to copy rhs into this object
        copy_list(rhs._top, _top);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    delete_all(_top);
}
template <typename T>
void Stack<T>::push(const T& item) {
    _insert_head(_top, item);
}
template <typename T>
T Stack<T>::pop() {
    assert(!empty() && "Stack: empty object cannot be popped.");
    //call function to remove node at head (_top) and reutn the item.
    return delete_head(_top);
}
template <typename T>
bool Stack<T>::empty() {
    return _top == nullptr;
}
template <typename T>
T Stack<T>::top() {
    assert(!empty() && "Stack: top of empty object does not exist.");
    //grab the first item and return it.
    return return_item(_top);
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() {
    return Stack<T>::Iterator(_top);
}

/*------------------------------------------------------------------
//  test functions:
1. declare an instance of the Stack(Queue) class, in a for loop, push 0..9 into the object, 
   print the object

2. Declare another object using the copy constructor to be a copy of this first object.

3. while the container is not empty, pop(show the popped item in braces{ }) and reprint the 
   object

4. when the object is empty, assign the second object back into the firstand reprint both 
   objects.
/*------------------------------------------------------------------*/

void test_stack_push() {
    cout << "Stack: pushing 0..9 into stack here: " << endl;
    Stack<int> s;
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    cout << "S:" << s << endl;

    Stack<int> s2(s);
    cout << "Copy of S:"<< s2 << endl;

    s = s;

    while (!s.empty()) {
        cout << "/S.top: " << s.top();
        cout << " /Popping " << s.pop();
        cout << " /S:" << s << endl;
    }

    cout << "Copy of S:" << s2 << endl;
    s = s2;
    cout << "S:" << s << endl;


    cout << "\nTesting Iterators. WILL BE ONE OFF IN THE FORWARD DIRECTION.\n";
    Stack<int>::Iterator it = s.begin();

    for (it; !(it.next() == nullptr); ++it) {
        cout << *it;
    }

    cout << "\n";

    for (it; !(it.prev() == nullptr); --it) {
        cout << *it;
    }

    cout << *(it--);
}

void test_stack_pop_empty() {
    cout << "Stack: popping empty Stack" << endl;
    Stack<int> s;
    s.pop();
}

void test_stack_top_empty() {
    cout << "Stack: top of an empty Stack." << endl;
    Stack<int> s;
    cout << s.top() << endl;;
}

#endif