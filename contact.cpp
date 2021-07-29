#include "contact.h"

Contact::Contact(QString firstName, QString surname, QString phone)
    : m_firstName{std::move(firstName)},
      m_surname{std::move(surname)},
      m_phone{std::move(phone)}
{

}

QString Contact::surname() const
{
    return m_surname;
}

QString Contact::firstName() const
{
    return m_firstName;
}

QString Contact::phone() const
{
    return m_phone;
}
