cmake_minimum_required(VERSION 3.10)
project(lab6)

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

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Подключаем заголовочные файлы
include_directories(include)


# Создаем исполняемый файл для основной программы
add_executable(lab5_exe main.cpp)

# Линкуем основную программу с библиотекой
target_link_libraries(lab5_exe PRIVATE lab5_lib)

# Включаем поддержку тестов
enable_testing()

# Создаем исполняемый файл для тестов
add_executable(lab6
    main.cpp
    src/npc.cpp
    src/elf.cpp
    src/dragon.cpp
    src/druid.cpp
    src/visitor.cpp
    src/observer.cpp
    src/factory.cpp
)

# Линкуем тесты с библиотекой и Google Test
target_link_libraries(tests lab6_lib gtest_main)

# Добавляем тесты в тестовый набор
add_test(NAME tests COMMAND tests)

