#pragma once
//#ifndef VECTOR_MYSELF_H
//#define VECTOR_MYSELF_H
using namespace std;

template<typename T>
class vector {
public:
    vector(int capacity = 4) {
        _a = new T[capacity]();
        _cap = _size = capacity;
    }
    vector(int capacity, const T value) {
        _a = new T[capacity]();
        _cap = _size = capacity;
        for (register int i = 0; i < capacity; ++i) {
            _a[i] = value;
        }
    }
    vector(const vector& v) {
        if (_a != NULL) delete[] _a;
        _a = new T[v._cap]();
        for (int i = 0; i < v._cap; ++i) {
            _a[i] = v._a[i];
        }
    }
    ~vector() {
        if (_a != NULL) delete[] _a;
    }
    void push_back(T value) {
        if (_size + 1 >= _cap) {
            T* tmp = new T[_cap << 1]();
            for (register int i = 0; i < _cap; ++i) {
                tmp[i] = _a[i];
            }
            if (_a != NULL) delete[] _a;
            _a = tmp;
            _cap <<= 1;
        }
        _a[_size++] = value;
    }
    void pop_back() {
        if (--_size < 0) throw "pop_back: Vector is empty";
    }
    int size() const {
        return _size;
    }
    bool empty() const {
        return _size == 0;
    }
    void clear() {
        _size = 0;
    }
    void clear_force() {
        _size = _cap = 0;
        if (_a) delete[] _a;
        _a = NULL;
    }
    T& operator [] (int idx) {
        return _a[idx];
    }
    T* begin() const {
        return _a;
    }
    T* end() const {
        return _a + _size;
    }
    const T& front() const {
        return _a[0];
    }
    const T& back() const {
        return _a[_size - 1];
    }
private:
    T* _a;
    int _size;
    int _cap;
};