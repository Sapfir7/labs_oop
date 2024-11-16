#include "Vector2.h"

namespace MyVector {

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector() : data(nullptr), size(0), capacity(0) {}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(int initial_capacity)
    : size(0), capacity(initial_capacity) {
    data = allocator.allocate(capacity);
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector& v)
    : size(v.size), capacity(v.capacity) {
    data = allocator.allocate(capacity);
    for (int i = 0; i < size; ++i) {
        allocator.construct(data + i, v.data[i]);
    }
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(Vector&& v) noexcept
    : data(v.data), size(v.size), capacity(v.capacity) {
    v.data = nullptr;
    v.size = 0;
    v.capacity = 0;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::~Vector() {
    for (int i = 0; i < size; ++i) {
        allocator.destroy(data + i);
    }
    if (data) {
        allocator.deallocate(data, capacity);
    }
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T, typename Allocator>
int Vector<T, Allocator>::getSize() const {
    return size;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::push_back(const T& element) {
    if (size == capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    allocator.construct(data + size, element);
    ++size;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::reserve(int new_capacity) {
    if (new_capacity > capacity) {
        T* new_data = allocator.allocate(new_capacity);
        for (int i = 0; i < size; ++i) {
            allocator.construct(new_data + i, std::move(data[i]));
            allocator.destroy(data + i);
        }
        if (data) {
            allocator.deallocate(data, capacity);
        }
        data = new_data;
        capacity = new_capacity;
    }
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::Iterator Vector<T, Allocator>::begin() {
    return Iterator(data);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::Iterator Vector<T, Allocator>::end() {
    return Iterator(data + size);
}

} 
