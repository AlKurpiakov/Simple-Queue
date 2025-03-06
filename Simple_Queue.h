#include <iostream>
using namespace std;

template <typename T>
class SimpleQueue{
private:
    T* _data;
    size_t _startIndex;
    size_t _endIndex;
    size_t _size;
   size_t _capacity;


public:
    
    SimpleQueue(size_t capacity): _size(capacity), _data(new T[_capacity]),
                                  _startIndex(0), _capacity(0), 
                                  _endIndex(0){}
    
    ~SimpleQueue(){
        delete[] _data;
    }
    
    void Pop(){
        if (IsEmpty())   throw "Queue is empty";
        _capacity--;
        _startIndex = (_startIndex + 1) & (_size - 1);
    }
    
    void Push(const T& elem) {
        if (IsFull())   throw "Queue is full";

        _data[_endIndex] = elem;
        _endIndex = (_endIndex + 1) & (_size - 1);
        _capacity++;
    }
    

    void Push(T&& elem) {
        if (IsFull())   throw "Queue is full";
        
        _data[_size++] = T(elem);
        elem = T();
        _endIndex = (_endIndex + 1) & (_size - 1);
        _capacity++;
    }

    void Print(){
        for(size_t i = 0; i < _capacity; i++)
            cout << _data[(_startIndex + i) & (_size - 1)] << endl;
    }


    size_t Capacity()     {return _capacity;}
    
    bool IsEmpty()    {return _capacity == 0;}
    bool IsFull()     {return _size == _capacity;}
    

    T& Front() {
        if (IsEmpty()) {
            throw "Queue is empty";
        }
        return _data[_startIndex];
    }
    const T& Front() const {
        if (IsEmpty()) {
            throw "Queue is empty";
        }
        return _data[_startIndex];
    }


    T& Back() {
        if (IsEmpty()) {
            throw "Queue is empty";
        }
        return _data[_endIndex];
    }
    const T& Back() const {
        if (IsEmpty()) {
            throw "Queue is empty";
        }
        return _data[_endIndex];
    }

};
