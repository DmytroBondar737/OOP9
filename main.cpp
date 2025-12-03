#include "figure.h"
#include <Windows.h>

    int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        cout << "Лабораторна робота №9: Віртуальні функції" << endl;
        cout << "Варіант 3: Клас 'Пряма' похідний від 'Геометрична фігура'" << endl;
        cout << "========================================================\n" << endl;

        // Створення об'єкта прямої
        Line line(100, 100, 50, 45);

        // Демонстрація роботи методів
        cout << "1. Показ фігури:" << endl;
        line.show();

        cout << "\n2. Поворот фігури:" << endl;
        line.rotate(30);
        line.show();

        cout << "\n3. Переміщення фігури:" << endl;
        line.move(20, -10);
        line.show();

        cout << "\n4. Приховування фігури:" << endl;
        line.hide();

        cout << "\n5. Демонстрація поліморфізму:" << endl;
        GeometricFigure* figure = &line;
        figure->show();
        figure->rotate(-15);
        figure->move(5, 5);
        figure->hide();

        cout << "\n6. Зміна довжини (специфічний метод класу Line):" << endl;
        line.setLength(75);
        cout << "Нова довжина: " << line.getLength() << endl;
        line.show();

        return 0;
    }
