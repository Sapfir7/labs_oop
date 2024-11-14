#pragma once
#include "Figure.h"
#include "NumberConcept.h"

template<Number T> class Pentagon : public Figure<T>{
    template <Number U> friend std::ostream& operator<<(std::ostream& os, const Pentagon<U>& figure);
    template<Number U> friend std::istream& operator>>(std::istream& is, Pentagon<U>& figure);
    public:
        Pentagon();
        Pentagon(const std::shared_ptr<Point<T>> points);
        Pentagon(const Pentagon<T>& other);
        Pentagon(Pentagon<T>&& other);

        virtual ~Pentagon() = default;

        // std::string getFigureName() const;
        // Point* getPoints() const;
        static Pentagon<T> create(const std::shared_ptr<Point<T>> points);
        
        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point<T> center() const override;
        
        Pentagon<T>& operator=(Pentagon<T>& other);
        Pentagon<T>& operator=(Pentagon<T>&& other);
        bool operator==(Pentagon<T>& other);

        virtual Figure<T>& operator=(const Figure<T>&& other) override;
        virtual Figure<T>& operator=(const Figure<T>& other) override;
        virtual bool operator==(const Figure<T>& other) override;

    private:
        // std::string figureName = "Pentagon";
        void fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data) override;
};
template<Number T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T>& figure);
template<Number T>
std::istream& operator>>(std::istream& is, Pentagon<T>& figure);