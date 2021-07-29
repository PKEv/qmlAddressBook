#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H

#include <QAbstractListModel>

#include "contact.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ContactsModel();

    static registerMe(std::string)

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    std::vector<Contact> m_contacts;

    enum ContactRoles {
        NameRole = Qt::UserRole + 1,
        SurnameRole,
        PhoneNamberRole
    };
};

#endif // CONTACTSMODEL_H
