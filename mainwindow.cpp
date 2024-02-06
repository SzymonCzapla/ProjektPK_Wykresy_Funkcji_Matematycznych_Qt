#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->C->hide();
    ui->D->hide();
    ui->f->hide();
    ui->fi->hide();
    ui->c_label->hide();
    ui->d_label->hide();
    ui->fi_label->hide();
    ui->f_label->hide();

    ui->A->setSingleStep(0.1);
    ui->B->setSingleStep(0.1);
    ui->C->setSingleStep(0.1);
    ui->D->setSingleStep(0.1);
    ui->fi->setSingleStep(0.1);
    ui->f->setSingleStep(0.1);
    ui->rozdzielczosc->setSingleStep(10);
    ui->A->setMinimum(-1000);
    ui->B->setMinimum(-1000);
    ui->C->setMinimum(-1000);
    ui->D->setMinimum(-1000);
    ui->fi->setMinimum(-1000);
    ui->f->setMinimum(0.00000001);
    ui->minX->setMinimum(-1000);
    ui->maxX->setMinimum(-1000);
    ui->minY->setMinimum(-1000);
    ui->maxY->setMinimum(-1000);
    ui->rozdzielczosc->setMinimum(1);
    ui->A->setMaximum(1000);
    ui->B->setMaximum(1000);
    ui->C->setMaximum(1000);
    ui->D->setMaximum(1000);
    ui->fi->setMaximum(1000);
    ui->f->setMaximum(1000);
    ui->minX->setMaximum(1000);
    ui->maxX->setMaximum(1000);
    ui->minY->setMaximum(1000);
    ui->maxY->setMaximum(1000);
    ui->rozdzielczosc->setMaximum(1000);
    ui->A->setValue(1);
    ui->B->setValue(1);
    ui->C->setValue(1);
    ui->D->setValue(1);
    ui->fi->setValue(1);
    ui->f->setValue(1);
    ui->minX->setValue(-10);
    ui->maxX->setValue(10);
    ui->minY->setValue(-10);
    ui->maxY->setValue(10);
    ui->rozdzielczosc->setValue(10);
    qInfo()<<maxX;
    WykresLiniowa->obliczFunkcjeLiniowa();
    //MainWindow::rysuj_wykres();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getdane(){
    A=ui->A->value();
    B=ui->B->value();
    C=ui->C->value();
    D=ui->D->value();
    fi=ui->fi->value();
    f=ui->f->value();
    rozdzielczosc=ui->rozdzielczosc->value();
    minX=ui->minX->value();
    qInfo()<<"PrzedmaxX:"<<maxX;
    maxX=ui->maxX->value();
    qInfo()<<"POmaxX:"<<maxX;
    minY=ui->minY->value();
    maxY=ui->maxY->value();
    typ_funkcji=ui->typ_funkcji->currentText();
}


void MainWindow::rysuj_wykres(){
    ui->graph->graph(0)->setData(x, y);
    ui->graph->xAxis->setRange(minX, maxX);
    ui->graph->yAxis->setRange(minY, maxY);
    //wyglad wykresu
    ui->graph->setBackground(QBrush(QColor(56,56,56)));

    ui->graph->xAxis->setBasePen(QPen(QColor(255,255,255)));
    ui->graph->xAxis->setTickPen(QPen(QColor(255,255,255)));
    ui->graph->xAxis->setSubTickPen(QPen(QColor(255,255,255)));
    ui->graph->xAxis->setTickLabelColor(QColor(255,255,255));
    ui->graph->xAxis->setLabelColor(QColor(255,255,255));

    ui->graph->yAxis->setBasePen(QPen(QColor(255,255,255)));
    ui->graph->yAxis->setTickPen(QPen(QColor(255,255,255)));
    ui->graph->yAxis->setSubTickPen(QPen(QColor(255,255,255)));
    ui->graph->yAxis->setTickLabelColor(QColor(255,255,255));
    ui->graph->yAxis->setLabelColor(QColor(255,255,255));

    ui->graph->graph(0)->setPen(QPen(QColor(119,122,168),5));
    ui->graph->replot();
}

void MainWindow::jaka_funkcja(){
    MainWindow::getdane();
    if(typ_funkcji=="Liniowa"){
        WykresLiniowa->Liniowa::obliczFunkcjeLiniowa();
    }
    else if(typ_funkcji=="Sinusoidalna"){
        WykresSinusoidalna->Sinusoidalna::obliczFunkcjeSinusoidalna();
    }
    else if(typ_funkcji=="Logarytmiczna"){
        WykresLogarytmiczna->Logarytmiczna::obliczFunkcjeLogarytmiczna();
    }
    else if(typ_funkcji=="Pierwiastkowa"){
        WykresPierwiastkowa->Pierwiastkowa::obliczFunkcjePierwiastkowa();
    }
    MainWindow::rysuj_wykres();
    //qDebug()<<typ_funkcji; //jak chcesz cos sprawdzac czy dziala
}

void MainWindow::on_rysujwykres_clicked()
{
    MainWindow::jaka_funkcja();
}
void MainWindow::on_typ_funkcji_currentTextChanged(const QString &typ_funkcji)
{
    if(typ_funkcji=="Liniowa"){
        ui->A->show();
        ui->a_label->show();
        ui->B->show();
        ui->b_label->show();
        ui->C->hide();
        ui->c_label->hide();
        ui->D->hide();
        ui->d_label->hide();
        ui->f->hide();
        ui->f_label->hide();
        ui->fi->hide();
        ui->fi_label->hide();
    }
    else if(typ_funkcji=="Sinusoidalna"){
        ui->A->show();
        ui->a_label->show();
        ui->B->show();
        ui->b_label->show();
        ui->f->show();
        ui->f_label->show();
        ui->fi->show();
        ui->fi_label->show();
        ui->C->hide();
        ui->c_label->hide();
        ui->D->hide();
        ui->d_label->hide();
    }
    else if(typ_funkcji=="Logarytmiczna"){
        ui->A->show();
        ui->a_label->show();
        ui->B->show();
        ui->b_label->show();
        ui->C->show();
        ui->c_label->show();
        ui->D->hide();
        ui->d_label->hide();
        ui->f->hide();
        ui->f_label->hide();
        ui->fi->hide();
        ui->fi_label->hide();            
    }
    else if(typ_funkcji=="Pierwiastkowa"){
        ui->A->show();
        ui->a_label->show();
        ui->D->show();
        ui->d_label->show();
        ui->B->hide();
        ui->b_label->hide();
        ui->C->hide();
        ui->c_label->hide();
        ui->f->hide();
        ui->f_label->hide();
        ui->fi->hide();
        ui->fi_label->hide();
    }
}


