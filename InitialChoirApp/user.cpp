#include "user.h"

User::User()
{

}

QString User::getUser_role() const
{
    return user_role;
}

void User::setUser_role(const QString &value)
{
    user_role = value;
}

QString User::getIp_address_login() const
{
    return ip_address_login;
}

void User::setIp_address_login(const QString &value)
{
    ip_address_login = value;
}

QString User::getName() const
{
    return name;
}

void User::setName(const QString &value)
{
    name = value;
}

QString User::getSection() const
{
    return section;
}

void User::setSection(const QString &value)
{
    section = value;
}

QString User::getIp_address_choir_room() const
{
    return ip_address_choir_room;
}

void User::setIp_address_choir_room(const QString &value)
{
    ip_address_choir_room = value;
}

Microphone *User::getUser_microphone_object() const
{
    return user_microphone_object;
}

void User::setUser_microphone_object(Microphone *value)
{
    user_microphone_object = value;
}
