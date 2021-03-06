/*
 * This is a Allocator class
 * use for
 * - memory create and delete
 * - object constructor and destructor
 */

#ifndef TINYSTL_ALLOCATOR_H
#define TINYSTL_ALLOCATOR_H

#include <iostream>

namespace tiny_stl {
using std::size_t;

template <typename T>
class allocator {
 public:
  typedef T value_type;
  typedef size_t size_type;
  typedef std::ptrdiff_t difference_type;

 public:
  static T* allocate(size_type n = 1);
  static void deallocate(T* ptr);
  static void deallocate(T* ptr, size_type n);
};

template <typename T>
T* allocator<T>::allocate(size_type n) {
  return static_cast<T*>(::operator new(n * sizeof(T)));
}

template <typename T>
void allocator<T>::deallocate(T* ptr) {
  if (ptr == nullptr) {
    return;
  }

  ::operator delete(ptr);
}

template <typename T>
void allocator<T>::deallocate(T* ptr, size_type) {
  if (ptr == nullptr) {
    return;
  }

  ::operator delete[](ptr);
}

}  // namespace tiny_stl

#endif  // TINYSTL_ALLOCATOR_H
