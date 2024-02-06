#include "funkcje.h"

void Funkcje::setA(double a)
{ this->A = a;}

void Funkcje::setB(double b)
{this->B = b;}

void Funkcje::setMaxX(int ma_x)
{this->maxX=ma_x;}

void Funkcje::setMinX(int mi_x)
{this->minX=mi_x;}

void Funkcje::setMaxY(int ma_y)
{this->maxY=ma_y;}

void Funkcje::setMinY(int mi_y)
{this->minY=mi_y;}

void Funkcje::setRozdzielczosc(int Rozdzielczosc)
{this->rozdzielczosc=Rozdzielczosc;};

void Funkcje::setC(double c)
{this->C=c;}

void Funkcje::setD(double d)
{this->D=d;}

void Funkcje::setF(double f)
{this->F=f;}

void Funkcje::setFi(double fi)
{this->Fi=fi;};

double Funkcje::getA()
{ return this->A;}

double Funkcje::getF()
{return this->F;};

double Funkcje::getFi()
{return this->Fi;};

double Funkcje::getC()
{return this->C;}

double Funkcje::getD()
{return this->D;}

double Funkcje::getB()
{ return this->B;}

int Funkcje::getMaxX()
{qInfo()<<"getMaxX"<<maxX;
    return maxX;}

int Funkcje::getMinX()
{return this->minX;}

int Funkcje::getMaxY()
{return this->maxY;}

int Funkcje::getMinY()
{return this->minY;}

int Funkcje::getRozdzielczosc()
{return this->rozdzielczosc;};

QVector<double>* Funkcje::getVectorX()
{return &this->x;};

QVector<double>* Funkcje::getVectorY()
{return &this->y;};


void Liniowa::obliczFunkcjeLiniowa()
{
    double Xlength = getMaxX() - Funkcje::getMinX();
    /*int points = Xlength * Funkcje::getRozdzielczosc();
    QVector<double>* wektorX = Funkcje::getVectorX();
    QVector<double>* wektorY = Funkcje::getVectorY();
    wektorX->resize(points);
    wektorY->resize(points);
    for (int i = 0; i < points; ++i)
    {
        (*wektorX)[i] = Xlength * static_cast<double>(i) / (points - 1) + Funkcje::getMinX();
        (*wektorY)[i] = Funkcje::getA() * (*wektorX)[i] + Funkcje::getB();
    }*/
}

void Logarytmiczna::obliczFunkcjeLogarytmiczna()
{
        double Xlength=Funkcje::getMaxX();
        int points=Xlength*Funkcje::getRozdzielczosc();
        QVector<double>* wektorX = Funkcje::getVectorX();
        QVector<double>* wektorY = Funkcje::getVectorY();
        wektorX->resize(points);
        wektorY->resize(points);
        for (int i=0; i<points; ++i)
        {
            (*wektorX)[i] = Xlength *static_cast<double>(i) / (points - 1);
            (*wektorY)[i] = Funkcje::getA() * (log((*wektorX)[i]) / log(Funkcje::getB())) + Funkcje::getC();
        }

};

void Sinusoidalna::obliczFunkcjeSinusoidalna()
{
    double Xlength=Funkcje::getMaxX() - Funkcje::getMinX();
    int points=Xlength*Funkcje::getRozdzielczosc();
    QVector<double>* wektorX = Funkcje::getVectorX();
    QVector<double>* wektorY = Funkcje::getVectorY();
    wektorX->resize(points);
    wektorY->resize(points);
    for (int i=0; i<points; ++i)
    {
        (*wektorX)[i] = Xlength * static_cast<double>(i) / (points - 1) + Funkcje::getMinX();
        (*wektorY)[i] = Funkcje::getA()*sin(2.0*Funkcje::getF()*M_PI*(*wektorX)[i]+Funkcje::getFi())+Funkcje::getB();
    }

};

void Pierwiastkowa::obliczFunkcjePierwiastkowa()
{
    double Xlength=Funkcje::getMaxX() - Funkcje::getMinX();;
    int points=Xlength*Funkcje::getRozdzielczosc();
    QVector<double>* wektorX = Funkcje::getVectorX();
    QVector<double>* wektorY = Funkcje::getVectorY();
    wektorX->resize(points);
    wektorY->resize(points);
    for (int i=0; i<points; ++i)
    {
        (*wektorX)[i] = Xlength * static_cast<double>(i) / (points - 1) + Funkcje::getMinX();
        (*wektorY)[i] = Funkcje::getA()*sqrt((*wektorX)[i])+Funkcje::getB();
    }

};
