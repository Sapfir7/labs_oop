#include "FigureList.h"
#include "Figure.h"

FigureList::FigureList(){
    size = 0;
    capacity = 10;
    figures = new Figure*[capacity];
}

FigureList::~FigureList(){
    size = 0;
    capacity = 0;
    for (int i = 0;i < size; ++i){
        delete figures[i];
    }
    delete[] figures;
    figures = nullptr;
}

void FigureList::push_back(Figure* figure){
    if (size + 2 > capacity){
        capacity *= 2;
        Figure** newFigures = new Figure*[capacity];
        for (int i = 0; i < size; ++i){
            newFigures[i] = figures[i];
        }
        for (int i = 0;i < size; ++i){
            delete figures[i];
        }
        delete[] figures;
        figures = newFigures;
    }

    figures[size++] = figure;

}

 Figure* FigureList::operator [](const int index) const{
    if (index >= size || index < 0){
        throw std::invalid_argument("Invalid index");
    }
    return figures[index];
 }

void FigureList::remove(int index){
    if (index >= size || index < 0){
        throw std::invalid_argument("Invalid index");
    }
    for (int i = index; i < size; ++i){
        // delete figures[i];
        figures[i] = figures[i+1];
    }
    size--;
}

int FigureList::getSize() const {
    return size;
}
