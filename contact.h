#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact() = default;

    Contact(QString firstName, QString surname, QString phone);

    QString firstName() const;
    QString surname() const;
    QString phone() const;

private:

    QString m_firstName;
    QString m_surname;
    QString m_phone;
};

#endif // CONTACT_H
