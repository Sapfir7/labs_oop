#include "Pentagon.h"
#include "Point.h"
#include "ValidationCompositor.h"
#include <memory>
#include "NumberConcept.h"

template<Number T> Pentagon<T>::Pentagon(){
    this->points =std::shared_ptr<Point<T>>(new Point<T>[5]);
    this->figureName = "Pentagon";
}

// std::string Pentagon::getFigureName() const{
//     return figu
// }

template<Number T> Pentagon<T>::Pentagon(const std::shared_ptr<Point<T>> points){
    this->points =std::shared_ptr<Point<T>>(new Point<T>[5]);
    this->figureName = "Pentagon";
    for (int i = 0; i < 5; ++i){
        this->points.get()[i] = points.get()[i];
    }
    ValidationCompositor<T> validator;
    validator.validate(dynamic_cast<Figure<T>&>(*this));
    

}

template<Number T> Pentagon<T> Pentagon<T>::create(const std::shared_ptr<Point<T>> points){
    return Pentagon<T>{points};
}

template<Number T> Pentagon<T>::Pentagon(const Pentagon<T>& other){
   this->points =std::shared_ptr<Point<T>>(new Point<T>[5]);
    for (int i = 0; i < 5; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    //fillPoints(5,points, other.points);
}

template<Number T> Pentagon<T>::Pentagon(Pentagon<T>&& other){
    this->points = other.points;
    // delete[] other.points;
    // other.points = nullptr;

}

template<Number T> Pentagon<T>& Pentagon<T>::operator=(Pentagon<T>& other){
    //delete[] points;
   this->points =std::shared_ptr<Point<T>>(new Point<T>[5]);
    for (int i = 0; i < 5; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    // fillPoints(5,points,other.points);
    return *this;
}

template<Number T> Pentagon<T>& Pentagon<T>::operator=(Pentagon<T>&& other){
    this->points = other.points;
    // delete[] other.points;
    // other.points=nullptr;
    return *this;
}

template<Number T> bool Pentagon<T>::operator==(Pentagon<T>& other){
    for (int i = 0; i < 5; ++i){
        int flag = 0;
        for (int j =0; j < 5; ++j){
            if ((this->points.get()[i].getX() == other.points.get()[i].getX()) && (this->points.get()[i].getY() == other.points.get()[i].getY())){
                flag = 1;
            }
        }
        if (flag == 0){
            return false;
        }
    }
    return true;
}

template<Number T> Figure<T>& Pentagon<T>::operator=(const Figure<T>&& other){
    try{
        const Pentagon<T>&& other_pentagon = dynamic_cast<const Pentagon<T>&&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Pentagon");

    }
    
}
template<Number T> Figure<T>& Pentagon<T>::operator=(const Figure<T>& other){
    try{
        const Pentagon<T>& other_pentagon = dynamic_cast<const Pentagon<T>&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Pentagon");

    }
}

template<Number T> bool Pentagon<T>::operator==(const Figure<T>& other){
    try{
        const Pentagon<T>& other_pentagon = dynamic_cast<const Pentagon<T>&>(other);
        return *this== other_pentagon;
    }
    catch(const std::bad_cast &e){
        return false;
    }
}

template<Number T> Point<T> Pentagon<T>::center()const{
    T Xsum = 0;
    T Ysum = 0;
    for(int i = 0; i < 5; ++i){
        Xsum += this->points.get()[i].getX();
        Ysum += this->points.get()[i].getY();
    }
    Point<T> center;
    center.setX(Xsum / 5); 
    center.setY(Ysum / 5);

    return center;

}

template<Number T> Pentagon<T>::operator double() const{
    double s = 0;
    for (int i = 0; i < 5; i++) {
        s += this->points.get()[i].getX() * this->points.get()[(i + 1) % 5].getY() - this->points.get()[i].getY() * this->points.get()[(i + 1) % 5].getX();
    }
    return fabs(s / 2);
}


template<Number T>void Pentagon<T>::fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data){
     for (int i = 0; i < 5; ++ i){
        res[i] = data[i];
    }
}


template<Number T> std::ostream& Pentagon<T>::print(std::ostream& os) const{
    for (int i = 0; i < 5; ++i){
        os << this->points.get()[i] << "\n";
    }
    return os;
    
}
template<Number T> std::istream& Pentagon<T>::read(std::istream& is){
    for (int i = 0; i < 5; ++i){
        is >> this->points.get()[i];
    }
    return is;
}

template<Number T> std::ostream& operator<<(std::ostream& os, const Pentagon<T>& figure){
    return figure.print(std::cout);
}

template<Number T> std::istream& operator>>(std::istream& is, Pentagon<T>& figure){
    return figure.read(std::cin);
}