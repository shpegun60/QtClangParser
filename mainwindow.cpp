#include "mainwindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"


#include <ClangParser.h>
#include <QGuiApplication>
#include <QQmlContext>
#include "classinfoprovider.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // ClangParser parser;
    // parser.parseFile("C:/Users/admin/Documents/Work/Qt/ClangParser/example.cpp");

    // const QMap<QString, ClangParser::Class>& classes = parser.getClasses();
    // for (auto it = classes.begin(); it != classes.end(); ++it) {
    //     qDebug() << "Class:" << it.key() << "is struct:" << it.value().isStruct;
    //     for (const auto &var : it.value().variables) {
    //         qDebug() << "  Variable:" << var.name << "Type:" << var.type << "Access:" << parser.accessSpecifierToString(var.accessSpecifier);
    //     }
    //     for (const auto &func : it.value().functions) {
    //         qDebug() << "  Function:" << func.name << "Return Type:" << func.returnType << "Parameters:" << func.parameters << "Access:" << parser.accessSpecifierToString(func.accessSpecifier);
    //     }
    // }



    provider = new ClassInfoProvider(this);

    // start qml ---------------------------------------------------------------------------
    engine = new QQmlApplicationEngine(this);
    engine->rootContext()->setContextProperty("provider", provider);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine->load(url);
    if (engine->rootObjects().isEmpty()) {
        qDebug() << "error --------------------------------------------:";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
