/*!
 * \file users.cpp
 * \brief file for the definition of the class "Users"
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
#include "users.h"

Users::Users(QObject * parent)
    : QObject(parent)
    , m_usersModel(new OLM_Person(this))
    , m_usersProxyModel(new OLPM_Person(m_usersModel, this))
{}

void Users::registerClass()
{
    qmlRegisterType<Users>("App", 1, 0, "Users");
    Person::registerClass();
}

bool Users::addUser(const QString & firstName,
                    const QString & lastName,
                    const QDate &   birthDay,
                    const QString & login,
                    const QString & country)
{
    if (isLoginUnique(login)) {
        QSharedPointer<Person> user(new Person);
        user->setFirstName(firstName);
        user->setLastName(lastName);
        user->setBirthDay(birthDay);
        user->setLogin(login);
        user->setCountry(country);
        m_usersModel->append(user);
        return true;
    }
    return false;
}

bool Users::editUser(int             index,
                     const QString & firstName,
                     const QString & lastName,
                     const QDate &   birthDay,
                     const QString & login,
                     const QString & country)
{
    if (index >= 0 && index < m_usersProxyModel->rowCount()) {
        QModelIndex modelIndex = m_usersProxyModel->mapToSource(m_usersProxyModel->index(index, 0));
        auto user = m_usersModel->getAt(index);
        if (user && isLoginUnique(login, user->login())) {
            user->setFirstName(firstName);
            user->setLastName(lastName);
            user->setBirthDay(birthDay);
            user->setLogin(login);
            user->setCountry(country);
            // m_usersModel->emitChanged();
            return true;
        }
    }
    return false;
}

void Users::setSortField(const QString & field, Qt::SortOrder order)
{
    m_usersProxyModel->setSortField(field, order);
}
