/*!
 * \file person.h
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
#ifndef PERSON_H
#define PERSON_H

#include <QDate>
#include <QObject>
#include <QString>

#include "qobject_list_model.h"

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString  firstName   READ firstName  WRITE setFirstName  NOTIFY firstNameChanged)
    Q_PROPERTY(QString  lastName    READ lastName   WRITE setLastName   NOTIFY lastNameChanged)
    Q_PROPERTY(QDate    birthDay    READ birthDay   WRITE setBirthDay   NOTIFY birthDayChanged)
    Q_PROPERTY(QString  login       READ login      WRITE setLogin      NOTIFY loginChanged)
    Q_PROPERTY(QString  country     READ country    WRITE setCountry    NOTIFY countryChanged)
    Q_PROPERTY(int      age         READ age                            NOTIFY ageChanged)

public:
    explicit    Person          (QObject * parent = nullptr);

    DECLARE_QML_REGISTER_CLASS();

    QString     firstName       () const { return m_firstName; }
    QString     lastName        () const { return m_lastName; }
    QDate       birthDay        () const { return m_birthDay; }
    QString     login           () const { return m_login; }
    QString     country         () const { return m_country; int a = Qt::UserRole; }

    int         age             () const;

    void        setFirstName    (const QString &firstName);
    void        setLastName     (const QString &lastName);
    void        setBirthDay     (const QDate &birthDay);
    void        setLogin        (const QString &login);
    void        setCountry      (const QString &country);

    DECLARE_ROLE_DEFINITIONS_VARGS({"firstName" , Qt::UserRole + 1,  0, QObject::tr("First Name")},
                                   {"lastName"  , Qt::UserRole + 2,  1, QObject::tr("Last Name" )},
                                   {"age"       , Qt::UserRole + 3,  2, QObject::tr("Age"       )},
                                   {"login"     , Qt::UserRole + 4, -1, QObject::tr("Login"     )},
                                   {"birthday"  , Qt::UserRole + 5, -1, QObject::tr("Birthday"  )},
                                   {"country"   , Qt::UserRole + 6, -1, QObject::tr("Country"   )})

signals:
    void        firstNameChanged();
    void        lastNameChanged ();
    void        birthDayChanged ();
    void        ageChanged      ();
    void        loginChanged    ();
    void        countryChanged  ();

private:
    QString m_firstName;
    QString m_lastName;
    QDate   m_birthDay;
    QString m_login;
    QString m_country;
};

DECLARE_Q_OBJECT_LIST_PROXY_MODEL(Person)

#endif // PERSON_H
