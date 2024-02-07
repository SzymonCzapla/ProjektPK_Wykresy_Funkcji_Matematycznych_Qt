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

private:
    QString typ_funkcji;
    Ui::MainWindow *ui;
    Funkcje funkcja;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getTypFunkcji();

private slots:
    void on_rysujwykres_clicked();
    void on_typ_funkcji_currentTextChanged(const QString &typ_funkcji);
    void rysuj_wykres();
    void getdane();
    void jaka_funkcja();

};
#endif // MAINWINDOW_H
