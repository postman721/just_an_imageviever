#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QUrl>
#include <QStatusBar>
#include <QKeyEvent>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_an_image_triggered();

    void keyPressEvent(QKeyEvent *events);


    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QMessageBox *messagebox;
};

#endif // MAINWINDOW_H
