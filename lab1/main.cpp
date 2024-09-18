#include <iostream>
#include "include/execute.h"

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << tobin(a, b);
    return 0;
}