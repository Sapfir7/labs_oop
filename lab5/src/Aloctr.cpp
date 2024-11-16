#include <list>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace mai {
    template <class T, size_t BLOCK_SIZE>
    class allocator {
    private:
        std::list<T*> memory_blocks;
        T* memory_block;
        size_t block_size;
        size_t used_memory;

    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        template <typename U>
        struct rebind {
            using other = allocator<U, BLOCK_SIZE>;
        };

        allocator() : block_size(BLOCK_SIZE), used_memory(0) {
            memory_block = reinterpret_cast<T*>(::operator new(block_size * sizeof(T)));
            memory_blocks.push_back(memory_block);
        }

        template <typename U>
        allocator(const allocator<U, BLOCK_SIZE>&) : allocator() {}

        ~allocator() {
            for (T* block : memory_blocks) {
                ::operator delete(block);
            }
        }

        T* allocate(size_t n) {
            if (used_memory + n > block_size) {
                throw std::bad_alloc();
            }
            T* allocated_memory = memory_block + used_memory;
            used_memory += n;
            return allocated_memory;
        }

        void deallocate(T* p, size_t n) {

        }

        template <typename U, typename... Args>
        void construct(U* p, Args&&... args) {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(T* p) {
            p->~T();
        }
    };

    template <class T1, size_t BLOCK_SIZE1, class T2, size_t BLOCK_SIZE2>
    bool operator==(const allocator<T1, BLOCK_SIZE1>&, const allocator<T2, BLOCK_SIZE2>&) {
        return BLOCK_SIZE1 == BLOCK_SIZE2;
    }

    template <class T1, size_t BLOCK_SIZE1, class T2, size_t BLOCK_SIZE2>
    bool operator!=(const allocator<T1, BLOCK_SIZE1>&, const allocator<T2, BLOCK_SIZE2>&) {
        return !(BLOCK_SIZE1 == BLOCK_SIZE2);
    }
}
