#include "contactsmodel.h"

ContactsModel::ContactsModel()
{

}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int,QByteArray> roles;

    roles[ContactRoles::NameRole] = "name";
    roles[ContactRoles::SurnameRole] = "surname";
    roles[ContactRoles::PhoneNamberRole] = "phone";

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
    case ContactRoles::PhoneNamberRole: {
        return QVariant::fromValue(contact.phone());
    }
    default: {
        return {};
    }
    }

}
