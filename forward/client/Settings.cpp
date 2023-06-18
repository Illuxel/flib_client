#include "forward/client/Settings.hpp"

#include <QtWidgets/QApplication>

SettingsWraper::SettingsWraper(QObject* parent ) 
    : QObject(parent)
{
    auto org = QApplication::organizationName();
    auto app = QApplication::applicationName();

    settings_ = new QSettings(org, app);
}
SettingsWraper::~SettingsWraper() 
{
    delete settings_;
}

void SettingsWraper::save() const  
{
    settings_->sync();
}

void SettingsWraper::addValue(QString  const& key, QVariant const& value) 
{
    settings_->setValue(key, value);
}

QVariant SettingsWraper::valueAt(QString const& key) const 
{
    return settings_->value(key);
}
QVariant SettingsWraper::valueAt(QString const& key, QVariant const& default_value) const
{
    return settings_->value(key, default_value);
}

bool SettingsWraper::isValueAt(QString const& key) const
{
    return settings_->contains(key);
}
