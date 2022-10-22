#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"connection.h"
#include"affaire.h"
#include<QIntValidator>
#include<QTableView>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // the edit lineedit will only accept integers between 100 and 999
    ui->id->setValidator(new QIntValidator(0, 999999, this));

    ui->tableView_aff_h->setModel(ff.afficher());

    ui->listView->setModel(ff.afficher());
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{

    int id=ui->id->text().toInt();
QString ordre=ui->comboBox_4->currentText();
QString nomj=ui->nom->text();
int cinj=ui->cin->text().toInt();
QString type=ui->comboBox_2->currentText();
QString typep=ui->comboBox_3->currentText();
QString datee=ui->_date_h->text();

    Affaire f(id,ordre,nomj,type,typep,datee,cinj);

    bool test=f.ajouter();

if (test)
{


    ui->tableView_aff_h->setModel(ff.afficher());

    ui->listView->setModel(ff.afficher());

    QMessageBox::information(nullptr, QObject::tr("félicitations"),
                QObject::tr("Ajout réussi.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::information(nullptr, QObject::tr("Échec"),
                QObject::tr("Échec de l'ajout.\n"

                  "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_pushButton_Sui_m_clicked()
{
    Affaire f;
    f.setid(ui->lineEdit_idS_h->text().toInt());
bool test=f.supprimer(f.getid());


if(test)
{

    ui->tableView_aff_h->setModel(ff.afficher());


    QMessageBox::critical(nullptr, QObject::tr("database is open"),
                QObject::tr("supp successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("supp failed.\n"

                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_chercher_2_clicked()
{
    int ch=ui->cher->text().toInt();
    Affaire f;
    f.chercher(ui->tableView_aff_h_2,ch);
    if(ui->cher->text().isEmpty())
    {
        ui->tableView_aff_h_2->setModel(f.afficher());
    }
}
