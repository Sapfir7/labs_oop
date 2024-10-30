#pragma once
#include "ValidationHandler.h"

class HexagonValidationHandler : public VaLidationHandler {
    public:
        void validate(const Figure& figure) const override;
        bool isAllowed(const Figure& figure) const override;
};
