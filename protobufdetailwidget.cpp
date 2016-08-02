#include "protobufdetailwidget.h"
#include <QFileDialog>
#include <sourcelistwidget.h>
#include <global.h>
#include <QProcess>
#include <QFile>

ProtoBufDetailWidget::ProtoBufDetailWidget()
{
    __setLayout();
    __connect();
}

void ProtoBufDetailWidget::__connect()
{
    connect(selectOutput, SIGNAL(clicked()), this, SLOT(SelectOutputDir()));
    connect(outputButton, SIGNAL(clicked()), this, SLOT(OutputButtonClicked()));
}

void ProtoBufDetailWidget::__setLayout()
{
    selectOutput = new QPushButton("导出目录:");
    outputButton = new QPushButton("导出");
    OutputDir = new QLabel("");
    layout = new QGridLayout();
    layout->addWidget(selectOutput, 0, 0, 1, 1);
    layout->addWidget(OutputDir, 0, 1, 1, 10);
    layout->addWidget(outputButton, 1, 0, 1, 1);
    layout->addWidget(new QLabel(), 2, 0, 100, 11);
    setLayout(layout);
}

void ProtoBufDetailWidget::SelectOutputDir()
{
    QString dir = QFileDialog::getExistingDirectory(this, "选择保存文件夹");
    OutputDir->setText(dir);
}

void ProtoBufDetailWidget::OutputButtonClicked()
{
    auto listWidget = dynamic_cast<SourceListWidget*>(g_listWidget);
    QStringList list = listWidget->getList();
    for(int i=0; i<list.size(); i++){
        auto str = list.at(i);
        QProcess p(0);
        QString command = "protoc.exe --proto_path=" + str.section("/", 0, -2) + " --java_out=" + OutputDir->text()
                + " " + str;
        p.start(command);
        p.waitForStarted();
        p.waitForFinished();
    }
    for(int i=0; i<list.size(); i++){
        auto str = list.at(i);
        QString oname = OutputDir->text() + "/";
        if(str.contains(".")){
            oname += str.section("/", -1).section(".", 0, -2);
        }else{
            oname += str.section("/", -1);
        }
        oname += ".cs";
        QString copyFile = QDir::currentPath() + "/" + str.section("/", -1);
        QFile::copy(str, copyFile);
        QProcess p(0);
        QString command = "protogen.exe -i:" + copyFile + " -o:" + oname;
        p.start(command);
        p.waitForStarted();
        p.waitForFinished();
        if(str != copyFile)
            QFile::remove(copyFile);
    }
    addConsoleInfo("导出成功!");
}
