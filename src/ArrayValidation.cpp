#include "Point.h"
#include "ArrayValidation.h"

template<typename T> bool validateArray(const  std::shared_ptr<Point<T>> points1,const  std::shared_ptr<Point<T>> points2, const int size){
    for (int i = 0; i < size; ++i){
        if (points1.get()[i] != points2.get()[i]){
            return false;
        }
    }
    return true;

}

// bool validateFiguresInArray(const FigureList list, const std::vector<std::string> expectedFigures){
//     if (list.getSize() != expectedFigures.size()){
//         return false;
//     }
//     for (int i = 0; i < list.getSize(); ++i){
//         if (list[i]->getFigureName() != expectedFigures[i]){
//             return false;
//         }
//     }
//     return true;
// }