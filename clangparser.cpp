#include "ClangParser.h"
#include "qdebug.h"
#include <iostream>

ClangParser::ClangParser() {
    // Initialization
}

ClangParser::~ClangParser() {
    // Cleanup
}

QString ClangParser::accessSpecifierToString(ClangParser::AccessSpecifier accessSpecifier) {
    switch (accessSpecifier) {
    case ClangParser::Public:
        return "public";
    case ClangParser::Protected:
        return "protected";
    case ClangParser::Private:
        return "private";
    case ClangParser::None:
        return "none";
    }
    return "unknown";
}

void ClangParser::parseFile(const QString &filePath)
{
    CXIndex index = clang_createIndex(0, 0);
    CXTranslationUnit translationUnit = clang_parseTranslationUnit(
        index, filePath.toStdString().c_str(), nullptr, 0, nullptr, 0, CXTranslationUnit_None);

    if (translationUnit == nullptr) {
        std::cerr << "Unable to parse translation unit." << std::endl;
        return;
    }

    parseAST(translationUnit);
    clang_disposeTranslationUnit(translationUnit);
    clang_disposeIndex(index);
}


void ClangParser::parseAST(CXTranslationUnit translationUnit)
{
    CXCursor cursor = clang_getTranslationUnitCursor(translationUnit);
    clang_visitChildren(cursor, [](CXCursor c, CXCursor parent, CXClientData clientData) {
            ClangParser* const parser = static_cast<ClangParser*>(clientData);
            const enum CXCursorKind cursorType = clang_getCursorKind(c);

            if (cursorType == CXCursor_ClassDecl || cursorType == CXCursor_StructDecl) {

                ClangParser::classLocal classLocaldata;

                const bool isStruct = (cursorType == CXCursor_StructDecl);
                classLocaldata.cls.name = QString::fromStdString(clang_getCString(clang_getCursorSpelling(c)));
                classLocaldata.cls.isStruct = isStruct;
                classLocaldata.specifier_flag = isStruct ? ClangParser::Public : ClangParser::Private;

                clang_visitChildren(c, [](CXCursor member, CXCursor parent, CXClientData clientData) {
                        ClangParser::classLocal* classLocaldata = static_cast<struct classLocal*>(clientData);

                        if (clang_getCursorKind(member) == CXCursor_CXXAccessSpecifier) {
                            CX_CXXAccessSpecifier accessSpec = clang_getCXXAccessSpecifier(member);

                            switch (accessSpec) {
                            case CX_CXXPublic:
                                classLocaldata->specifier_flag = ClangParser::Public;
                                break;
                            case CX_CXXProtected:
                                classLocaldata->specifier_flag = ClangParser::Protected;
                                break;
                            case CX_CXXPrivate:
                                classLocaldata->specifier_flag = ClangParser::Private;
                                break;
                            default:
                                classLocaldata->specifier_flag = ClangParser::None;
                                break;
                            }
                        }

                        if (clang_getCursorKind(member) == CXCursor_FieldDecl) {
                            ClangParser::Variable var;
                            var.name = QString::fromStdString(clang_getCString(clang_getCursorSpelling(member)));
                            var.type = QString::fromStdString(clang_getCString(clang_getTypeSpelling(clang_getCursorType(member))));
                            var.accessSpecifier = classLocaldata->specifier_flag;
                            classLocaldata->cls.variables.append(var);
                        }

                        if (clang_getCursorKind(member) == CXCursor_CXXMethod) {
                            ClangParser::Function func;
                            func.name = QString::fromStdString(clang_getCString(clang_getCursorSpelling(member)));
                            func.returnType = QString::fromStdString(clang_getCString(clang_getTypeSpelling(clang_getCursorResultType(member))));
                            func.accessSpecifier = classLocaldata->specifier_flag;

                            int numArgs = clang_Cursor_getNumArguments(member);
                            for (int i = 0; i < numArgs; ++i) {
                                CXCursor arg = clang_Cursor_getArgument(member, i);
                                QString argType = QString::fromStdString(clang_getCString(clang_getTypeSpelling(clang_getCursorType(arg))));
                                func.parameters.append(argType);
                            }
                            classLocaldata->cls.functions.append(func);
                        }
                        return CXChildVisit_Continue;
                    }, &classLocaldata);

                parser->classes.insert(classLocaldata.cls.name, classLocaldata.cls);
            }

            return CXChildVisit_Continue;
        }, this);
}

const QMap<QString, ClangParser::Class>& ClangParser::getClasses() const {
    return classes;
}
