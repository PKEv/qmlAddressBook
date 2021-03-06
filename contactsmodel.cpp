#include "contactsmodel.h"
#include <QQmlEngine>
#include <QDebug>

ContactsModel::ContactsModel()
{
    const bool updateResult {updateContacts()};
    if (!updateResult) {
        qWarning() << "update contacts faild";
    }
}

void ContactsModel::registerMe(const std::string &modulName)
{
    qmlRegisterType<ContactsModel>(modulName.c_str(), 1, 0, "ContactsModel");

}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int,QByteArray> roles;

    roles[ContactRoles::NameRole] = "name";
    roles[ContactRoles::SurnameRole] = "surname";
    roles[ContactRoles::PhoneNumberRole] = "phone";

    return roles;
}

int ContactsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_contacts.size());
}

QVariant ContactsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index))
    {
        return {};
    }
    const Contact &contact {m_contacts.at(index.row())};

    switch (role)
    {
    case ContactRoles::NameRole: {
        return QVariant::fromValue(contact.firstName());
    }
    case ContactRoles::SurnameRole: {
        return QVariant::fromValue(contact.surname());
    }
    case ContactRoles::PhoneNumberRole: {
        return QVariant::fromValue(contact.phone());
    }
    default: {
        return {};
    }
    }

}

bool ContactsModel::updateContacts()
{
    bool requestResult{false};
    std::vector<Contact> constactsResult;
    std::tie(requestResult, constactsResult) = m_contactsReader.requestContactsBrowse();

    if (requestResult) {
        m_contacts.swap(constactsResult);
        emit dataChanged(createIndex(0,0),createIndex(m_contacts.size(),0));
    }
}
