#include "Point.h"
#include <iostream>
#include <math.h>
const double EPS = 1e-9;

Point::Point(const double x,const double y){
    this->x = x;
    this->y = y;
}

Point::Point(const Point& other){
    x = other.x;
    y = other.y;
}

Point::Point(Point&& other){
    x = other.x;
    y = other.y;

    other.x = 0;
    other.y = 0;

}
double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

void Point::setX(double x){
    this->x = x;
}

void Point::setY(double y){
    this->y = y;
}

Point Point::operator+(const Point& other){
    // x += other.x;
    // y += other.y;
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point& other){
    // x -= other.x;
    // y -= other.y;
    return Point(x - other.x, y - other.y);
}

bool Point::operator==(const Point& other)const {
    return (std::abs(x - other.x) < EPS) && (std::abs(y - other.y) < EPS);
}

Point& Point::operator=(const Point& other){
    x = other.x;
    y = other.y;
    return *this;
}

Point& Point::operator=(Point&& other){
    x = other.x;
    y = other.y;

    other.x = 0;
    other.y = 0;
    return *this;
}

void Point::print(){
    std::cout << "Point(x: " << x << ", y: " << y << ")" << std::endl;
}

double dot(const Point& p1, const Point& p2){
    return p1.getX() * p2.getX() + p1.getY() * p2.getY();
}
double abs(const Point& p1){
    return sqrt(p1.getX() * p1.getX() + p1.getY() * p1.getY())  ;
}
double cos(const Point& p1, const Point& p2){
    return dot(p1,p2) / (abs(p1) * abs(p2));
}

bool isParalel(const Point& p1, const Point& p2){
    if (fabs(fabs(cos(p1, p2)) -1) <= EPS){
        return true;
    }
    return false;
}


std::ostream& operator<<(std::ostream& os, const Point& p){
    os << p.x << " " << p.y;
    return os;
}

std::istream& operator>>(std::istream& is, Point& p){
    is >> p.x >> p.y;
    return is;
}