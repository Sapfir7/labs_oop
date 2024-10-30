#pragma once
#include "HexagonValidationHandler.h"
#include "RombValidationHandler.h"
#include "PentagonValidationHandler.h"
#include "ValidationHandler.h"
#include "Figure.h"
#include <vector>


class ValidationCompositor{
    private:
        std::vector<VaLidationHandler* > validations;

    public:
    ValidationCompositor();
    virtual ~ValidationCompositor();
    void validate(Figure& figure) const;

};