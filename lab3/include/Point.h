#pragma once
#include <iostream>
#include <math.h>
class Point{
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
    public:
        Point() = default;
        Point(const double x, const double y);
        Point(const Point& other);
        Point(Point&& other);
        ~Point() = default;
        double getX() const;
        double getY() const;
        void setX(double x);
        void setY(double y);
        Point operator+(const Point& other);
        Point operator-(const Point& other);
        bool operator==(const Point& other) const;
        Point& operator=(const Point& other);
        Point& operator=(Point&& other);
        void print();
        

    private:
        double x;
        double y;
};

std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);

double dot(const Point& p1, const Point& p2);
double abs(const Point& p1) ;
double cos(const Point& p1, const Point& p2);
bool isParalel(const Point& p1, const Point& p2);
Point intersection(const Point& p1, const Point& p2);