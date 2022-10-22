#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("haroun");
db.setUserName("haroun");//inserer nom de l'utilisateur
db.setPassword("456123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
