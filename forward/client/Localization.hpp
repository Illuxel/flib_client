#pragma once

#include <QtCore/QObject>
#include <QtQml/qqmlregistration.h>

#include <QTranslator>

class Localization : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT

private: 
    static QTranslator* translator_;

public:
    Q_INVOKABLE QStringList localeList() const;
    Q_INVOKABLE QStringList countryList() const;

    Q_INVOKABLE QString currentLocale() const;

    Q_INVOKABLE void changeLocale(QString const& language);

    QString getLanguageCode(QString const& displayName) const;
};