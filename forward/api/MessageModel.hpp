#pragma once

#include <QtCore/QObject>
#include <QtQml/qqmlregistration.h>

#include <QtGui/QIcon>

class MessageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString recipient READ recipient WRITE setRecipient NOTIFY recipientChanged)

private:
    QIcon avatar_;
    int id_;
    QString recipient_;

public:
    explicit MessageModel(QObject *parent = nullptr);

    QString recipient() const;
    void setRecipient(QString const& recipient);

signals:
    void recipientChanged();

};