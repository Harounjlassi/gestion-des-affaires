#include "affaire.h"

#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QMessageBox>
Affaire::Affaire()
{id=0;
    type="";
    ordre= "";
    nom_juge= "";
    type= "";
    type_p= "";
    date= "";
     cin=  0;

}
 Affaire::Affaire(int idd, QString ordree,QString nom_jugee,  QString typee,QString type_pp,QString datee,
                  int  cinn)
    {
        id=idd;
        type=typee;
        ordre= ordree;
        nom_juge= nom_jugee;
        type= typee;
        type_p= type_pp;
        date= datee;
         cin=  cinn;

    }
    int Affaire:: getid(){return id;}
   QString  Affaire:: gettype(){return type;}
   QString  Affaire:: getordre(){return type;}
   QString  Affaire:: getnom_juge(){return type;}
   QString  Affaire:: gettype_p(){return type;}
   QString  Affaire:: getdate(){return type;}
   QString  Affaire:: getcin(){return type;}

    void Affaire:: setid(int idd ){id=idd;}
    bool Affaire::ajouter(){

        QSqlQuery query;
        QString id_string=QString::number(id);
        QString cin_string=QString::number(cin);

              query.prepare("INSERT INTO Affaire (id,ordre,nom_juge,cin_juge,type,type_p,datea) "
                            "VALUES (:id,:ordree,:non_jugee,:cin_jugee,:typee,:type_pp,:dateaa )");
              query.bindValue(":id", id_string);
              query.bindValue(":ordree", ordre);
              query.bindValue(":non_jugee", nom_juge);
              query.bindValue(":cin_jugee", cin_string);
              query.bindValue(":typee", type);
              query.bindValue(":type_pp", type_p);
              query.bindValue(":dateaa", date);

              return query.exec();

    }

    QSqlQueryModel* Affaire::afficher()
    {
        QSqlQueryModel *model=new QSqlQueryModel();

        model->setQuery("SELECT* FROM affaire");
      //model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifaint"));
      // model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));


        return model;



    }
    bool Affaire::supprimer(int id ){

        QSqlQuery query;

        query.prepare("Delete from  Affaire where id=:id");
        query.bindValue(":id", id);
        return query.exec();


    }
    void Affaire ::chercher(QTableView *table,int cas )
     {
         QSqlQueryModel *model= new QSqlQueryModel();

         QSqlQuery *query=new QSqlQuery;
         QString cas_string=QString::number(cas);

         query->prepare("SELECT * FROM Affaire WHERE (id LIKE "+cas_string+  ")");

         //model->setQuery("SELECT* FROM affaire");

        // model->setQuery(*query);
         if(query->exec()){
         model->setQuery(*query);
         table->setModel(model);
         table->show();}else{


             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("supp failed.\n"

                           "Click Cancel to exit."), QMessageBox::Cancel);

         }

     }
