#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ClassInfoProvider.h>
#include <QMainWindow>
#include <QQmlApplicationEngine>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QQmlApplicationEngine* engine;
    ClassInfoProvider* provider;
};
#endif // MAINWINDOW_H
