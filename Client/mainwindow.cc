#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  client.connect();
}

void MainWindow::on_pushButton_2_clicked() {
  client.disconnect();
}

void MainWindow::on_pushButton_4_clicked() {
  client.transaction();
}

void MainWindow::on_pushButton_3_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                  "/Users/ivanmorozov",
                                                  tr("Txt file(*.json)"));

  ui->lineEdit->setText(fileName);
  client.send_file(fileName.toLatin1().data());
}
