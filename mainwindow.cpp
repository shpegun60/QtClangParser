#include "mainwindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"

#include <QQmlContext>


#include <ClangParser.h>
#include <QGuiApplication>
#include "ClassInfoProvider.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ClangParser parser;
    parser.parseFile("C:/Users/admin/Documents/Work/Qt/ClangParser/example.cpp");

    const QMap<QString, ClangParser::Class>& classes = parser.getClasses();
    for (auto it = classes.begin(); it != classes.end(); ++it) {
        qDebug() << "Class:" << it.key() << "is struct:" << it.value().isStruct;
        for (const auto &var : it.value().variables) {
            qDebug() << "  Variable:" << var.name << "Type:" << var.type << "Access:" << parser.accessSpecifierToString(var.accessSpecifier);
        }
        for (const auto &func : it.value().functions) {
            qDebug() << "  Function:" << func.name << "Return Type:" << func.returnType << "Parameters:" << func.parameters << "Access:" << parser.accessSpecifierToString(func.accessSpecifier);
        }
    }

    // start qml ---------------------------------------------------------------------------
    mymodel = new TreeModels::MyTreeModel(this);
    mymodel->BuildTree(classes);

    //provider = new ClassInfoProvider;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QQmlContext* const ctx = ui->quickWidget->engine()->rootContext();

    //ctx->setContextProperty("provider", provider);
    ctx->setContextProperty("mymodel", mymodel);
    ui->quickWidget->setSource(url);

    // engine = new QQmlApplicationEngine(this);
    // engine->rootContext()->setContextProperty("provider", provider);
    // const QUrl url(QStringLiteral("qrc:/main.qml"));
    // engine->load(url);
    // if (engine->rootObjects().isEmpty()) {
    //     qDebug() << "error --------------------------------------------:";
    // }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // ui->treeWidget->currentItem()->setBackground(0, Qt::red);
    // ui->treeWidget->currentItem()->setBackground(1, Qt::blue);
}


void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    on_pushButton_clicked();
}

