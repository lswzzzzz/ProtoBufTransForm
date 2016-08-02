#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <qplaintextedit.h>
#include <QtCore\qobject.h>
#include <QListWidget>

extern QPlainTextEdit* logText;
extern QListWidget* g_listWidget;
extern QWidget* g_DetailWidget;
extern QString g_saveDir;

void addConsoleInfo(char* fmt, ...);

#endif // GLOBAL_H
