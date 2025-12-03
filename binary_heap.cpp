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
upheap(int element)
{

    int root = parent(element);
    int leaf = element;
    while(heap[leaf - 1] > heap[root - 1]){
    std::iter_swap(heap.begin() + (leaf - 1), heap.begin() + (root - 1));
    leaf = root;
    root = parent(leaf);
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
void
print_with_branches() {
      if (heap.empty()) {
        std::cout << "<empty heap>\n";
        return;
    }

    int n = (int)heap.size();
    int height = (int)std::floor(std::log2(n)) + 1;

    int maxWidth = 0;
    for (int v : heap) {
        maxWidth = std::max(maxWidth, (int)std::to_string(v).size());
    }
    int nodeCell = maxWidth + 2;                  // «ячейка» одного узла
    int totalWidth = (1 << height) * nodeCell;    // ширина всей строки

    int startIdx = 0;

    for (int level = 0; level < height && startIdx < n; ++level) {
        int levelCount = 1 << level;
        int remaining  = n - startIdx;
        if (levelCount > remaining) levelCount = remaining;

        int step = totalWidth / (1 << level); // ширина блока на один узел этого уровня

        std::string nodesLine(totalWidth, ' ');
        std::string branchLine(totalWidth, ' ');

        bool hasChildren = false;

        for (int j = 0; j < levelCount; ++j) {
            int idx = startIdx + j;
            int center = step / 2 + j * step; // центр «ячейки» узла

            std::string s = std::to_string(heap[idx]);
            int len = (int)s.size();
            int leftPos = center - len / 2;

            // записываем число
            for (int k = 0; k < len && leftPos + k < totalWidth; ++k) {
                if (leftPos + k >= 0)
                    nodesLine[leftPos + k] = s[k];
            }

            int leftChild  = 2 * idx + 1;
            int rightChild = 2 * idx + 2;

            int branchOffset = step / 4;
            if (branchOffset < 1) branchOffset = 1;

            if (leftChild < n) {
                int pos = center - branchOffset;
                if (pos >= 0 && pos < totalWidth)
                    branchLine[pos] = '/';
                hasChildren = true;
            }
            if (rightChild < n) {
                int pos = center + branchOffset;
                if (pos >= 0 && pos < totalWidth)
                    branchLine[pos] = '\\';
                hasChildren = true;
            }
        }

        std::cout << nodesLine << '\n';
        if (hasChildren)
            std::cout << branchLine << '\n';

        startIdx += levelCount;
    }
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


  heap.print_with_branches();



  return 0;
}
