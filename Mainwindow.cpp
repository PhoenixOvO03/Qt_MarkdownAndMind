#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //主窗口标题
    setWindowTitle("Markdown & Mind");

    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::NewDocument);//new
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::OpenDocument);//open
    connect(ui->actionSave,&QAction::triggered,this,&MainWindow::SaveDocument);//save
    connect(ui->actionExit,&QAction::triggered,this,&MainWindow::Exit);//exit
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NewDocument()//new a file
{
    m_FileName.clear();//clear open_file_name
    ui->textEdit->setText(QString(""));//clear textEdit
    setWindowTitle("Markdown & Mind");//set title default
}

void MainWindow::OpenDocument()//open a file
{
    QString fileName_open = QFileDialog::getOpenFileName(this,"Open file","C:");//get open_file_name
    QFile file(fileName_open);//create a file to open

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){//if can not open file
        QMessageBox::warning(this,"Warning","Can not open file:"+file.errorString());//warning
        return;
    }
    m_FileName = fileName_open;//set m_open_file_name
    setWindowTitle(m_FileName);//set title is open_file_name

    QTextStream in(&file);//open file to string stream
    QString text = in.readAll();//get all text from file
    ui->textEdit->setText(text);//set text from file
    file.close();
}

void MainWindow::SaveDocument()//save or build a file
{
    QString fileName_save;//save_file_name
    if(m_FileName.isEmpty()){//not open file
        fileName_save = QFileDialog::getSaveFileName(this,"Save","C:new.md");//get save_file_name
        m_FileName = fileName_save;//open the save_file
    }else{//is open
        fileName_save = m_FileName;//save_file is open_file
    }

    QFile file(fileName_save);//create a file to save
    if(!file.open(QIODevice::WriteOnly | QFile::Text)){//if can not open
        QMessageBox::warning(this,"Warning","Can not save file:"+file.errorString());//warning
        return;
    }

    setWindowTitle(fileName_save);//set title is open_file_name

    QTextStream out(&file);//open file to string stream
    QString text = ui->textEdit->toPlainText();//get text form textEdit
    out << text;//text go to stream to save_file
    file.close();
}

void MainWindow::Exit()//exit this software
{
    QCoreApplication::quit();
}
