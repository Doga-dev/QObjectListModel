/*!
 * \file users.h
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
#ifndef USERS_H
#define USERS_H

#include <QObject>

#include "qobject_list_model.h"
#include "person.h"

class Users : public QObject {
    Q_OBJECT
    Q_PROPERTY(OLPM_Person* usersModel READ usersModel CONSTANT)

public:
    explicit Users(QObject *parent = nullptr);

    OLPM_Person* usersModel() const { return m_usersProxyModel; }

    static void         registerClass   ();

    Q_INVOKABLE bool addUser(const QString & firstName,
                             const QString & lastName,
                             const QDate &   birthDay,
                             const QString & login,
                             const QString & country);

    Q_INVOKABLE bool editUser(int             index,
                              const QString & firstName,
                              const QString & lastName,
                              const QDate &   birthDay,
                              const QString & login,
                              const QString & country);

    Q_INVOKABLE void removeUser(int index) {
        if (index >= 0 && index < m_usersModel->rowCount()) {
            m_usersModel->removeAt(index);
        }
    }

public slots:
    void setSortField(const QString& field, Qt::SortOrder order = Qt::AscendingOrder);

private:
    bool isLoginUnique(const QString &login, const QString &currentLogin = QString()) const {
        for (int i = 0; i < m_usersModel->rowCount(); ++i) {
            auto user = m_usersModel->getAt(i);
            if (user && user->login() == login && user->login() != currentLogin) {
                return false;
            }
        }
        return true;
    }

    OLM_Person *  m_usersModel;
    OLPM_Person * m_usersProxyModel;
};

#endif // USERS_H
