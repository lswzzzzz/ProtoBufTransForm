#include "sourcelistwidget.h"

SourceListWidget::SourceListWidget()
{
    connect(this, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));
}

SourceListWidget::~SourceListWidget()
{
}

void SourceListWidget::itemClicked(QListWidgetItem * item)
{
    QString name = item->data(Qt::UserRole).toString();
}

QStringList SourceListWidget::getList()
{
    QStringList strList;
    auto count = this->count();
    for(int i=0; i<count; i++){
        QString str = this->item(i)->data(Qt::UserRole).toString();
        strList.push_back(str);
    }
    return strList;
}
