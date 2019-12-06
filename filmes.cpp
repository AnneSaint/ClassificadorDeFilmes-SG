#include "filmes.h"
#include "ui_filmes.h"

Filmes::Filmes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Filmes)
{
    ui->setupUi(this);
}

Filmes::~Filmes()
{
    delete ui;
}
