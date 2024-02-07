#include "funkcje.h"
#include <QMessageBox>

Funkcje::Funkcje() {};


void Funkcje::setMaxX(double XMax){m_maxX=XMax;}

void Funkcje::setMaxY(double YMax){m_maxY=YMax;}

void Funkcje::setMinX(double XMin){m_minX=XMin;}

void Funkcje::setMinY(double YMin){m_minY=YMin;}

void Funkcje::setA(double a){m_A=a;}
void Funkcje::setB(double b){m_B=b;}
void Funkcje::setC(double c){m_C=c;}
void Funkcje::setD(double d){m_D=d;}
void Funkcje::setF(double f){m_f=f;}
void Funkcje::setFi(double fi){m_fi=fi;}
void Funkcje::setRozdzielczosc(int rozdzielczosc){m_rozdzielczosc=rozdzielczosc;}


QVector<double> Funkcje::getX()
{return x;}

QVector<double> Funkcje::getY()
{return y;}


void Funkcje::liniowa(){

    double Xlength = m_maxX - m_minX;
    int points = Xlength * m_rozdzielczosc;
    x.resize(points);
    y.resize(points);
    for (int i = 0; i < points; ++i)
    {
        x[i] = Xlength * static_cast<double>(i) / (points - 1) + m_minX;
        y[i] = m_A * x[i] + m_B;
    }
}

void Funkcje::sinusoidalna(){
    double Xlength=m_maxX-m_minX;
    int points=Xlength*m_rozdzielczosc;
    x.resize(points);
    y.resize(points);
    for (int i=0; i<points; ++i)
    {
        x[i] = Xlength * static_cast<double>(i) / (points - 1) + m_minX;
        y[i] = m_A*sin(2.0*m_f*m_PI*x[i]+m_fi)+m_B;
    }
}

void Funkcje::logarytmiczna(){
    if(m_B==1 || m_B<=0.0)
    {
        QMessageBox msg;
        msg.setText("Z własności logartymów wartość B musi być większe od 0 i różne od 1");
        msg.exec();
        msg.deleteLater();
    }
    else{
        double Xlength=m_maxX;
        int points=Xlength*m_rozdzielczosc;
        x.resize(points);
        y.resize(points);
        for (int i=0; i<points; ++i)
        {
            x[i] = Xlength * static_cast<double>(i) / (points - 1);
            y[i] = m_A * (log(x[i]) / log(m_B)) + m_C;
        }
    }
}

void Funkcje::pierwiastkowa(){
    double Xlength=m_maxX-m_minX;
    int points=Xlength*m_rozdzielczosc;
    x.resize(points);
    y.resize(points);
    for (int i=0; i<points; ++i)
    {
        x[i] = Xlength * static_cast<double>(i) / (points - 1) + m_minX;
        y[i] = m_A*sqrt(x[i])+m_B;
    }
}
