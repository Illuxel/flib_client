#include "forward/api/MessageModel.hpp"


MessageModel::MessageModel(QObject *parent)
    : QObject(parent)
{

}

QString MessageModel::recipient() const 
{
    return recipient_;
}

void MessageModel::setRecipient(QString const& recipient) 
{
    recipient_ = recipient;
}