#include <iostream>
#include <vector>
#include <cstdint>



template<typename Element>
class myVector{
public: 

  size_t size;

  size_t capacity;

  myVector() : data(nullptr), size(0), capacity(0){};

  size_t get_capacity() const {
    return capacity;
  }

  size_t get_size() const {
    return size;
  }


private:

  Element* data;
};


int main(){
  std::vector<int> vec;
  std::cout << "capacity: " << vec.capacity();
  std::cout << "size: " << vec.size();
  return 0;
}
