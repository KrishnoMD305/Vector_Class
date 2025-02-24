#include<iostream>
#include<algorithm> // For copy function
#include<stdexcept> // For noexcept
using namespace std;
template <typename T>
class vector{
private:
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
    vector(){
        data = nullptr;
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
        copy(other.data, other.data + size_, data);
    }
    //Move constructor
    vector(vector&& other) noexcept{
        // Moving ownership or stealing
        data = other.data;
        size_ = other.size_;
        capacity_ = other.capacity_;
        // The others need to be empty for surity
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    // Assignment operator (copy) 
    vector& operator=(const vector &other){
        if(this != other){
            size_ = other.size_;
            capacity_ = other.capacity_;
            delete[] data; // Freeing the older memory
            data = new T[capacity_]; // Allocating new memory
            copy(other.data, other.data+size_, data); // Copy the elements to the new allocated memory
        }
        return this; // Return it
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
            expandCapacity();
        }
        data[size_] = value;
        size_ = size_ + 1;
    }
    // Removing element from the end
    void pop_back(){
        if(size_ > 0){
            size_ --;
        }
    }
    // Return data with bound checking
    T& at(size_t index){
        if(index >= size_){
            throw out_of_range("Index Out of Range"); // Error Massage
        }
        return data[index];
    }
    // Return data without bound checking
    T& operator[](size_t index){
        return data[index];
    }
    
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
            T *newData = new T[capacity_];
            copy(data, data+size_, newData);
            delete[] data;
            data = newData;
        }
    }
    void resize(size_t newSize, const T& defaultValue = T()){
        if(newSize > capacity_){
            reserve(newSize);
        }
        for(size_t i=size_; i<newSize; ++i){
            data[i] = defaultValue;
        }
        size_ = newSize;
    }
};


int main(){
    return 0;
}
