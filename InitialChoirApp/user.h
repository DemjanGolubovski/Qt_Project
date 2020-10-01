#ifndef USER_H
#define USER_H

#include <QString>
#include "microphone.h"

class User
{
public:
    User();

    QString getUser_role() const;
    void setUser_role(const QString &value);

    QString getIp_address_login() const;
    void setIp_address_login(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getSection() const;
    void setSection(const QString &value);

    QString getIp_address_choir_room() const;
    void setIp_address_choir_room(const QString &value);

    Microphone *getUser_microphone_object() const;
    void setUser_microphone_object(Microphone *value);

private:
    QString user_role; // it can be either 'member' or 'leader'
    QString ip_address_login; // if the user is choir 'leader' then this does not apply to him and it will be an empty string
    QString name; // the name of the user
    QString section; // this does not apply for choir 'leader' and it will be an empty string. As for 'members' it can be {Sopranos, Altos, Tenors, Basses}
    QString ip_address_choir_room; // the ip address when entering a room as a choir 'member'
    Microphone *user_microphone_object; //

    // TODO: implement the headphones section
};

#endif // USER_H
