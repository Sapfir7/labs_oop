#include "RombValidationHandler.h"
#include "Romb.h"
#include "Figure.h"

// const double EPS = 1e-9;

template<class T> bool RombValidationHandler<T>::isAllowed(const Figure<T>& fugure) const {
    try {
        dynamic_cast<const Romb<T> &>(fugure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

template<class T>void RombValidationHandler<T>::validate(const Figure<T>& figure) const {
    for (int i = 0; i < 4; i++) {
        if (abs(figure.getPoints().get()[(i + 1) % 4] - figure.getPoints().get()[i]) <= 1e-9) {
            throw std::invalid_argument("The side with 0 length found(");
        }
    }

    for (int i = 0; i < 4; i++) {
        if (isParalel(figure.getPoints().get()[(i + 1) % 4] - figure.getPoints().get()[i], figure.getPoints().get()[(i + 2) % 4] - figure.getPoints().get()[(i + 1) % 4])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }

    if ((!isParalel(figure.getPoints().get()[0] - figure.getPoints().get()[3], figure.getPoints().get()[2] - figure.getPoints().get()[1])) || (!isParalel(figure.getPoints().get()[3] - figure.getPoints().get()[2], figure.getPoints().get()[1] - figure.getPoints().get()[0])) ){
         throw std::invalid_argument("opposite sides arent paralell");
    }

}

