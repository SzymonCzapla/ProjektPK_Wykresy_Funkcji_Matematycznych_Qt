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
    MainWindow::liniowa();
    MainWindow::rysuj_wykres();
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
    maxX=ui->maxX->value();
    minY=ui->minY->value();
    maxY=ui->maxY->value();
    typ_funkcji=ui->typ_funkcji->currentText();
}

void MainWindow::liniowa(){

    double Xlength = maxX - minX;
    int points = Xlength * rozdzielczosc;
    x.resize(points);
    y.resize(points);
    for (int i = 0; i < points; ++i)
    {
        x[i] = Xlength * static_cast<double>(i) / (points - 1) + minX;
        y[i] = A * x[i] + B;
    }
}

void MainWindow::sinusoidalna(){
    double Xlength=maxX-minX;
    int points=Xlength*rozdzielczosc;
    x.resize(points);
    y.resize(points);
    for (int i=0; i<points; ++i)
    {
        x[i] = Xlength * static_cast<double>(i) / (points - 1) + minX;
        y[i] = A*sin(2.0*f*M_PI*x[i]+fi)+B;
    }
}

void MainWindow::logarytmiczna(){
    if(B==1)
    {
        QMessageBox::information(this,"B","Z własności logartymów wartość B musi być różne od 1");
    }
    double Xlength=maxX;
    int points=Xlength*rozdzielczosc;
    x.resize(points);
    y.resize(points);
    for (int i=0; i<points; ++i)
    {
        x[i] = Xlength * static_cast<double>(i) / (points - 1);
        y[i] = A * (log(x[i]) / log(B)) + C;
    }
}

void MainWindow::pierwiastkowa(){
    double Xlength=maxX-minX;
    int points=Xlength*rozdzielczosc;
    x.resize(points);
    y.resize(points);
    for (int i=0; i<points; ++i)
    {
        x[i] = Xlength * static_cast<double>(i) / (points - 1) + minX;
        y[i] = A*sqrt(x[i])+B;
    }
}

void MainWindow::rysuj_wykres(){
    ui->graph->addGraph();
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
    if(typ_funkcji=="liniowa"){
        MainWindow::liniowa();
    }
    else if(typ_funkcji=="sinusoidalna"){
        MainWindow::sinusoidalna();
    }
    else if(typ_funkcji=="logarytmiczna"){
        MainWindow::logarytmiczna();
    }
    else if(typ_funkcji=="pierwiastkowa"){
        MainWindow::pierwiastkowa();
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
    if(typ_funkcji=="liniowa"){
        ui->C->hide();
        ui->D->hide();
        ui->f->hide();
        ui->fi->hide();
        ui->c_label->hide();
        ui->d_label->hide();
        ui->fi_label->hide();
        ui->f_label->hide();

    }
    else if(typ_funkcji=="sinusoidalna"){
        ui->f->show();
        ui->fi->show();
        ui->fi_label->show();
        ui->f_label->show();
    }
    else if(typ_funkcji=="logarytmiczna"){
        ui->f->hide();
        ui->fi->hide();
        ui->fi_label->hide();
        ui->f_label->hide();
        ui->C->show();
        ui->c_label->show();
    }
    else if(typ_funkcji=="pierwiastkowa"){
        ui->B->hide();
        ui->b_label->hide();
        ui->C->hide();
        ui->c_label->hide();
        ui->D->show();
        ui->d_label->show();
    }
}


