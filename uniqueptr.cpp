#include <cstdlib>
#include <iostream>

template<typename T>
class unique_ptr {
    public:
    // constructor
    unique_ptr() : ptr(nullptr) {}
    explicit unique_ptr(T* p) : ptr(p) {}

    // destructor
    ~unique_ptr() {
        delete ptr;
    }

    // copy c
    unique_ptr(const unique_ptr& other) = delete;

    // copy a
    unique_ptr& operator=(const unique_ptr& ) = delete;

    // move c
    unique_ptr(unique_ptr&& other) {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    // move a
    unique_ptr& operator=(unique_ptr&& other) {
        if (this != &other) {
            delete ptr; // THIS FIRST!!
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }


    private:
    T* ptr;

};


int main() {
    return 0;
}