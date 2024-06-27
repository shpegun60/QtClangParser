#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ClassInfoProvider.h>
#include <QMainWindow>
#include <QQmlApplicationEngine>

#include <MyTreeModel.hpp>

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

private slots:
    void on_pushButton_clicked();

    void on_treeWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;

    QQmlApplicationEngine* engine;
    ClassInfoProvider* provider;
    TreeModels::MyTreeModel* mymodel;
};
#endif // MAINWINDOW_H
