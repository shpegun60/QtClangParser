#ifndef CLANGPARSER_H
#define CLANGPARSER_H

#include <clang-c/Index.h>
#include <QString>
#include <QVector>
#include <QMap>

class ClangParser {
public:
    ClangParser();
    ~ClangParser();
    void parseFile(const QString &filePath);


    enum AccessSpecifier {
        Public,
        Protected,
        Private,
        None
    };

    struct Variable {
        QString name;
        QString type;
        AccessSpecifier accessSpecifier = None;
    };

    struct Function {
        QString name;
        QString returnType;
        QVector<QString> parameters;
        AccessSpecifier accessSpecifier = None;
    };

    struct Class {
        QString name;
        bool isStruct;
        AccessSpecifier accessSpecifier = None;

        QVector<Variable> variables;
        QVector<Function> functions;
        QVector<Class*> classes;
    };

    const QMap<QString, Class>& getClasses() const;
    static QString accessSpecifierToString(ClangParser::AccessSpecifier accessSpecifier);

private:

    struct classLocal {
        ClangParser::Class cls;
        AccessSpecifier specifier_flag;
    };

    void parseAST(CXTranslationUnit translationUnit);

    QMap<QString, Class> classes;
};

#endif // CLANGPARSER_H
