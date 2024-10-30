#include "Pentagon.h"
#include "Point.h"
#include "ValidationCompositor.h"


Pentagon::Pentagon(){
    points = new Point[5];
    figureName = "Pentagon";
}

// std::string Pentagon::getFigureName() const{
//     return figu
// }

Pentagon::Pentagon(const Point* points){
    this->points = new Point[5];
    figureName = "Pentagon";
    for (int i = 0; i < 5; ++i){
        this->points[i] = points[i];
    }
    ValidationCompositor validator;
    validator.validate(dynamic_cast<Figure&>(*this));
    // fillPoints(5, this->points, points);

}

Figure* Pentagon::create(const Point* points){
    return dynamic_cast<Figure*>(new Pentagon(points));
}

Pentagon::Pentagon(const Pentagon& other){
    points = new Point[5];
    for (int i = 0; i < 5; ++i){
        this->points[i] = other.points[i];
    }
    //fillPoints(5,points, other.points);
}

Pentagon::Pentagon(Pentagon&& other){
    points = other.points;
    delete[] other.points;
    other.points = nullptr;

}

Pentagon& Pentagon::operator=(Pentagon& other){
    delete[] points;
    points = new Point[5];
    for (int i = 0; i < 5; ++i){
        points[i] = other.points[i];
    }
    // fillPoints(5,points,other.points);
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other){
    points = other.points;
    delete[] other.points;
    other.points=nullptr;
    return *this;
}

bool Pentagon::operator==(Pentagon& other){
    for (int i = 0; i < 5; ++i){
        int flag = 0;
        for (int j =0; j < 5; ++j){
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

Figure& Pentagon::operator=(const Figure&& other){
    try{
        const Pentagon&& other_pentagon = dynamic_cast<const Pentagon&&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Trap");

    }
    
}
Figure& Pentagon::operator=(const Figure& other){
    try{
        const Pentagon& other_pentagon = dynamic_cast<const Pentagon&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Trap");

    }
}

bool Pentagon::operator==(const Figure& other){
    try{
        const Pentagon& other_pentagon = dynamic_cast<const Pentagon&>(other);
        return *this== other_pentagon;
    }
    catch(const std::bad_cast &e){
        return false;
    }
}

Point Pentagon::center()const{
    double Xsum = 0;
    double Ysum = 0;
    for(int i = 0; i < 5; ++i){
        Xsum += points[i].getX();
        Ysum += points[i].getY();
    }
    Point center;
    center.setX(Xsum / 5); 
    center.setY(Ysum / 5);

    return center;

}

Pentagon::operator double() const{
    double s = 0;
    for (int i = 0; i < 5; i++) {
        s += points[i].getX() * points[(i + 1) % 5].getY() - points[i].getY() * points[(i + 1) % 5].getX();
    }
    return fabs(s / 2);
}


void Pentagon::fillPoints(const int pointsAmount,Point* res,const Point* data){
     for (int i = 0; pointsAmount < 5; ++ i){
        res[i] = data[i];
    }
}


std::ostream& Pentagon::print(std::ostream& os) const{
    for (int i = 0; i < 5; ++i){
        os << points[i] << "\n";
    }
    os << std::endl;
    return os;
    
}
std::istream& Pentagon::read(std::istream& is){
    for (int i = 0; i < 5; ++i){
        is >> points[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Pentagon& figure){
    return figure.print(std::cout);
}

std::istream& operator>>(std::istream& is, Pentagon& figure){
    return figure.read(std::cin);
}