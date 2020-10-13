#include "User.h"
User::User(QString name, int value): username(name), volume_value(value) 
{

}

QString User::getUsername() const
{ 
	return username; 
}

int User::getVolumeValue() const
{
	return volume_value;
}

void User::setVolumeValue(const int &value)
{
	volume_value = value;
}

void User::setUsername(const QString &name)
{
	username = name;
}