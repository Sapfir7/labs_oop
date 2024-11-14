#pragma once
#include "Figure.h"
#include "NumberConcept.h"

template<Number T> class Romb : public Figure<T>{
    template<Number U> friend std::ostream& operator<<(std::ostream& os, const Romb<U>& figure);
    template<Number U> friend std::istream& operator>>(std::istream& is, Romb<U>& figure);
    public:
        Romb();
        Romb(const std::shared_ptr<Point<T>> points);
        Romb(const Romb<T>& other);
        Romb(Romb<T>&& other);

        virtual ~Romb() = default;

        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point<T> center() const override;

        Romb<T>& operator =(const Romb<T>& other);
        Romb<T>& operator =(Romb<T>&& other);
        bool operator ==(Romb<T>& other);

        

        virtual Figure<T>& operator=(const Figure<T>&& other) override;
        virtual Figure<T>& operator=(const Figure<T>& other) override;
        virtual bool operator==(const Figure<T>& other) override;
    private:
        virtual void fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data) override;
};
template<Number T>
std::ostream& operator<<(std::ostream& os, const Romb<T>& figure);
template<Number T>
std::istream& operator>>(std::istream& is, Romb<T>& figure);