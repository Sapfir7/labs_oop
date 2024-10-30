#pragma once
#include "Point.h"
#include "FigureList.h"
#include <vector>
bool validateArray(const Point* points1,const Point* points2, const int size);
bool validateFiguresInArray(const FigureList list, const std::vector<std::string> expectedFigures);