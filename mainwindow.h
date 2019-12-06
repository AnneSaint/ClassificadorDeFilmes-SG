#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "anime.h"
#include <QVector>
#include <QMainWindow>
#include <algorithm>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_btnInserirAv_clicked();
    void inserirNaTabela(Anime a, int linha);

    int size();
    QVector<Anime> filmes;
    Anime anime;
private slots:
    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_btnInserir_clicked();

    void on_btnInserir_2_clicked();

    void on_btnApagar_clicked();

    void on_btnDelete_clicked();

    void on_btnDel_clicked();

    void on_comboOrdenar_activated(const QString &arg1);

    void ordenarPorAnimacao();
    void ordenarPorGenero();

    double duracao();

    void carregarDados(QString file);
    void salvarDados(QString file);
    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

private:
    Ui::MainWindow *ui;

    QString assistir = "";


};
#endif // MAINWINDOW_H
