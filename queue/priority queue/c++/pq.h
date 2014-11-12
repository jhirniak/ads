/**
 * by Jaroslaw Hirniak
 * 11 November 2014
 */

#include <vector>
#include <limits>

template<typename T>
class PQ {
  private:
    virtual void upheap(int k);
    virtual void downheap(int k);
    virtual void downheap(std::vector<T> &heap, std::size_t k);
    virtual void downheap(std::vector<T> &heap, std::size_t N, std::size_t k);
    std::vector<T> heap;

  public:
    PQ() : heap{} {
      heap.push_back(std::numeric_limits<T>::max());
    }

    ~PQ() {
      heap.clear();
      delete heap; 
    }

    virtual void insert(T item);
    virtual T remove();
    virtual T replace(T item);
    virtual std::vector<T> heapsort(std::vector<T> &items);
    std::size_t size() {
      return heap.size() - 1;
    }
};
