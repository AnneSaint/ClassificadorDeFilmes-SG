#include "anime.h"

Anime::Anime()
{

}

QString Anime::getAnimacao() const
{
    return animacao;
}

bool Anime::setAnimacao(const QString &value)
{
    if(value != ""){
        animacao = value;
        return 1;
    }else {
        return 0;
    }
}

QString Anime::getGenero() const
{
    return genero;
}

bool Anime::setGenero(const QString &value)
{
    if(value != ""){
        genero = value;
        return 1;
    }else {
        return 0;
    }
}

double Anime::getNota() const
{
    return nota;
}

bool Anime::setNota(double value)
{
    if(value >= 0 and value <= 100){
        nota = value;
        return 1;
    }else {
        return 0;
    }
}

double Anime::getTempo() const
{
    return tempo;
}
bool Anime::setTempo(double value)
{
    if(value > 0){
        tempo = value;
        return 1;
    }else {
        return 0;
    }
}

QString Anime::getAvaliador() const
{
    return avaliador;
}

bool Anime::setAvaliador(const QString &value)
{
    if(value != ""){
        avaliador = value;
        return 1;
    }else {
        return 0;
    }
}

QString Anime::getAssistido() const
{
    return assistido;
}

bool Anime::setAssistido(const QString &value)
{
    if(value != ""){
        assistido = value;
        return 1;
    }else {
        return 0;
    }
}




