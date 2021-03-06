#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //----Plot----
    void addPoint(double x, double y);
    void clearData();
    void plot();
    //------------

private slots:
    void on_pushButton_agregar_clicked();

    void on_pushButtonlimpiar_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x, qv_y;
};

#endif // MAINWINDOW_H
