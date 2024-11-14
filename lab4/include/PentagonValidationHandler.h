#pragma once
#include "ValidationHandler.h"

template <class T> class PentagonValidationHandler: public VaLidationHandler<T>{
    public:
        void validate(const Figure<T>& figure1) const  override;
        bool isAllowed(const Figure<T>& fugure) const override;
};