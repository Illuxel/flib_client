#pragma once

#include <QObject>
#include <qqmlregistration.h>

#include <QDateTime>
#include <QIcon>

class MessageItemModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int identity READ ID WRITE SetID)
    Q_PROPERTY(QIcon avatar READ Avatar WRITE SetAvatar)
    Q_PROPERTY(QString recipient READ Recipient WRITE SetRecipient)
    Q_PROPERTY(QDateTime datetime READ Time WRITE SetTime)

private:
    int id_;
    QIcon avatar_;
    QString recipient_;
    QDateTime datetime_;

public:
    explicit MessageItemModel(QObject *parent = nullptr);

    int ID() const;
    void SetID(int id);

    QIcon Avatar() const;
    void SetAvatar(QIcon const& avatar);

    QString Recipient() const;
    void SetRecipient(QString const& recipient);

    QDateTime Time() const;
    void SetTime(QDateTime const& time);
};
