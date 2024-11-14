#include "Romb.h"
#include "Point.h"
#include "ValidationCompositor.h"
#include "Figure.h"
#include "ValidationCompositor.cpp"
#include "NumberConcept.h"

template<Number T> Romb<T>::Romb(){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
    this->figureName = "Romb";
}

template<Number T> Romb<T>::Romb(const std::shared_ptr<Point<T>> points){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
    this->figureName = "Romb";
    for (int i =0; i < 4; ++i){
        this->points.get()[i] = points.get()[i];
    }

    ValidationCompositor<T> validator;
    validator.validate(dynamic_cast<Figure<T> &>(*this));
    // fillPoints(4, this->points, points);
}

template<Number T> Romb<T>::Romb(const Romb<T>& other){
     this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
    for (int i = 0; i < 4; ++i){
         this->points[i] = other.points[i];
    }
    //fillPoints(4, this->points, other.points);

}

template<Number T> Romb<T>::Romb(Romb<T>&& other){
     this->points = other.points;

    //delete[] other.points;
    //other.points = nullptr;
}

// std::string Romb::getFigureName() const{
//     return figureName;
// }

// Point* Romb::getPoints() const {
//     return points;
// }

template<Number T> Point<T> Romb<T>::center()const{
    T Xsum = 0;
    T Ysum = 0;
    for(int i = 0; i < 4; ++i){
        Xsum += this->points.get()[i].getX();
        Ysum += this->points.get()[i].getY();
    }
    Point<T> center;
    center.setX(Xsum / 4); 
    center.setY(Ysum / 4);

    return center;

}

template<Number T> Romb<T>::operator double() const{
    double s = 0;
    for (int i = 0; i < 4; i++) {
        s += this->points.get()[i].getX() * this->points.get()[(i + 1) % 4].getY() - this->points.get()[i].getY() * this->points.get()[(i + 1) % 4].getX();
    }
    return fabs(s / 2);
}

template<Number T> Romb<T>& Romb<T>::operator=(const Romb<T>& other){
   // delete[] points;
    
     this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
    for (int i = 0; i < 4; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    // fillPoints(4,points,other.points);
    return *this;
}

template<Number T> Romb<T>& Romb<T>::operator=(Romb<T>&& other){
     this->points = other.points;

    // delete[] other.points;
    // other.points = nullptr;
    return *this;
}

template<Number T> bool Romb<T>::operator==(Romb<T>& other){
    for (int i = 0; i < 4; ++i){
        int flag = 0;
        for (int j = 0; j < 4; ++j){
            if ((this->points[i].getX() == other.points[i].getX()) && (this->points[i].getY() == other.points[i].getY())){
                flag = 1;
            }
        }
        if (flag == 0){
            return false;
        }
    }
    return true;
}




template< Number T> void Romb<T>::fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data){
     for (int i = 0; i < 4; ++ i){
        res[i] = data[i];
    }
}

template <Number T> std::ostream& Romb<T>::print(std::ostream& os) const {
    for (int i = 0; i < 4; ++i){
        os << this->points.get()[i] <<  "\n";
    }
    return os;
}
template <Number T> std::istream& Romb<T>::read(std::istream& is) {
    for (int i = 0; i < 4; ++i){
        is >> this->points.get()[i];
    }
    return is;
    
}

template <Number T> std::ostream& operator<<(std::ostream& os, const Romb<T>& figure){
    return figure.print(std::cout);
}
template <Number T > std::istream& operator>>(std::istream& is, Romb<T>& figure){
    return figure.read(std::cin);
}

template<Number T> Figure<T>& Romb<T>::operator=(const Figure<T>&& other){
    try{
        const Romb<T>&& other_romb = dynamic_cast<const Romb<T>&&>(other);
        return *this = other_romb;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Romb");

    }
    
}
template<Number T> Figure<T>& Romb<T>::operator=(const Figure<T>& other){
    try{
        const Romb<T>& other_romb = dynamic_cast<const Romb<T>&>(other);
        return *this = other_romb;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Romb");

    }
}

template<Number T> bool Romb<T>::operator==(const Figure<T>& other){
    try{
        const Romb<T>& other_romb = dynamic_cast<const Romb<T>&>(other);
        return *this== other_romb;
    }
    catch(const std::bad_cast &e){
        return false;
    }
}
