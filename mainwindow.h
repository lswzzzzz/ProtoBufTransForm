#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sourcelistwidget.h"
#include "ProtoBufDetailWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpenFile_triggered();

private:
    Ui::MainWindow *ui;
    SourceListWidget* listWidget;
    ProtoBufDetailWidget* detailWidget;
};

#endif // MAINWINDOW_H
