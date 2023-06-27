#include "forward/api/MessageItemModel.hpp"


MessageItemModel::MessageItemModel(QObject *parent)
    : QObject(parent)
{

}

int MessageItemModel::ID() const
{
    return id_;
}
void MessageItemModel::SetID(int id)
{
    id_ = id;
}

QIcon MessageItemModel::Avatar() const
{
    return avatar_;
}
void MessageItemModel::SetAvatar(QIcon const& avatar)
{
    avatar_ = avatar;
}

QString MessageItemModel::Recipient() const 
{
    return recipient_;
}
void MessageItemModel::SetRecipient(QString const& recipient) 
{
    recipient_ = recipient;
}

QDateTime MessageItemModel::Time() const
{
    return datetime_;
}
void MessageItemModel::SetTime(QDateTime const& time)
{
    datetime_ = time;
}

