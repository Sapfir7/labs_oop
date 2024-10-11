#include "SixBuilder.h"
#include "Six.h"


SixBuilder::SixBuilder()=default;

SixBuilder& SixBuilder::size(long long value){
    object._size = value;
    return *this;
}

SixBuilder& SixBuilder::data(unsigned char * value){
    if (value == nullptr) {
        throw std::invalid_argument("Null is not permitted value");
    }
    object._array = new unsigned char[object._size]; 

    for (long long i = 0; i < object._size; i++) {
        object._array[object._size-1-i] = value[i];
    }
    return *this;
}


Six SixBuilder::build(){
    return object;
}



