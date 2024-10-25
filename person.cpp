/*!
 * \file person.cpp
 * \brief file for the definition of the class "Person"
 * \author francis CHAPET
 * \date 2024-10-25
 *
 * \details
 *
 * \copyright
 ****************************************************************************
 *
 ****************************************************************************
 */
#include "person.h"

Person::Person(QObject * parent)
    : QObject{parent}
{}

IMPLEMENTE_QML_REGISTER_CLASS_OLPM_TYPES("App", 1, 0, Person);

void Person::setFirstName(const QString & firstName)
{
    if (m_firstName != firstName) {
        m_firstName = firstName;
        emit firstNameChanged();
    }
}

void Person::setLastName(const QString & lastName)
{
    if (m_lastName != lastName) {
        m_lastName = lastName;
        emit lastNameChanged();
    }
}

void Person::setBirthDay(const QDate & birthDay)
{
    if (m_birthDay != birthDay) {
        m_birthDay = birthDay;
        emit birthDayChanged();
        emit ageChanged();
    }
}

int Person::age() const
{
    return m_birthDay.isValid() ? m_birthDay.daysTo(QDate::currentDate()) / 365 : 0;
}

void Person::setLogin(const QString & login)
{
    if (m_login != login) {
        m_login = login;
        emit loginChanged();
    }
}

void Person::setCountry(const QString & country)
{
    if (m_country != country) {
        m_country = country;
        emit countryChanged();
    }
}
