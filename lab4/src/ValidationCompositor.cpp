#include "ValidationCompositor.h"
#include <vector>
#include "TrapValidationHandler.h"
#include "RombValidationHandler.h"
#include "PentagonValidationHandler.h"
#include "TrapValidationHandler.cpp"
#include "RombValidationHandler.cpp"
#include "PentagonValidationHandler.cpp"
#include <memory>


template<class T> void ValidationCompositor<T>::validate(Figure<T>& figure) const{
    for (std::shared_ptr<VaLidationHandler<T>> validator : validations){
       // VaLidationHandler* validator = validations[i];
       
        if (validator.get()->isAllowed(figure)){
            validator.get()->validate(figure);
            return;
        }
    }
}

template<class T> ValidationCompositor<T>::ValidationCompositor(){
   
    validations.push_back(  std::shared_ptr< VaLidationHandler<T> >(dynamic_cast<VaLidationHandler<T> *>(new TrapValidationHandler<T>())));
    validations.push_back(  std::shared_ptr< VaLidationHandler<T> >(dynamic_cast<VaLidationHandler<T> *>(new RombValidationHandler<T>())));
    validations.push_back(  std::shared_ptr< VaLidationHandler<T> >(dynamic_cast<VaLidationHandler<T> *>(new PentagonValidationHandler<T>())));


    // validations.push_back(std::make_shared(dynamic_cast<VaLidationHandler<T> *>( new RombValidationHandler<T>())));
    // validations.push_back(std::make_shared(dynamic_cast<VaLidationHandler<T> *>(new PentagonValidationHandler<T>())));
   // validations.push_back(dynamic_cast< std::shared_ptr<VaLidationHandler<T>> >( new TrapValidationHandler()));
   // validations.push_back(dynamic_cast<std::shared_ptr<VaLidationHandler<T>> >(new RombValidationHandler()));
   // validations.push_back(dynamic_cast >(new PentagonValidationHandler()));
    
}

