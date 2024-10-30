#pragma once
#include <Figure.h>
#include <vector>

class VaLidationHandler{
    public:
        virtual void validate(const Figure& figure1) const = 0;
        virtual bool isAllowed(const Figure& fugure) const = 0;
};