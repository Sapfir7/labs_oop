#include "PentagonValidationHandler.h"
#include "Pentagon.h"
#include "Figure.h"

const double EPS = 1e-9;

bool PentagonValidationHandler::isAllowed(const Figure& fugure) const {
    try {
        dynamic_cast<const Pentagon &>(fugure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

void PentagonValidationHandler::validate(const Figure& figure) const {
    for (int i = 0; i < 5; i++) {
        if (abs(figure.getPoints()[(i + 1) % 4] - figure.getPoints()[i]) <= EPS) {
            throw std::invalid_argument("side with 0 length found(");
        }
    }

    for (int i = 0; i < 5; i++) {
        if (isParalel(figure.getPoints()[(i + 1) % 5] - figure.getPoints()[i], figure.getPoints()[(i + 2) % 5] - figure.getPoints()[(i + 1) % 5])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }

}

