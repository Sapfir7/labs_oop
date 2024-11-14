#pragma once
#include "ValidationHandler.h"

template <class T> class HexagonValidationHandler: public ValidationHandler<T> {
    public:
        void validate(const Figure<T>& figure) const override;
        bool isAllowed(const Figure<T>& figure) const override;
};
