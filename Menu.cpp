#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

int Menu::executar(RenderWindow *janela, View *camera)
{
    camera->setCenter(480, 360);
    janela->setView(*camera);

	Event evento;
	bool ativo = true;
	Texture textura;
	Sprite sprite;
	Font fonte;
	Text menu0;
	Text menu2;
	Text menu3;
	Text menu4;
	int menu = 0;

	textura.loadFromFile("files/background2.png");

	sprite.setTexture(textura);
	sprite.setColor(Color(255, 255, 255, 255*3));
	sprite.scale(6,6);

    fonte.loadFromFile("files/pixel.ttf");

	menu0.setFont(fonte);
	menu0.setCharacterSize(100);
	menu0.setString("Fase 1");
	menu0.setPosition({ 350.f, 100.f });

	menu2.setFont(fonte);
	menu2.setCharacterSize(100);
	menu2.setString("Fase 2");
	menu2.setPosition({ 350.f, 250.f });

	menu3.setFont(fonte);
	menu3.setCharacterSize(100);
	menu3.setString("Chefão");
	menu3.setPosition({ 350.f, 400.f });

	menu4.setFont(fonte);
	menu4.setCharacterSize(100);
	menu4.setString("Exit");
	menu4.setPosition({ 350.f, 550.f });

	while (ativo)
	{
		while (janela->pollEvent(evento))
		{
			// Window closed
			if (evento.type == Event::Closed)
			{
				return -2;
			}
			//Key pressed

			if (evento.type == Event::KeyPressed)
			{
				switch (evento.key.code)
				{
                    case Keyboard::Up:
                        if(menu > 0)
                            menu--;
                        else
                            menu = 3;
                        break;
                    case Keyboard::Down:
                        if(menu < 3)
                            menu++;
                        else
                            menu = 0;
                        break;
                    case Keyboard::Return:
                        return menu;
                        break;
                    default:
                        break;
				}
			}
		}

		sprite.setColor(Color(255, 255, 255, 255*3));
		if (menu == 0)
		{
			menu0.setFillColor(Color::Red);
			menu2.setFillColor(Color::Black);
			menu3.setFillColor(Color::Black);
			menu4.setFillColor(Color::Black);
		}
		else if(menu == 1)
        {
            menu0.setFillColor(Color::Black);
            menu2.setFillColor(Color::Red);
            menu3.setFillColor(Color::Black);
            menu4.setFillColor(Color::Black);
        }
        else if(menu == 2)
        {
            menu0.setFillColor(Color::Black);
            menu2.setFillColor(Color::Black);
            menu3.setFillColor(Color::Red);
            menu4.setFillColor(Color::Black);
        }
        else if(menu == 3)
        {
            menu0.setFillColor(Color::Black);
            menu2.setFillColor(Color::Black);
            menu3.setFillColor(Color::Black);
            menu4.setFillColor(Color::Red);
        }


		janela->clear();
		janela->draw(sprite);

        janela->draw(menu0);
        janela->draw(menu2);
        janela->draw(menu3);
        janela->draw(menu4);
		janela->display();

    }

	return -2;
}


