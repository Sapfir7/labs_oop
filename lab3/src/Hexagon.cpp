#include "Hexagon.h"
#include "Point.h"
#include "ValidationCompositor.h"


Hexagon::Hexagon() {
    points = new Point[6];
    figureName = "Hexagon";
}

Hexagon::Hexagon(const Point* points) {
    this->points = new Point[6];
    figureName = "Hexagon";
    for (int i = 0; i < 6; ++i) {
        this->points[i] = points[i];
    }
    ValidationCompositor validator;
    validator.validate(dynamic_cast<Figure&>(*this));
}


Figure* Hexagon::create(const Point* points) {
    return dynamic_cast<Figure*>(new Hexagon(points));
}

Hexagon::Hexagon(const Hexagon& other) {
    points = new Point[6];
    for (int i = 0; i < 6; ++i) {
        this->points[i] = other.points[i];
    }
}


Hexagon::Hexagon(Hexagon&& other) {
    points = other.points;
    delete[] other.points;
    other.points = nullptr;
}

Hexagon& Hexagon::operator=(Hexagon& other) {
    delete[] points;
    points = new Point[6];
    for (int i = 0; i < 6; ++i) {
        points[i] = other.points[i];
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) {
    points = other.points;
    delete[] other.points;
    other.points = nullptr;
    return *this;
}


bool Hexagon::operator==(Hexagon& other) {
    for (int i = 0; i < 6; ++i) {
        int flag = 0;
        for (int j = 0; j < 6; ++j) {
            if ((points[i].getX() == other.points[i].getX()) && (points[i].getY() == other.points[i].getY())) {
                flag = 1;
            }
        }
        if (flag == 0) {
            return false;
        }
    }
    return true;
}

Figure& Hexagon::operator=(const Figure&& other) {
    try {
        const Hexagon&& other_hexagon = dynamic_cast<const Hexagon&&>(other);
        return *this = other_hexagon;
    }
    catch (const std::bad_cast &e) {
        throw std::invalid_argument("expected Hexagon");
    }
}

Figure& Hexagon::operator=(const Figure& other) {
    try {
        const Hexagon& other_hexagon = dynamic_cast<const Hexagon&>(other);
        return *this = other_hexagon;
    }
    catch (const std::bad_cast &e) {
        throw std::invalid_argument("expected Hexagon");
    }
}

bool Hexagon::operator==(const Figure& other) {
    try {
        const Hexagon& other_hexagon = dynamic_cast<const Hexagon&>(other);
        return *this == other_hexagon;
    }
    catch (const std::bad_cast &e) {
        return false;
    }
}

Point Hexagon::center() const {
    double Xsum = 0;
    double Ysum = 0;
    for (int i = 0; i < 6; ++i) {
        Xsum += points[i].getX();
        Ysum += points[i].getY();
    }
    Point center;
    center.setX(Xsum / 6);
    center.setY(Ysum / 6);
    return center;
}

Hexagon::operator double() const {
    double s = 0;
    for (int i = 0; i < 6; i++) {
        s += points[i].getX() * points[(i + 1) % 6].getY() - points[i].getY() * points[(i + 1) % 6].getX();
    }
    return fabs(s / 2);
}

void Hexagon::fillPoints(const int pointsAmount, Point* res, const Point* data) {
    for (int i = 0; i < 6; ++i) {
        res[i] = data[i];
    }
}

std::ostream& Hexagon::print(std::ostream& os) const {
    for (int i = 0; i < 6; ++i) {
        os << points[i] << "\n";
    }
    os << std::endl;
    return os;
}

std::istream& Hexagon::read(std::istream& is) {
    for (int i = 0; i < 6; ++i) {
        is >> points[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Hexagon& figure) {
    return figure.print(std::cout);
}

std::istream& operator>>(std::istream& is, Hexagon& figure) {
    return figure.read(std::cin);
}
