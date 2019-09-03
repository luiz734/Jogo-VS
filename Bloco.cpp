#pragma once
#include "Bloco.h"
//teste

Bloco::Bloco(int tamanhoX, int tamanhoY, int posX, int posY)
{
    isSafe = false;
    setTamX((float)(48 * tamanhoX));
    setTamY((float)(48 * tamanhoY));
    setPosX((float)(48 * posX));
    setPosY((float)(48 * posY));
}

Bloco::~Bloco()
{

}

bool Bloco::getIsSafe()
{
    return isSafe;
}
