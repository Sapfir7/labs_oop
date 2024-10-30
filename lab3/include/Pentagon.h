#pragma once
#include "Figure.h"

class Pentagon : public Figure{
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& figure);
    friend std::istream& operator>>(std::istream& is, Pentagon& figure);
    public:
        Pentagon();
        Pentagon(const Point* points);
        Pentagon(const Pentagon& other);
        Pentagon(Pentagon&& other);

        virtual ~Pentagon() = default;

        // std::string getFigureName() const;
        // Point* getPoints() const;
        static Figure* create(const Point* points);
        
        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point center() const override;
        
        Pentagon& operator=(Pentagon& other);
        Pentagon& operator=(Pentagon&& other);
        bool operator==(Pentagon& other);

        virtual Figure& operator=(const Figure&& other) override;
        virtual Figure& operator=(const Figure& other) override;
        virtual bool operator==(const Figure& other) override;

    private:
        // std::string figureName = "Pentagon";
        void fillPoints(const int pointsAmount,Point* res,const Point* data) override;
};
std::ostream& operator<<(std::ostream& os, const Pentagon& figure);
std::istream& operator>>(std::istream& is, Pentagon& figure);