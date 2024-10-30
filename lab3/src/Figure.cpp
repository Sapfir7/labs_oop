#include "Figure.h"

Figure::Figure(std::string figureName){
    this->figureName = figureName;
}

Figure::~Figure(){
    figureName = "";
    delete[] points;
    points = nullptr;

}

Figure::Figure(){
    figureName = "";
    points = nullptr;
}

Point* Figure::getPoints() const{
    return points;
}

std::string Figure::getFigureName() const{
    return figureName;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure){
    return figure.print(os);
}
std::istream& operator>>(std::istream& is, Figure& figure){
    return figure.read(is);
}

