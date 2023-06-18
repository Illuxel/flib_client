#pragma once

#include <QtCore/QObject>
#include <QtQml/qqmlregistration.h>

#include <QtCore/QSettings>

class SettingsWraper : public QObject
{
    Q_OBJECT
    QML_NAMED_ELEMENT(Settings)

private:
    QSettings* settings_;

public:
    explicit SettingsWraper(QObject* parent = nullptr);
    ~SettingsWraper() override;

    Q_INVOKABLE void save() const;

    Q_INVOKABLE void addValue(QString const& key, QVariant const& value);

    Q_INVOKABLE QVariant valueAt(QString const& key) const;
    Q_INVOKABLE QVariant valueAt(QString const& key, QVariant const& default_value) const;

    Q_INVOKABLE bool isValueAt(QString const& key) const;
};