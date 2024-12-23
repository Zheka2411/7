#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array {
private:
    T* arr;
    int size;
    int capacity;

public:
    Array(int cap = 10) : capacity(cap), size(0) {
        arr = new T[capacity];
    }

    ~Array() {
        delete[] arr;
    }

    void push_back(T value) {
        if (size == capacity) {
            capacity *= 2;
            T* newArr = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = value;
    }

    T pop_back() {
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }
        return arr[--size];
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    int get_size() const {
        return size;
    }

    void clear() {
        size = 0;
    }
};

template <typename T>
class Stack {
private:
    Array<T> array;

public:
    void push(T value) {
        array.push_back(value);
    }

    T pop() {
        return array.pop_back();
    }

    T top() const {
        if (array.get_size() == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return array[array.get_size() - 1];
    }

    void clear() {
        array.clear();
    }

    bool is_empty() const {
        return array.get_size() == 0;
    }
};
