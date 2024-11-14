#include "PentagonValidationHandler.h"
#include "Pentagon.h"
#include "Figure.h"

// const double EPS = 1e-9;

template<class T> bool PentagonValidationHandler<T>::isAllowed(const Figure<T>& fugure) const {
    try {
        dynamic_cast<const Pentagon<T> &>(fugure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

template<class T> void PentagonValidationHandler<T>::validate(const Figure<T>& figure) const {
    for (int i = 0; i < 5; i++) {
        if (abs(figure.getPoints().get()[(i + 1) % 4] - figure.getPoints().get()[i]) <= 1e-9) {
            throw std::invalid_argument("The side with 0 length found(");
        }
    }

    for (int i = 0; i < 5; i++) {
        if (isParalel(figure.getPoints().get()[(i + 1) % 5] - figure.getPoints().get()[i], figure.getPoints().get()[(i + 2) % 5] - figure.getPoints().get()[(i + 1) % 5])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }

}

