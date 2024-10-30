#pragma once
#include "ValidationHandler.h"

class RombValidationHandler: public VaLidationHandler{
    public:
        void validate(const Figure& figure1) const override;
        virtual bool isAllowed(const Figure& fugure) const override;
};