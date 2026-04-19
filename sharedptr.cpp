#include <cstdlib>
#include <iostream>


template<typename T>
class mySharedPtr {
    public:
    // constructor
    mySharedPtr(T* ptr = nullptr) : shared_ptr(ptr), ref_ct(new int(ptr ? 1:0)) {}

    // destructor
    ~mySharedPtr() {
        release();
    }

    // copy construtor
    mySharedPtr(const mySharedPtr& ptr) {
        shared_ptr = ptr.shared_ptr;
        ref_ct = ptr.ref_ct;
        if(shared_ptr) (*ref_ct)++;
    }

    // copy assignment
    mySharedPtr& operator=(mySharedPtr ptr) {
        std::swap(shared_ptr, ptr.shared_ptr);
        std::swap(ref_ct, ptr.ref_ct);
        return *this;
    }

    // move constructor
    mySharedPtr(mySharedPtr&& ptr) {
        shared_ptr = ptr.shared_ptr;
        ref_ct = ptr.ref_ct;
        ptr.shared_ptr = nullptr;
        ptr.ref_ct = nullptr;
    }

    // move assignment
    mySharedPtr& operator=(mySharedPtr&& ptr) {
        if(this != &ptr) {
            release();
            shared_ptr = ptr.shared_ptr;
            ref_ct = ptr.ref_ct;
            ptr.shared_ptr = nullptr;
            ptr.ref_ct = nullptr;
        }
        return *this;
    }



    private:
    void release() {
        if(ref_ct) {
            if (shared_ptr) (*ref_ct)--;
            if(*ref_ct <= 0) {
                delete shared_ptr;
                delete ref_ct;
                shared_ptr = nullptr;
                ref_ct = nullptr;
            }
        }
    }

    T* shared_ptr;
    int* ref_ct;

};


int main() {


    return 0;
}
