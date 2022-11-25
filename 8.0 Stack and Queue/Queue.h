#ifndef QUEUE_H
#define QUEUE_H

#include "list_functions.h"

template <typename T>
class Queue {
public:
    class Iterator {
        friend class Queue;
    public:
        Iterator(node<T>* p = nullptr) :_ptr(p) {}

        Iterator next()                     //return an iterator to the
        {
            assert(_ptr);                                //next location in the list
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
    Queue();

    //big three functions:
    Queue(const Queue& other);
    Queue& operator=(const Queue& rhs);
    ~Queue();

    void push(const T& item); //puts items at the REAR of the queue
    T pop(); //Returns/deletes from the FRONT of the queue
    bool empty();
    T top(); //Returns the item from the FRONT of the queue
    Iterator begin();
    Iterator rear();
    friend ostream& operator <<(ostream& outs, const Queue& s) {
        _print_list(s._front, outs);
        return outs;
    }
private:
    node<T>* _front;
    node<T>* _rear;
};

template <typename T>
Queue<T>::Queue() {
    init_head(_front);
    init_head(_rear);
}
//big three functions:
template <typename T>
Queue<T>::Queue(const Queue& other) {
    init_head(_front);
    _rear = copy_list(other._front, _front);
}
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& rhs) {
    if(&rhs != this){
      //call function to clear this object.
        delete_all(_front);
      //call function to copy rhs into this object
       _rear = copy_list(rhs._front, _front);
    }
    
    return *this;
}

template <typename T>
Queue<T>::~Queue() {
    delete_all(_front);
    _rear = nullptr;
}

//Insert node at the back of the queue
template <typename T>
void Queue<T>::push(const T& item) {
    _rear = insert_after(_front,_rear, item);
}

//Return and delete item from the front of the queue
template <typename T>
T Queue<T>::pop() {
    assert(!empty() && "queue: empty object cannot be popped.");
    return delete_head(_front);
}
template <typename T>
bool Queue<T>::empty() {
    return _front == nullptr;
}


template <typename T>
T Queue<T>::top() {
    assert(!empty() && "queue: top of empty object does not exist.");
    //grab the first item and return it.
    return return_item(_front);
}
template <typename T>
typename Queue<T>::Iterator Queue<T>::begin(){
     return Queue<T>::Iterator(_front);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::rear() {
    return Queue<T>::Iterator(_rear);
}
//------------------------------------------------------------------
//  test functions:
//------------------------------------------------------------------

void test_queue_push() {
    cout << "Queue: pushing 0..9 into Queue here: " << endl;
    Queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.push(i);
    }
    cout << q << endl;
}
void test_queue_pop_empty() {
    cout << "Queue: popping empty Queue" << endl;
    Queue<int> q;
    q.pop();
}

void test_queue_top_empty() {
    cout << "Queue: top of an empty Queue." << endl;
    Queue<int> q;
    cout << q.top() << endl;;
}

void test_queue() {
    cout << "Queue: pushing 0..9 into Queue here: " << endl;
    Queue<int> s;
 
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    cout << "S:" << s << endl;

    Queue<int> s2(s);
    cout << "Copy of S:" << s2 << endl;

    s = s;

    while (!s.empty()) {
        cout << "/S.top: " << s.top();
        cout << " /Popping " << s.pop();
        cout << " /S:" << s << endl;
    }

    cout << "S:" << s << endl;
    cout << "Copy of S:" << s2 << endl;
    s = s2;
    cout << "S after Copy of S:" << s << endl;

    cout << "Testing iterators: \n";

    Queue<int>::Iterator it = s.begin();

    for (it; !(it.next() == nullptr); ++it) {
        cout << *it;
    }
    cout << *(it++);

    cout << "\n";

    it = s.rear();
    for (it; !(it.prev() == nullptr); --it) {
        cout << *it;
    }

    cout << *(it--);
}

#endif //QUEUE_H