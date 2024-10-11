#pragma once
#include "Six.h"
#include <iostream>

class SixBuilder{
    public:
        SixBuilder();
        SixBuilder& size(long long value);
        SixBuilder& data(unsigned char * value);
        Six build();
    private:
        Six object;
};