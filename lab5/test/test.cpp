#include <gtest/gtest.h>
#include "./../include/Vector2.h"
#include "./../src/Aloctr.cpp"

TEST(VectorTest, DefaultConstructor) {
    MyVector::Vector<int, mai::allocator<int, 10>> vec;
    EXPECT_EQ(vec.getSize(), 0);
}

TEST(VectorTest, PushBack) {
    MyVector::Vector<int, mai::allocator<int, 10>> vec;
    vec.push_back(42);
    EXPECT_EQ(vec.getSize(), 1);
    EXPECT_EQ(vec[0], 42);
}

TEST(VectorTest, Reserve) {
    MyVector::Vector<int, mai::allocator<int, 10>> vec(5);
    vec.reserve(10);
    EXPECT_EQ(vec.getSize(), 0);
}

TEST(VectorTest, PushBackCapacityIncrease) {
    MyVector::Vector<int, mai::allocator<int, 10>> vec;
    for (int i = 0; i < 20; ++i) {
        vec.push_back(i);
    }
    EXPECT_EQ(vec.getSize(), 20);
    EXPECT_EQ(vec[19], 19);
}

TEST(VectorTest, CopyConstructor) {
    MyVector::Vector<int, mai::allocator<int, 10>> vec;
    vec.push_back(1);
    vec.push_back(2);

    MyVector::Vector<int, mai::allocator<int, 10>> vec_copy(vec);
    EXPECT_EQ(vec_copy.getSize(), 2);
    EXPECT_EQ(vec_copy[0], 1);
    EXPECT_EQ(vec_copy[1], 2);
}

TEST(VectorTest, MoveConstructor) {
    MyVector::Vector<int, mai::allocator<int, 10>> vec;
    vec.push_back(1);
    vec.push_back(2);

    MyVector::Vector<int, mai::allocator<int, 10>> vec_move(std::move(vec));
    EXPECT_EQ(vec_move.getSize(), 2);
    EXPECT_EQ(vec_move[0], 1);
    EXPECT_EQ(vec_move[1], 2);
}

TEST(VectorTest, Iterator) {
    MyVector::Vector<int, mai::allocator<int, 10>> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }

    int expected = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        EXPECT_EQ(*it, expected++);
    }
}

TEST(AllocatorTest, CustomAllocator) {
    mai::allocator<int, 10> alloc;
    int* ptr = alloc.allocate(5);
    for (int i = 0; i < 5; ++i) {
        alloc.construct(ptr + i, i);
    }

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(ptr[i], i);
    }

    for (int i = 0; i < 5; ++i) {
        alloc.destroy(ptr + i);
    }
    alloc.deallocate(ptr, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
