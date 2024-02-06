#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QMessageBox>
#include "funkcje.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString typ_funkcji;
    void jaka_funkcja();
    int rozdzielczosc=10;
    void skala();
    void rysuj_wykres();
    void getdane();
    Liniowa *WykresLiniowa;
    Sinusoidalna *WykresSinusoidalna;
    Pierwiastkowa *WykresPierwiastkowa;
    Logarytmiczna *WykresLogarytmiczna;

private slots:
    void on_rysujwykres_clicked();
    void on_typ_funkcji_currentTextChanged(const QString &typ_funkcji);

private:
    Ui::MainWindow *ui;
    double A=0, B=0,C=0,D=0,f=0,fi=0;
    int minX=0,maxX=0,minY=0, maxY=0;
    QVector<double>x,y;
};
#endif // MAINWINDOW_H
