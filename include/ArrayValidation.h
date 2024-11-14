#pragma once
#include "Point.h"
#include "FigureList.h"
#include <vector>
#include <memory>

template<typename T>
bool validateArray(const std::shared_ptr<Point<T>> points1,const  std::shared_ptr<Point<T>> points2, const int size);
// bool validateFiguresInArray(const FigureList list, const std::vector<std::string> expectedFigures);