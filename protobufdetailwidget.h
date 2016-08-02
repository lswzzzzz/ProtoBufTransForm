#ifndef PROTOBUFDETAILWIDGET_H
#define PROTOBUFDETAILWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>

class ProtoBufDetailWidget : public QWidget
{
    Q_OBJECT
public:
    ProtoBufDetailWidget();
    void __connect();
    void __setLayout();

private slots:
    void SelectOutputDir();
    void OutputButtonClicked();

private:
    QPushButton* selectOutput;
    QLabel* OutputDir;
    QPushButton* outputButton;
    QGridLayout* layout;
};

#endif // PROTOBUFDETAILWIDGET_H
