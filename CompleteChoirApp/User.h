#pragma once
#include <qstring.h>

class User
{
public:
	User(QString name="", int value=0);
	int getVolumeValue() const;
	QString getUsername() const;
	void setVolumeValue(const int &value);
	void setUsername(const QString &name);
private:
	QString username;
	int volume_value;
};

