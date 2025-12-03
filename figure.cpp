#include "figure.h"
#include <cmath>

// Реалізація GeometricFigure
GeometricFigure::GeometricFigure(double x, double y, double a, double s)
    : centerX(x), centerY(y), angle(a), scale(s), visible(false) {
}

void GeometricFigure::setVisible(bool v) {
    visible = v;
}

bool GeometricFigure::isVisible() const {
    return visible;
}

// Реалізація Line
Line::Line(double x, double y, double len, double a)
    : GeometricFigure(x, y, a), length(len) {
}

void Line::show() const {
    if (!visible) {
        cout << "Показую пряму:" << endl;
        cout << "  Центр: (" << centerX << ", " << centerY << ")" << endl;
        cout << "  Довжина: " << length << endl;
        cout << "  Кут повороту: " << angle << "°" << endl;
        cout << "  Масштаб: " << scale << endl;
        const_cast<Line*>(this)->setVisible(true);
    }
}

void Line::hide() const {
    if (visible) {
        cout << "Ховаю пряму з центра (" << centerX << ", " << centerY << ")" << endl;
        const_cast<Line*>(this)->setVisible(false);
    }
}

void Line::rotate(double degrees) {
    angle += degrees;
    if (angle >= 360) angle -= 360;
    if (angle < 0) angle += 360;
    cout << "Повертаю пряму на " << degrees << "°. Новий кут: " << angle << "°" << endl;
}

void Line::move(double dx, double dy) {
    centerX += dx;
    centerY += dy;
    cout << "Переміщую пряму на вектор (" << dx << ", " << dy << ")" << endl;
    cout << "Новий центр: (" << centerX << ", " << centerY << ")" << endl;
}

double Line::getLength() const {
    return length;
}

void Line::setLength(double len) {
    length = len;
}
