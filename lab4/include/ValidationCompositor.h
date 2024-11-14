#pragma once
#include "TrapValidationHandler.h"
#include "RombValidationHandler.h"
#include "PentagonValidationHandler.h"
#include "ValidationHandler.h"
#include "Figure.h"
#include <vector>


template<class T>class ValidationCompositor{
    private:
        std::vector<std::shared_ptr<VaLidationHandler<T>>> validations;

    public:
    ValidationCompositor();
    virtual ~ValidationCompositor() = default;
    void validate(Figure<T>& figure) const;

};