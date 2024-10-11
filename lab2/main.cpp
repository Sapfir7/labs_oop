#include <iostream>
#include "Six.h"
#include "SixBuilder.h"


int main(){

    Six first;
    first.print(std::cout) << std::endl;

    Six second {'5', '5', '5', '5'};
    second.print(std::cout) << std::endl;
    Six third {"5555"};
    third.print(std::cout) << std::endl;
    Six forth {third};
    forth.print(std::cout) << std::endl;
    std::cout << third.equals(forth) << "\n";
    std::cout << third.operator<(second) << "\n";
    std::cout << third.operator>(second) << "\n";
    std::cout << third.operator>(forth) << "\n";
    std::cout << third.operator<(forth) << "\n";
    Six reslt  {second.remove(third)};
    reslt.print(std::cout) << std::endl;
    size_t n = 20;
    Six fifth(n, '0');
    fifth.print(std::cout) << "\n";

    Six res {second.add(third)};
    res.print(std::cout) << "\n";
    Six result {third.add(second)};
    result.print(std::cout) << "\n";
    // unsigned char arr[] = "555";
    // Six test {SixBuilder().size(3).data(arr).build()};
    // test.print(std::cout) << "\n";
    // Six re(std::move(second));
    // re.print(std::cout) << "\n";

}