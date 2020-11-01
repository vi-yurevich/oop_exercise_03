/*
 * Юревич В.Ю. М8О-207Б-19
 * Вариант 13
 * Разработать классы согласно варианту задания,
 * классы должны наследоваться от базового класса Figure.
 * Фигуры являются фигурами вращения.
 * Все классы должны поддерживать набор общих методов:
 * - Вычисление геометрического центра фигуры
 * - Вывод в стандартный поток std::cout координат вершин фигуры
 * - Вычисление площади фигуры
 * Создать программу, которая позволяет:
 * - Вводить в стандартный поток std::cin фигуры
 * - Сохранять заданные фигуры в вектор std::vector<Figure*>
 * - Вызывать для всего массива общие функции
 * - Необходимо уметь вычислять общую площадь фигур в массиве.
 * - Удалять из массива фигуру по индексу
 * Ромб, пятиугольник, шестиугольник.
 */

#include "Figure.h"
#include <vector>
#include <string>
#include <limits>
#include <cmath>

void EnterFigure(std::vector<TFigure*>& f, int type) {
    double x0;
    double y0;
    double side;
    double diagVert;
    double diagHor;
    bool key = false;
    do {
        std::cout << "Укажите координату Х центра фигуры: ";
        std::cin >> x0;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else { 
            key = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while(key != true);
    do {
        std::cout << "Укажите координату У центра фигуры: ";
        std::cin >> y0;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else {
            key = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while(key != false);
    switch(type) {
        case 2: {
            do {
                std::cout << "Укажите длинну вертикальной диагонали: ";
                std::cin >> diagVert;
                if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
                }
                else {
                    key = true;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while(key != true);
            do {
                std::cout << "Укажите длинну горизонтальной диагонали: ";
                std::cin >> diagHor;
                if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
                }
                else {
                    key = false;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while(key != false);
            TFigure* rhombus = new TRhombus(x0, y0, diagVert, diagHor);
            f.push_back(rhombus); 
            break;
        }
        case 3: {
            do {
                std::cout << "Укажите длинну стороны: ";
                std::cin >> side;
                if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
                }
                else if (side != fabs(side)) {
                    std::cout << "Ошибка ввода. Сторона не может быть отрицательной. Повторите ввод.\n";
                }
                else {
                    key = true;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while(key != true);
            TFigure* pentagone = new TPentagone(x0, y0, side);
            f.push_back(pentagone);
            break;
        }
        case 4: {
            do {
                std::cout << "Укажите длинну стороны: ";
                std::cin >> side;
                if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
                }
                else if (side != fabs(side)) {
                    std::cout << "Ошибка ввода. Сторона не может быть отрицательной. Повторите ввод.\n";
                }
                else {
                    key = true;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while(key != true);
            TFigure* hexagone = new THexagone(x0, y0, side);
            f.push_back(hexagone);
            break;
        }
    }
}

int main() {
    bool key = false;
    int menu = 1;
    int i;
    double arrayArea;
    std::vector<TFigure*> f;
    
    while(menu != 0) {
        switch(menu) {
            case 1:
            std::cout << "1 - Вывод меню\n2 - Добавить ромб\n3 - Добавить пятиугольник\n";
            std::cout << "4 - Добавить шестиугольник\n5 - Удалить элемент по индексу\n";
            std::cout << "6 - Вывести весь массив фигур\n7 - Посчитать общую площадь фигур в массиве\n";
            std::cout << "0 - Выход из программы\n";
            break;
            case 2:
            EnterFigure(f, 2);
            break;
            case 3:
            EnterFigure(f, 3);
            break;
            case 4:
            EnterFigure(f, 4);
            break;
            case 5:
            if (f.empty() == true) {
                std::cout << "Сначала нужно ввести хотя бы одну фигуру\n";
                break;
            }
            
            do {
                std::cout << "Укажите индекс: ";
                std::cin >> i;
                if (std::cin.fail()) {
                std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
                }
                else if ((i < 0) || (i > (f.size() - 1))) {
                    std::cout << "Ошибка. Элемент с указанным индексом отсутсвует в массиве. Повторите ввод.\n";
                }
                else {
                    key = true;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while(key != true);
            key = false;
            f.erase(f.begin() + i);
            break;
            case 6:
            if (f.empty() == true) {
                std::cout << "Сначала нужно ввести хотя бы одну фигуру\n";
                break;
            }
            for (int j = 0; j < f.size(); ++j) {
                std::cout << "[" << j << "] ";
                std::cout << "Тип: " << f[j]->Name() << std::endl;
                std::cout << "Координаты точек: " << f[j]->Coordinate() << std::endl;
                std::cout << "Координаты центра: " << f[j]->Center() << std::endl;
                std::cout << "Площадь: " << f[j]->Area() << std::endl;
            }
            break;
            case 7:
            if (f.empty() == true) {
                std::cout << "Сначала нужно ввести хотя бы одну фигуру\n";
                break;
            }
            arrayArea = 0.0;
            for (int j = 0; j < f.size(); ++j) {
                arrayArea += f[j]->Area();
            }
            std::cout << "Площадь фигур в массиве: " << arrayArea << std::endl;
            break;
            case 0:
            break;
        }
        do {
            std::cout << "Выберете пункт меню: ";
            std::cin >> menu;
            if (std::cin.fail()) { //контроль вводимых данных
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
            }
            else if ((menu < 0) || (menu > 7)) {
                std::cout << "Указанный пункт отсутсвует в меню. Попробуйте ещё раз." << std::endl;
            }
            else {
                key = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while(key != true);
        key = false;
    }

    for(int j = 0; j < f.size(); ++j) {
        delete f[j];
    }

    return(0);
}