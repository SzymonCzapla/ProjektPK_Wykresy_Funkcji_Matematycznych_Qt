#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <QVector>
#include <QMessageBox>

class Funkcje
{
private:
    double A=0, B=0,C=0,D=0,F=0, Fi=0;
    QVector<double>x,y;
    int minX=0,maxX=0,minY=0, maxY=0;
    int rozdzielczosc=0;
public:
    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setD(double d);
    void setF(double f);
    void setFi(double fi);
    void setMinX(int minX);
    void setMaxX(int maxX);
    void setMinY(int minY);
    void setMaxY(int maxY);
    void setRozdzielczosc(int rozdzielczosc);


    double getA();
    double getB();
    double getC();
    double getD();
    double getF();
    double getFi();
    int getMinX();
    int getMaxX();
    int getMinY();
    int getMaxY();
    int getRozdzielczosc();
    QVector<double>* getVectorX();
    QVector<double>* getVectorY();


};

class Liniowa : public Funkcje
{
public:

    void obliczFunkcjeLiniowa();
    Liniowa();
};

class Logarytmiczna : public Funkcje
{
public:
    void obliczFunkcjeLogarytmiczna();
    Logarytmiczna(double a,double b, double c);
};

class Sinusoidalna : public Funkcje
{
public:
    void obliczFunkcjeSinusoidalna();
    Sinusoidalna(double a, double b, double f, double fi);
};

class Pierwiastkowa : public Funkcje
{
private:

public:
    void obliczFunkcjePierwiastkowa();
    Pierwiastkowa(double a, double d);
};
#endif // FUNKCJE_H
