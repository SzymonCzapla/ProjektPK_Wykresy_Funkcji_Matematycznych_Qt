#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <QString>
#include <QVector>

class Funkcje
{
private:
    double m_A=1, m_B=1, m_C=1, m_D=1, m_fi=1, m_f=1, m_minX=-10, m_maxX=10, m_minY=-10, m_maxY=10;
    const double m_PI=3.1415;
    QVector<double> x, y;
    int m_rozdzielczosc=10;

public:
    Funkcje();
    QVector<double> getX();
    QVector<double> getY();

    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setD(double d);
    void setF(double f);
    void setFi(double fi);
    void setRozdzielczosc(int rozdzielczosc);
    void setMaxX(double XMax);
    void setMaxY(double YMax);
    void setMinX(double XMin);
    void setMinY(double YMin);

    void liniowa();
    void sinusoidalna();
    void logarytmiczna();
    void pierwiastkowa();
};

#endif // FUNKCJE_H

