#include "Mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //主窗口标题
    setWindowTitle("Markdown & Mind");
}

MainWindow::~MainWindow()
{
    delete ui;
}

