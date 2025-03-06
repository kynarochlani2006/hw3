#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> elements;
  int m;

  PComparator comp;

  void heapifyUP(size_t index);
  void heapifyDOWN(size_t index);

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m(m), comp(c) {}


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return elements.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return elements.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){

  elements.push_back(item);
  size_t i = elements.size() - 1;

  while(i > 0){
    size_t theParent = (i - 1) / m;
    if(comp(elements[i], elements[theParent])){
      std::swap(elements[i], elements[theParent]);
      i = theParent;
    } else {
      break;
    }
  }
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("underflow error");



  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return elements.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("underflow error");  

  }

  std::swap(elements.front(), elements.back());
  elements.pop_back();
  

  if(!empty()){
    size_t index = 0;

    size_t size = elements.size();


    bool keepGoing = true;

    while(keepGoing){

      keepGoing = false;
      size_t topOne = index;

      for(int i = 1; i <= m; i++){
        size_t children = m *index + i;
        if(children < size && comp(elements[children], elements[topOne])){
          topOne = children;
        }
      }

      if(topOne != index){
        std::swap(elements[index], elements[topOne]);
        index = topOne;
        keepGoing = true;
      }
    }
  }

}

#endif

