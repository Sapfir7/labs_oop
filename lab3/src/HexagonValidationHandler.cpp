#include "HexagonValidationHandler.h"
#include "Hexagon.h"
#include "Figure.h"

const double EPS = 1e-9;

bool HexagonValidationHandler::isAllowed(const Figure& figure) const {
    try {
        dynamic_cast<const Hexagon &>(figure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

void HexagonValidationHandler::validate(const Figure& figure) const {
    for (int i = 0; i < 6; i++) {
        if (abs(figure.getPoints()[(i + 1) % 6] - figure.getPoints()[i]) <= EPS) {
            throw std::invalid_argument("Side with 0 length found");
        }
    }

    for (int i = 0; i < 6; i++) {
        if (isParalel(figure.getPoints()[(i + 1) % 6] - figure.getPoints()[i], 
                      figure.getPoints()[(i + 2) % 6] - figure.getPoints()[(i + 1) % 6])) {
            throw std::invalid_argument("Neighbor sides are parallel");
        }
    }
}
