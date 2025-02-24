# Custom Vector Implementation in C++

## Introduction
This project is a custom implementation of a **vector** class in C++ that replicates the core functionalities of `std::vector`. It provides dynamic array capabilities with efficient memory management and supports essential operations such as size tracking, capacity management, element insertion, and deletion.

## Features
- **Size & Capacity Functions**
  - `size()`: Returns the current number of elements in the vector.
  - `capacity()`: Returns the current allocated memory capacity of the vector.

- **Element Access & Modification**
  - Supports assignment (`=`) operator similar to `std::vector`.

- **Modification Functions**
  - `push_back(value)`: Adds an element to the end of the vector.
  - `pop_back()`: Removes the last element of the vector.
  - `reserve(new_capacity)`: Allocates memory for at least `new_capacity` elements.
  - `resize(new_size)`: Resizes the vector to contain `new_size` elements.

- **Iterators**
  - `begin()`: Returns an iterator to the first element.
  - `end()`: Returns an iterator to the past-the-end element.

## How to Use
1. **Create a Header File**
   - Make a new header file, e.g., `vector.h`.

2. **Copy the Source Code**
   - Copy the vector implementation source code into this header file.

3. **Include Necessary Header Files**
   - Ensure you include all necessary C++ standard library headers required for your implementation.

4. **Exclude `iostream` and `main()` Function**
   - Do not include `#include <iostream>` in the header file.
   - Do not write the `main()` function inside the header file.

5. **Include the Header in Your Program**
   - In your main program file, include `vector.h` and use your custom vector class as needed.

## Example Usage
```cpp
#include <iostream>
#include "vector.h"

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
    
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
```



