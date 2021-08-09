#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H

#include <QAbstractListModel>
#include <vector>

#include "contact.h"
#include "contactsreader.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ContactsModel();

    static void registerMe(const std::string& modulName);

    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    ContactsReader m_contactsReader;
    std::vector<Contact> m_contacts;

    enum ContactRoles {
        NameRole = Qt::UserRole + 1,
        SurnameRole,
        PhoneNumberRole
    };

    bool updateContacts();
};

#endif // CONTACTSMODEL_H
