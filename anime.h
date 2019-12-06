#ifndef ANIME_H
#define ANIME_H

#include <QString>
#include <algorithm>


class Anime
{
public:
    Anime();

    void inserirNaTabela(Anime a, int linha);

    QString getAnimacao() const;
    bool setAnimacao(const QString &value);

    QString getGenero() const;
    bool setGenero(const QString &value);

    double getNota() const;
    bool setNota(double value);

    double getTempo() const;
    bool setTempo(double value);

    QString getAvaliador() const;
    bool setAvaliador(const QString &value);

    QString getAssistido() const;
    bool setAssistido(const QString &value);





private:
    QString animacao;
    QString genero;
    double nota;
    double tempo;
    QString avaliador;
    QString assistido;
};

#endif // ANIME_H
