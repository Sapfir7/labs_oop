#include "Romb.h"
#include "Point.h"
#include "ValidationCompositor.h"

Romb::Romb(){
    points = new Point[4];
    figureName = "Romb";
}

Romb::Romb(const Point* points){
    this->points = new Point[4];
    figureName = "Romb";
    for (int i =0; i < 4; ++i){
        this->points[i] = points[i];
    }

    ValidationCompositor validator;
    validator.validate(dynamic_cast<Figure &>(*this));
    // fillPoints(4, this->points, points);
}

Romb::Romb(const Romb& other){
    points = new Point[4];
    fillPoints(4, this->points, other.points);

}

Romb::Romb(Romb&& other){
    points = other.points;

    delete[] other.points;
    other.points = nullptr;
}

// std::string Romb::getFigureName() const{
//     return figureName;
// }

// Point* Romb::getPoints() const {
//     return points;
// }

Point Romb::center()const{
    double Xsum = 0;
    double Ysum = 0;
    for(int i = 0; i < 4; ++i){
        Xsum += points[i].getX();
        Ysum += points[i].getY();
    }
    Point center;
    center.setX(Xsum / 4); 
    center.setY(Ysum / 4);

    return center;

}

Romb::operator double() const{
    double s = 0;
    for (int i = 0; i < 4; i++) {
        s += points[i].getX() * points[(i + 1) % 4].getY() - points[i].getY() * points[(i + 1) % 4].getX();
    }
    return fabs(s / 2);
}

Romb& Romb::operator=(const Romb& other){
    delete[] points;
    
    points = new Point[4];
    for (int i = 0; i < 4; ++i){
        points[i] = other.points[i];
    }
    // fillPoints(4,points,other.points);
    return *this;
}

Romb& Romb::operator=(Romb&& other){
    points = other.points;

    delete[] other.points;
    other.points = nullptr;
    return *this;
}

bool Romb::operator==(Romb& other){
    for (int i = 0; i < 4; ++i){
        int flag = 0;
        for (int j = 0; j < 4; ++j){
            if ((points[i].getX() == other.points[i].getX()) && (points[i].getY() == other.points[i].getY())){
                flag = 1;
            }
        }
        if (flag == 0){
            return false;
        }
    }
    return true;
}




void Romb::fillPoints(const int pointsAmount,Point* res,const Point* data){
     for (int i = 0; pointsAmount < 4; ++ i){
        res[i] = data[i];
    }
}

std::ostream& Romb::print(std::ostream& os) const {
    for (int i = 0; i < 4; ++i){
        os << points[i] <<  "\n";
    }
    os << std::endl;
    return os;
}
std::istream& Romb::read(std::istream& is) {
    for (int i = 0; i < 4; ++i){
        is >> points[i];
    }
    return is;
    
}

std::ostream& operator<<(std::ostream& os, const Romb& figure){
    return figure.print(std::cout);
}
std::istream& operator>>(std::istream& is, Romb& figure){
    return figure.read(std::cin);
}

Figure& Romb::operator=(const Figure&& other){
    try{
        const Romb&& other_romb = dynamic_cast<const Romb&&>(other);
        return *this = other_romb;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Trap");

    }
    
}
Figure& Romb::operator=(const Figure& other){
    try{
        const Romb& other_romb = dynamic_cast<const Romb&>(other);
        return *this = other_romb;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Trap");

    }
}

bool Romb::operator==(const Figure& other){
    try{
        const Romb& other_romb = dynamic_cast<const Romb&>(other);
        return *this== other_romb;
    }
    catch(const std::bad_cast &e){
        return false;
    }
}
