#pragma once
#include "ValidationHandler.h"

class PentagonValidationHandler: public VaLidationHandler{
    public:
        void validate(const Figure& figure1) const  override;
        bool isAllowed(const Figure& fugure) const override;
};