#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

QFile file("out.txt");
QTextStream out(&file);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //-----Plot----
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->plot->xAxis->setRange(-31.748,-31.749);
    ui->plot->yAxis->setRange(-60.522,-60.524);
    //-------------

    //----TXT-----
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    else
        qDebug() << "txt creado con éxito";
    while(!file.atEnd()){
        QByteArray linea = file.read(11);
        linea.chop(1);
        ui->labelfile->setText(linea.data());
        ui->spinBox_x->setValue(linea.toFloat());
        linea = file.read(11);
        linea.chop(1);
        ui->labelfile2->setText(linea.data());
        ui->spinBox_y->setValue(linea.toFloat());
        on_pushButton_agregar_clicked();
    }
    file.close();
    //------------
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void MainWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();
}

void MainWindow::plot()
{
    ui->plot->graph(0)->setData(qv_x, qv_y);
    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::on_pushButton_agregar_clicked()
{
    addPoint(ui->spinBox_x->value(), ui->spinBox_y->value());
    plot();
}

void MainWindow::on_pushButtonlimpiar_clicked()
{
    clearData();
    plot();
}
