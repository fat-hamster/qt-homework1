#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculateButton_clicked()
{
    calculateFirstTask();
}

bool MainWindow::toNumber(QString str, int *value)
{
    bool ok;
    *value = str.toInt(&ok, 10);
    return ok;
}

void MainWindow::calculateFirstTask()
{
    int a, b, c;
    int des;
    double x1, x2;

    if(!toNumber(ui->lineEditA->text(), &a)) {
        ui->resultLineEdit->setText("a is not number!");
        ui->lineEditA->clear();
        return;
    }
    if(!toNumber(ui->lineEditB->text(), &b)) {
        ui->resultLineEdit->setText("b is not number!");
        ui->lineEditB->clear();
        return;
    }
    if(!toNumber(ui->lineEditC->text(), &c)) {
        ui->resultLineEdit->setText("c is not number!");
        ui->lineEditC->clear();
        return;
    }
    if(a == 0) {
        x1 = (-1 * c) / b;
        ui->resultLineEdit->setText("x=" + QString::number(x1) + " (this is a linear equation)");
        return;
    }
    des = b*b - 4*a*c;
    if(des < 0) {
        ui->resultLineEdit->setText("There is no solution");
        return;
    }
    x1 = (-b + qSqrt(des)) / (2 * a);
    if(des == 0) {
        ui->resultLineEdit->setText(QString::number(x1));
        return;
    }
    x2 = (-b - qSqrt(des)) / (2 * a);
    ui->resultLineEdit->setText("x1=" + QString::number(x1) +
                                ", x2=" + QString::number(x2));
}

void MainWindow::on_pushButton_clicked()
{
    calculateSecondTask();
}

void MainWindow::calculateSecondTask()
{
    int sideA, sideB;
    double angle;
    bool ok;

    if(!toNumber(ui->lineEditSideA->text(), &sideA)) {
        ui->lineEditSideA->clear();
        ui->lineEditResult->setText("Side A is not number!");
        return;
    }
    if(!toNumber(ui->lineEditSideB->text(), &sideB)) {
        ui->lineEditSideB->clear();
        ui->lineEditResult->setText("Side B is not number!");
        return;
    }
    angle = ui->lineEditAngle->text().toDouble(&ok);
    if(!ok) {
        ui->lineEditAngle->clear();
        ui->lineEditResult->setText("Angle is not number!");
        return;
    }
    if(ui->radioButtonRadians->isChecked()) {
        angle = (angle * 180) / M_PI;
    }
    int result = (int)qSqrt(sideA*sideA + sideB*sideB - 2*sideA*sideB * qCos(angle));
    ui->lineEditResult->setText(QString::number(result));
}

void MainWindow::on_pushButton_2_clicked()
{
    // copy
    ui->plainTextDest->insertPlainText(ui->plainTextSource->toPlainText());
}


void MainWindow::on_pushButton_3_clicked()
{
    // replace
    ui->plainTextDest->document()->clear();
    on_pushButton_2_clicked();
}


void MainWindow::on_pushButton_4_clicked()
{
    //push html
    ui->textEdit->setHtml("<font color='red'>Hello</font>");
}

