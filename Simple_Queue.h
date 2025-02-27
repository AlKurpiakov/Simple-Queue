#include <iostream>
using namespace std;

template <typename T>
class SimpleQueue{
private:
    T* _data;
    size_t _capacity;
    size_t _size;
    size_t _backIndex;


    void Move(){
        for (int i = 0; i < _size; i++) {
            _data[i] = _data[i+1];
        }
    }

public:
    
    SimpleQueue(size_t _capacity):  _capacity(_capacity), 
                                    _size(0), _backIndex(0),
                                    _data(new T[_capacity]){}
    
    ~SimpleQueue(){
        delete[] _data;
    }
    
    void Pop(){
        if (IsEmpty())   throw "Queue is empty";
        _size--;
        (_size == 0) ? _backIndex = 0 : _backIndex--;
        Move();
    }
    
    void Push(const T& elem) {
        if (IsFull())   throw "Queue is full";
        (_size == 0) ? : _backIndex++;
        _data[_size++] = elem;
    }
    

    void Push(T&& elem) {
        if (IsFull())   throw "Queue is full";
        (_size == 0) ? : _backIndex++;
        _data[_size++] = T(elem);
        elem = T();
    }


    size_t Size()     {return _size;}
    
    bool IsEmpty()    {return _size == 0;}
    bool IsFull()     {return _size == _capacity;}
    

    T& Front() {
        if (IsEmpty()) {
            throw "Queue is empty";
        }
        return _data[0];
    }
    const T& Front() const {
        if (IsEmpty()) {
            throw "Queue is empty";
        }
        return _data[0];
    }


    T& Back() {
        if (IsEmpty()) {
            throw "Queue is empty";
        }
        return _data[_backIndex];
    }
    const T& Back() const {
        if (IsEmpty()) {
            throw "Queue is empty";
        }
        return _data[_backIndex];
    }

};
