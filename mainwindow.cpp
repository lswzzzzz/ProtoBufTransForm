#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "QFileDialog"
#include "QListWidget"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logText = ui->OutputView;
    listWidget = new SourceListWidget;
    ui->ListView->setWidget(listWidget);
    g_listWidget = listWidget;
    detailWidget = new ProtoBufDetailWidget();
    ui->DetailView->setWidget(detailWidget);
    listWidget->setStyleSheet("background-color: rgb(191, 191, 191);");
    g_DetailWidget = detailWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenFile_triggered()
{
    QStringList openFiles = QFileDialog::getOpenFileNames(this, "打开ProtoBuf文件", g_saveDir, tr(""));
    if (openFiles.size() > 0){
        g_saveDir = openFiles.at(0).section("/", 0, -2);
        QListWidget* listWidget = g_listWidget;
        for (int i = 0; i < openFiles.size(); i++){
            QString toFile = openFiles.at(i);
            auto item = new QListWidgetItem;
            item->setData(Qt::UserRole, toFile);
            if(toFile.contains(".")){
                item->setText(toFile.section("/", -1).section(".", 0, -2));
            }else{
                item->setText(toFile.section("/", -1));
            }
            listWidget->addItem(item);
        }
        addConsoleInfo("打开%d个文件", openFiles.size());
    }
}
