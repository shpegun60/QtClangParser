#ifndef CLASSINFOPROVIDER_H
#define CLASSINFOPROVIDER_H

#include <QObject>
#include <QStringList>
#include <QMap>
#include <qqml.h>

class ClassInfoProvider : public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList my_classes READ classes NOTIFY classesChanged)
    QML_ELEMENT

public:
    explicit ClassInfoProvider(QObject *parent = nullptr);

public:
    QStringList classes() const;
    Q_INVOKABLE QStringList getClassMembers(const QString &className) const;

signals:
    void classesChanged();
    void membersChanged();

private:
    QMap<QString, QStringList> m_classInfo;
};

#endif // CLASSINFOPROVIDER_H
