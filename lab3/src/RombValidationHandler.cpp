#include "RombValidationHandler.h"
#include "Romb.h"
#include "Figure.h"

const double EPS = 1e-9;

bool RombValidationHandler::isAllowed(const Figure& fugure) const {
    try {
        dynamic_cast<const Romb &>(fugure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

void RombValidationHandler::validate(const Figure& figure) const {
    for (int i = 0; i < 4; i++) {
        if (abs(figure.getPoints()[(i + 1) % 4] - figure.getPoints()[i]) <= EPS) {
            throw std::invalid_argument("The side with 0 length found(");
        }
    }

    for (int i = 0; i < 4; i++) {
        if (isParalel(figure.getPoints()[(i + 1) % 4] - figure.getPoints()[i], figure.getPoints()[(i + 2) % 4] - figure.getPoints()[(i + 1) % 4])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }

    if ((!isParalel(figure.getPoints()[0] - figure.getPoints()[3], figure.getPoints()[2] - figure.getPoints()[1])) || (!isParalel(figure.getPoints()[3] - figure.getPoints()[2], figure.getPoints()[1] - figure.getPoints()[0])) ){
         throw std::invalid_argument("opposite sides arent paralell");
    }

}

