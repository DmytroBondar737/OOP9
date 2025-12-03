#pragma once
#include <iostream>
using namespace std;

// Абстрактний клас Геометрична фігура
class GeometricFigure {
protected:
    double centerX, centerY;  // координати центра
    double angle;             // кут повороту в градусах
    double scale;             // масштабний фактор
    bool visible;             // чи видима фігура

public:
    GeometricFigure(double x = 0, double y = 0, double a = 0, double s = 1.0);
    virtual void show() const = 0;          // показати фігуру
    virtual void hide() const = 0;          // зробити невидимою
    virtual void rotate(double degrees) = 0; // повернути на кут
    virtual void move(double dx, double dy) = 0; // пересунути на вектор
    virtual ~GeometricFigure() {}

    // Допоміжні методи
    void setVisible(bool v);
    bool isVisible() const;
};

// Похідний клас Пряма
class Line : public GeometricFigure {
private:
    double length;  // довжина прямої

public:
    Line(double x = 0, double y = 0, double len = 10, double a = 0);
    void show() const override;
    void hide() const override;
    void rotate(double degrees) override;
    void move(double dx, double dy) override;

    double getLength() const;
    void setLength(double len);
};
