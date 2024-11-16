#pragma once
#include <memory>
#include <iostream>
#include <stdexcept>

namespace MyVector {

template <typename Vector>
class VectorIterator {
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

    explicit VectorIterator(PointerType ptr) : ptr(ptr) {}

    VectorIterator& operator++() {
        ++ptr;
        return *this;
    }

    VectorIterator operator++(int) {
        VectorIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    ReferenceType operator*() const { return *ptr; }

    PointerType operator->() const { return ptr; }

    bool operator==(const VectorIterator& other) const { return ptr == other.ptr; }

    bool operator!=(const VectorIterator& other) const { return ptr != other.ptr; }

private:
    PointerType ptr;
};

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
public:
    using ValueType = T;
    using Iterator = VectorIterator<Vector<T, Allocator>>;

    Vector();
    explicit Vector(int size);
    Vector(const Vector& v);
    Vector(Vector&& v) noexcept;
    ~Vector();

    T& operator[](int index);
    int getSize() const;
    void push_back(const T& element);
    void reserve(int new_capacity);

    Iterator begin();
    Iterator end();

private:
    T* data;
    int size;
    int capacity;
    Allocator allocator;
};

} 
