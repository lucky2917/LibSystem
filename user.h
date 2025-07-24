#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    enum UserType {
        ADMIN,
        CUSTOMER,
        INVALID
    };

    User();

    int id;
    QString username;
    QString password;
    UserType type;
};

#endif // USER_H
