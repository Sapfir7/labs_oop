#pragma once
#include "ValidationHandler.h"

template<class T> class RombValidationHandler: public VaLidationHandler<T>{
    public:
        void validate(const Figure<T>& figure1) const override;
        virtual bool isAllowed(const Figure<T>& fugure) const override;
};