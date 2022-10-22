#ifndef AFFAIRE_H
#define AFFAIRE_H

#include<QSqlQueryModel>
#include<QTableView>
#include<QMessageBox>
class Affaire
{
private:
    int id;
    QString ordre;
    QString nom_juge;
    int  cin;
    QString type;
    QString type_p;
    QString date;

public:
    Affaire();
    Affaire(int idd, QString ordree,QString nom_jugee,  QString typee,QString type_pp,QString datee,
            int  cinn);
  int getid();
    QString  getordre();
      QString   getnom_juge();
     QString   gettype();
     QString   gettype_p();
     QString  getdate();
     QString  getcin();
    void setid(int idd);
    bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int id);
void chercher(QTableView *table,int cas );
};

#endif // AFFAIRE_H
