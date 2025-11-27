#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


template <typename T>

class BinaryHeap{
public:

  BinaryHeap() = delete;

  BinaryHeap(std::vector<T> vector){

    construct(vector);
    
  }

void
my_insert(T element)
{

  heap.push_back(element);
  upheap(heap.size());

}

void 
print()
{

    for(auto pox : heap){
      std::cout << pox << " ";
    }
}

void
upheap(int element)
{

    int root = parent(element);
    int leaf = element;
    while(heap[leaf - 1] > heap[root - 1]){
    std::iter_swap(heap.begin() + (leaf - 1), heap.begin() + (root - 1));
    element = root;
    root = parent(element);
    }

  }

T
find_Min()
{


}

T 
find_Max()
{

    return heap.at(0);

}

T
extract_Max() 
{

    T max = heap.at(0);
    heap.erase(0);
    return max;

}

void
construct(const std::vector<T>& vector)
{

   for(int i = 0; i < vector.size() - 1; ++i){
      my_insert(vector.at(i));
    } 

}
private:
  
  std::vector<T> heap;

int 
parent(int i)
{

  if(i == 1) return 1;

  return i/2;

}

int
left(int i)
{

    return (2*i + 1); 
}

};

int
right(int i)
{

  return (2*i + 2);

}


int main(){
  std::vector vec{10, 20, 30 ,40, 15, 115, 52};

  BinaryHeap heap(vec);

  heap.print();


  return 0;
}
