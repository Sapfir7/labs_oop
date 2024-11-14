#include <iostream>
#include "Hexagon.h"
#include "Point.h"
#include "Figure.h"
#include "Romb.h"
#include "Pentagon.h"
#include "FigureList.h"
int main(){
    
    Point* TrapPoints = new Point[4];
    TrapPoints[0] = Point{0,0};
    TrapPoints[1] = Point{7,0};
    TrapPoints[2] = Point{2,3};
    TrapPoints[3] = Point{6,3};
    // std::cout << "hi" << "\n";
    
    // Trap trap{TrapPoints};
    // std::cout << "center: " << trap.center() << std::endl;
    // std::cout << "square " << (double) trap << std::endl;
    // std::cout << trap;
    // std::cout << "hi" << "\n";
    Point* Rombpoints = new Point[4];
    Rombpoints[0] = Point{0,0};
    Rombpoints[1] = Point{2,0};
    Rombpoints[2] = Point{2,2};
    Rombpoints[3] = Point{0,2};

    // Romb romb{Rombpoints};
    // std::cout << "center: " << romb.center() << std::endl;
    // std::cout << "square " << (double) romb << std::endl;
    // std::cout << romb;

    // std::cout << "hi" << "\n";
    Point* PentagonPoints = new Point[5];
    PentagonPoints[0] = Point{0,0};
    PentagonPoints[1] = Point{2,0};
    PentagonPoints[2] = Point{22,4};
    PentagonPoints[3] = Point{3,12};
    PentagonPoints[4] = Point{5,8};
    Pentagon pentagon{PentagonPoints};
    std::cout << "center: " << pentagon.center() << std::endl;
    std::cout << "square " << (double) pentagon << std::endl;
//     std::cout << pentagon;

    // FigureList list;
    // Figure* pentagon = Pentagon::create(PentagonPoints);
    // list.push_back(pentagon);
    // list.push_back(dynamic_cast<Figure*>(new Trap(TrapPoints)));
    // list.push_back(dynamic_cast<Figure*>(new Romb(Rombpoints)));
    // for (int i = 0; i < list.getSize(); ++i){
    //      std::cout << list[i]->center() << "\n";
    //     std::cout << list[i]->getFigureName() << "\n";
    // }
    // list.remove(1);
    //  for (int i = 0; i < list.getSize(); ++i){
    //     std::cout << list[i]->center() << "\n";
    //     std::cout << list[i]->getFigureName() << "\n";
    // }

    
    
}