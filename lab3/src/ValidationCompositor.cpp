#include "ValidationCompositor.h"
#include <vector>



void ValidationCompositor::validate(Figure& figure) const{
    for (VaLidationHandler* validator : validations){
       // VaLidationHandler* validator = validations[i];
       
        if (validator->isAllowed(figure)){
            validator->validate(figure);
            return;
        }
    }
}

ValidationCompositor::ValidationCompositor(){
    
    validations.push_back(dynamic_cast<VaLidationHandler *>( new HexagonValidationHandler()));
    validations.push_back(dynamic_cast<VaLidationHandler *>(new RombValidationHandler()));
    validations.push_back(dynamic_cast<VaLidationHandler *>(new PentagonValidationHandler()));
    
}

ValidationCompositor::~ValidationCompositor(){
    for (int i = 0; i < validations.size(); ++i){
        delete validations[i];
        
    }
}