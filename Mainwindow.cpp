#include "Mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //主窗口标题
    setWindowTitle("Markdown & Mind");

    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::NewDocument);
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::OpenDocument);
    connect(ui->actionSave,&QAction::triggered,this,&MainWindow::SaveDocument);
    connect(ui->actionExit,&QAction::triggered,this,&MainWindow::Exit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NewDocument()
{

}

void MainWindow::OpenDocument()
{

}

void MainWindow::SaveDocument()
{

}

void MainWindow::Exit()
{
    QCoreApplication::quit();
}
