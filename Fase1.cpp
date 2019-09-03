#include "Fase1.h"

Fase1::Fase1()
{

}

Fase1::~Fase1()
{

}

int Fase1::executar()
{
    //musica.openFromFile("files/Musica1.flac");
    listaEntidade->addEntidade(&backgound);
    listaEntidade->addEntidade(&heroi);

    backgound.setTamX(200*48);
    backgound.setTamY(15*48);
    backgound.setTextura("files/background2.png", 6, 0, 0, true);
    tile = "files/tile2.png";

    {
        BlocoAgua *temp = new BlocoAgua(200, 1, 0, 14);
        listaEntidade->addEntidade(temp);
    }

    for(int j = 0; j < SN; j++)
    {
        InimigoSpiky *temp = new InimigoSpiky(layoutSpiky[j][0], layoutSpiky[j][1]);
        listaInimigo->addInimigo(temp);
        listaEntidade->addEntidade(temp);
    }

    for(int j = 0; j < HN; j++)
    {
        InimigoBeorny *temp = new InimigoBeorny(layoutBeorny[j][0], layoutBeorny[j][1]);
        listaInimigo->addInimigo(temp);
        listaEntidade->addEntidade(temp);
    }

    for(int i = 0; i < BN; i++)
    {
        BlocoPlataforma *temp = new BlocoPlataforma(layoutBlocos[i][0], layoutBlocos[i][1], layoutBlocos[i][2], layoutBlocos[i][3], tile);
        listaBloco->addBloco(temp);
        listaEntidade->addEntidade(temp);
    }

    for(int i = 0; i < EN; i++)
    {
        BlocoEspinho *temp = new BlocoEspinho(layoutEspinhos[i][0], layoutEspinhos[i][1], layoutEspinhos[i][2], layoutEspinhos[i][3], layoutEspinhos[i][4]);
        listaBloco->addBloco(temp);
        listaEntidade->addEntidade(temp);
    }

    //musica.play();

    isAlive = motor->executar(&heroi, true);

    //musica.stop();

    listaInimigo->limpar();
    listaBloco->limpar();
    listaEntidade->limpar();

    if(isAlive == 1)
        return 1;
    else
        return isAlive-1;
}

