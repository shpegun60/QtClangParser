#include "classinfoprovider.h"

ClassInfoProvider::ClassInfoProvider(QObject *parent) : QObject(parent) {
    m_classInfo["MyClass1"] = QStringList() << "variable1" << "variable2" << "function1()" << "function2()";
    m_classInfo["MyClass2"] = QStringList() << "variableA" << "variableB" << "functionA()" << "functionB()";
}

QStringList ClassInfoProvider::classes() const
{
    return m_classInfo.keys();
}

QStringList ClassInfoProvider::getClassMembers(const QString &className) const
{
    return m_classInfo.value(className);
}
