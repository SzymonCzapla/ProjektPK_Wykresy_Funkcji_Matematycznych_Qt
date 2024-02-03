#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

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
    double A=1, B=1, C=1, D=1, fi=1, f=1, minX=-10, maxX=10, minY=-10, maxY=10;
    QVector<double> x, y;
    void jaka_funkcja();
    int rozdzielczosc=10;
    void getdane();
    void skala();
    void liniowa();
    void sinusoidalna();
    void logarytmiczna();
    void pierwiastkowa();
    void rysuj_wykres();

private slots:
    void on_rysujwykres_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
