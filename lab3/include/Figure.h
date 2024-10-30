#pragma once
#include <string>
#include "Point.h"

class Figure{
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    protected:
    Figure();
    Figure(std::string figureName);
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& is) = 0;

    public:
        virtual ~Figure();    
        virtual operator double() const = 0;
        virtual Point center() const = 0;
        virtual bool operator==(const Figure& other)=0;
        virtual Figure& operator=(const Figure&& other)=0;
        virtual Figure& operator=(const Figure& other)=0;
        virtual std::string getFigureName() const;
        virtual Point* getPoints() const ;
    protected:
        std::string figureName;
        Point* points;
        virtual void fillPoints(const int pointsAmount,Point* res,const Point* data) = 0;
    
};
std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);