#ifndef FILMES_H
#define FILMES_H

#include <QDialog>

namespace Ui {
class Filmes;
}

class Filmes : public QDialog
{
    Q_OBJECT

public:
    explicit Filmes(QWidget *parent = nullptr);
    ~Filmes();

private:
    Ui::Filmes *ui;
};

#endif // FILMES_H
