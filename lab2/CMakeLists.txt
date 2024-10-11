cmake_minimum_required(VERSION 3.10)
project(OOP_Lab2)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Подключаем заголовочные файлы
include_directories(include)

# Создаем библиотеку из исходников
add_library(OOP_Lab2_lib
    src/Six.cpp
    src/SixBuilder.cpp
)

# Создаем исполняемый файл для основной программы
add_executable(OOP_Lab2_exe main.cpp)

# Линкуем основную программу с библиотекой
target_link_libraries(OOP_Lab2_exe PRIVATE OOP_Lab2_lib)

# Включаем поддержку тестов
enable_testing()

# Создаем исполняемый файл для тестов
add_executable(OOP_Lab2_tests test/test.cpp)

# Линкуем тесты с библиотекой и Google Test
target_link_libraries(OOP_Lab2_tests OOP_Lab2_lib gtest_main)

# Добавляем тесты в тестовый набор
add_test(NAME OOP_Lab2_Tests COMMAND OOP_Lab2_tests)
