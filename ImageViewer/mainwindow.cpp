#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Press F1 for info. Open image with F3 Quit with Escape key.");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_an_image_triggered()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png, *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString choice = QFileDialog::getOpenFileName(this,tr("Open an image"), "/home", tr("Jpg or Png (*.jpg *.png)"));
    QImage image(choice);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->statusBar->showMessage(choice);
}


void MainWindow::keyPressEvent(QKeyEvent *events){

    if(events->key()==Qt::Key_F1){

        messagebox=new QMessageBox(this);
        messagebox->about(this,
                                "Just an imageviewer",

                                "\n"

                                "Author: JJ Posti <techtimejourney.net>"

                                "\n"
                                "\n"

                               "This is free software, and you are welcome to redistribute it under" "\n"
                               "GPL Version 2, June 1991. This program comes with ABSOLUTELY NO WARRANTY.");

                               //Delete messagebox from the heap.
                               delete messagebox;
                               //Return our standard message to the statusbar.
                                ui->statusBar->showMessage("Press F1 for info. Open image with F3 Quit with Escape key.");


          }

 //Open image
   else if(events->key()==Qt::Key_F3){
        on_actionOpen_an_image_triggered();
        ui->statusBar->showMessage("Press F1 for info. Open image with F3 Quit with Escape key.");

    }

//Esc event == Quit the program
    else if(events->key()==Qt::Key_Escape){
        this->close();
    }
};



void MainWindow::on_actionExit_triggered()
{
    this->close();
}
