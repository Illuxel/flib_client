#pragma once

#include <QtCore/QObject>
#include <QtQml/qqmlregistration.h>

class Localisation : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT

public:
    Q_INVOKABLE static QStringList localeList();
    Q_INVOKABLE static QStringList countryList();

    Q_INVOKABLE static void changeLocale(const QString& locale);
};