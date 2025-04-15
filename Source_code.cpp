// Created By Krishno Mondol 24 February, 2025
// GitHub
#include<iostream>
#include<algorithm> // For copy function
#include<stdexcept> // For noexcept
using namespace std;
template <typename T>
class vector{
private:
// In private we declare the main data size capacity and the expand function
    T *data; // A pointer to a dynamic array
    size_t size_; // Number of elements
    size_t capacity_; // Allocated memory size
    
    // This function is needed to expand capacity when it is needed
    void expandCapacity(){
        capacity_ = (capacity_ == 0) ? 1 : 2*capacity_; // Expanding capacity
        
        T *newdata = new T[capacity_]; // Allocating memory for the new capacity
        
        copy(data, data+size_, newdata); // Copy the old data in new location
        delete[] data; // Freeing the old memory
        data = newdata; // Giving access to the data pointer of the new allocated extended memory
    }
public:
    // Basic declaration constructor
    vector(){ // This is basic declaration of vector in main function / Declaring empty vector
        data = nullptr; // No allocated memory, initially no memory is allocated
        size_ = 0;
        capacity_ = 0;
    }
    ~vector(){
        delete[] data;
    }
    // Copy Constructor
    vector(const vector &other){
        // Copying all elements
        size_ = other.size_;
        capacity_ = other.capacity_;
        data = new T[capacity_];
        copy(other.data, other.data + size_, data); // Copy the elements from other to data
    }
    //Move constructor
    vector(vector&& other) noexcept{ //
        // noexcept is used to tell the compiler that the elements are moving from one cantainer to another container 
        // double ampersand is used to shallow copy the other. It is used to make the operation faster
        // Moving ownership or stealing
        data = other.data; // Just transferring ownership
        size_ = other.size_;
        capacity_ = other.capacity_;
        // The others need to be empty for surity
        other.data = nullptr; // Nullify the source object
        other.size_ = 0;
        other.capacity_ = 0;
    }
    // Assignment operator (copy) 
    vector& operator=(const vector &other){ // When "=" is used to copy
        if(this != other){ // Avoid self assignment
            size_ = other.size_;
            capacity_ = other.capacity_;
            delete[] data; // Freeing the older memory
            data = new T[capacity_]; // Allocating new memory
            copy(other.data, other.data+size_, data); // Copy the elements to the new allocated memory
        }
        return this; // Return reference to current object
    }
    // Assignment operator (move)
    vector& operator=(vector &&other){
        if(this != other){
            delete[] data; // Freeing the memory
            data = other.data; // Transferring the ownership
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data = nullptr; // Making the other null
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return this;
    }
    
    // Size
    size_t size(){
        return size_;
    }
    // Capacity
    size_t capacity(){
        return capacity_;
    }
    // Adding element to the end
    void push_back(const T &value){
        if(size_ == capacity_){
            expandCapacity(); // Expand when the container is full
        }
        data[size_] = value;
        size_ = size_ + 1; // New size is assigned as we insert a new element
    }
    // Removing element from the end
    void pop_back(){
        if(size_ > 0){
            size_ --; // Just making the size 1 short means that the container has realese the last element
        }
    }
    // Return data with bound checking
    T& at(size_t index){
        if(index >= size_){ // Provide bound checking access
            throw out_of_range("Index Out of Range"); // Error Massage if throws an error
        }
        return data[index];
    }
    // Return data without bound checking
    T& operator[](size_t index){
        return data[index];
    }

    // Returns iterators (pointers) to the beginning and end of the container
    
    T* begin(){
        return data;
    }
    T* end(){
        return data+size_;
    } 
    // Reserving storage for new elements without changing the size
    void reserve(size_t newCapacity){
        if(capacity_ < newCapacity){
            capacity_ = newCapacity;
            T *newData = new T[capacity_]; //Allocate memory for the new capacity
            copy(data, data+size_, newData); // Copying the previous element
            delete[] data;
            data = newData;
        }
    }
    void resize(size_t newSize, const T& defaultValue = T()){ // If second argument is not passed then it will assign default value
        if(newSize > capacity_){
            reserve(newSize); // If the newSize is large, then allocate more memory for the given size
        } // If increased, filled new slots with default values
        for(size_t i=size_; i<newSize; ++i){
            data[i] = defaultValue;
        }
        size_ = newSize;
    }
};


int main(){
    return 0;
}
