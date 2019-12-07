#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "anime.h"
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btnInserir_2_clicked()
{


     int quantidade_linhas = ui->tabelaFilmes->rowCount();

   if ( anime.setAnimacao(ui->comboFilmes->currentText()) and anime.setNota(ui->lineNota->text().toDouble()) and anime.setGenero(ui->comboGender->currentText()) and anime.setTempo(ui->lineTempo->text().toDouble()) and anime.setAvaliador(ui->lineAvaliador->text())   and   anime.setAssistido(assistir) ){


       filmes.push_back(anime);
       ui->tabelaFilmes->insertRow(quantidade_linhas);
       inserirNaTabela(anime, quantidade_linhas);

    }else{
       QMessageBox::warning(this, "Error", "Todos os dados não foram inseridos!\nTente de novo. ");
   }


   ui->lineNota->clear();
   ui->lineTempo->clear();
   ui->lineAvaliador->clear();


   ui->labelDura->setText(QString::number(duracao()));


}




void MainWindow::inserirNaTabela(Anime a, int linha)
{
    ui->tabelaFilmes->setItem(linha,0, new QTableWidgetItem(a.getAnimacao()));
    ui->tabelaFilmes->setItem(linha,1, new QTableWidgetItem(QString::number(a.getNota())));
    ui->tabelaFilmes->setItem(linha,2, new QTableWidgetItem(QString::number(a.getTempo())));
    ui->tabelaFilmes->setItem(linha,3, new QTableWidgetItem(a.getGenero()));
    ui->tabelaFilmes->setItem(linha,4, new QTableWidgetItem(a.getAssistido()));
    ui->tabelaFilmes->setItem(linha,5, new QTableWidgetItem(a.getAvaliador()));

}

int MainWindow::size()
{
    return filmes.size();
}



void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_radioButton_clicked()
{
    assistir = "sim";
}

void MainWindow::on_radioButton_2_clicked()
{
    assistir = "não";
}




void MainWindow::on_btnApagar_clicked()
{
    QMessageBox::StandardButton x = QMessageBox::question(this, "Excluir Dados", "Deseja mesmo excluir?");
    if(x == QMessageBox::Yes){
        QString nome = QInputDialog::getText(this, "Excluir Dados", "Digite o nome do filme que deseja excluir :");

        for(int i = 0; i < filmes.size(); i++){
            if(filmes[i].getAnimacao() == nome){

                filmes.erase(filmes.begin()+i);
                break;
            }
        }

        ui->tabelaFilmes->setRowCount(0);

        for(int i = 0; i < filmes.size(); i++){
            ui->tabelaFilmes->insertRow(i);

            inserirNaTabela(filmes[i], i);
        }

    }
}


void MainWindow::on_comboOrdenar_activated(const QString &arg1)
{
    if(arg1 == "Animação"){
        ordenarPorAnimacao();
    }else if (arg1 == "Gênero"){
        ordenarPorGenero();
    }
}


void MainWindow::ordenarPorAnimacao()
{
    std::sort(filmes.begin(), filmes.end(), [](Anime a, Anime c){
        return a.getAnimacao() < c.getAnimacao();
    });



    ui->tabelaFilmes->setRowCount(0);

    for(int i = 0; i < filmes.size(); i++){
        ui->tabelaFilmes->insertRow(i);

        inserirNaTabela(filmes[i], i);
    }

}


void MainWindow::ordenarPorGenero()
{
    std::sort(filmes.begin(), filmes.end(), [](Anime a, Anime c){
        return a.getGenero() < c.getGenero();
    });


    ui->tabelaFilmes->setRowCount(0);

    for(int i = 0; i < filmes.size(); i++){
        ui->tabelaFilmes->insertRow(i);

        inserirNaTabela(filmes[i], i);
    }

}

double MainWindow::duracao()
{
    double temp = 0;
    for (auto i : filmes){
        temp += i.getTempo();
    }
    return temp;
}

void MainWindow::carregarDados(QString file)
{
    QFile arquivo(file);
    arquivo.open(QIODevice::ReadOnly);
    QString linha;
    QStringList dados;
    while(!arquivo.atEnd()){
        Anime temp;
        linha = arquivo.readLine();
        dados = linha.split(";");
        temp.setAnimacao(dados[0]);
        temp.setNota(dados[1].toDouble());
        temp.setTempo(dados[2].toDouble());
        temp.setGenero(dados[3]);
        temp.setAssistido(dados[4]);
        temp.setAvaliador(dados[5]);

        filmes.push_back(temp);

    }
    arquivo.close();
}


void MainWindow::salvarDados(QString file)
{
    QFile arq(file);
    arq.open(QIODevice::WriteOnly);
    for (auto nice : filmes){
        QString lin = nice.getAnimacao() + ";" + QString::number(nice.getNota()) + ";" +  QString::number(nice.getTempo()) + ";" + nice.getGenero() + ";" + nice.getAssistido() + ";" + nice.getAvaliador() + "\n";
            arq.write(lin.toLocal8Bit());
    }
    arq.close();
}


void MainWindow::on_actionSalvar_triggered()
{
    QString temp;
    temp = QFileDialog::getSaveFileName(this, "Salvar", "","*.csv");
    salvarDados(temp);
}


void MainWindow::on_actionCarregar_triggered()
{
    QString temp;
    temp = QFileDialog::getOpenFileName(this, "Carregar","","*.csv");
    carregarDados(temp);

    for(int i = 0; i < filmes.size(); i++){
        ui->tabelaFilmes->insertRow(i);
        inserirNaTabela(filmes[i], i);
    }
}


void MainWindow::editar(QString txt, QString Animcao, QString nota, QString duracao, QString genero, QString assistido, QString Avaliador, QVector<Anime> &ordem)
{
    for (int i =0; i <ordem.size(); i++){
        if (ordem[i].getAnimacao() == txt){

            if (Animcao != "") filmes[i].setAnimacao(Animcao);
            if (nota != "") filmes[i].setNota(nota.toDouble());
            if (duracao != "") filmes[i].setTempo(duracao.toDouble());
            if (genero != "") filmes[i].setGenero(genero);
            if (assistido != "") filmes[i].setAssistido(assistido);
            if (Avaliador != "") filmes[i].setAvaliador(Avaliador);
        }
    }

}


void MainWindow::on_btnEdit_clicked()
{


    QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você deseja editar um item?");
    if(resp == QMessageBox::Yes){
            bool ok;
            QString txt = QInputDialog::getText(this, "Editar Itens", "Digite o título da Animação que deseja editar!", QLineEdit::Normal,"",&ok);
            QMessageBox::warning(this, "Alerta", "Se você não quiser editar algum item, apenas selecione a opção OK :3");
            QString Animacao = QInputDialog::getText(this, "Editar Itens", "Insira o novo Título", QLineEdit::Normal,"",&ok);
            QString nota = QInputDialog::getText(this, "Editar Itens", " Insira uma nova Nota", QLineEdit::Normal,"",&ok);
            QString duracao = QInputDialog::getText(this, "Editar Itens", "Insira outra Duração", QLineEdit::Normal,"",&ok);
            QString genero = QInputDialog::getText(this, "Editar Itens", "Insira outro Gênero", QLineEdit::Normal,"",&ok);
            QString assistido = QInputDialog::getText(this, "Editar Itens", "Você já tinha assistido?\nSim ou Não?", QLineEdit::Normal,"",&ok);
            QString avaliador = QInputDialog::getText(this, "Editar Itens", "Modifique o nome do Avaliador", QLineEdit::Normal,"",&ok);


            editar(txt, Animacao, nota, duracao, genero, assistido, avaliador, filmes );

            qDebug()<<genero;

            for(int i=0;i<filmes.size();i++)inserirNaTabela(filmes[i],i);
    }

}
