#include <SFML/Graphics.hpp>
#include <stdio.h>
#define n 13
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace sf;

class Simbols {
public:
	float x, y, w, h;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Simbols(String F, float X, float Y, float W, float H) {
		File = F;
		w = W; h = H;
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(w, h, 53, 54));
		sprite.setPosition(x,y);
	}
};

class Hungman {
public:
	float x, y, w, h, a, b;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Hungman(String F, float X, float Y, float A, float B, float W, float H) {
		File = F;
		w = W; h = H; a = A; b = B;
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y; 
		sprite.setTextureRect(IntRect(a, b, w, h));
		sprite.setPosition(x,y);
	}
};

int main() {
	char theme1[20] = {"1-Animals"}, theme2[20] = {"2-City"}, theme3[20] = {"3-Color"}, theme4[20] = {"4-Furniture"}, theme5[20] = {"5-Name"},
	slova1[20][n] = {"Horse\0", "Goat\0", "Pig\0", "Cow\0", "Lion\0", "Fox\0", "Pony\0", "Frog\0", "Rat\0", "Wolf\0", "Mouse\0", "Crow\0", 
	"Zebra\0", "Lemur\0", "Cat\0", "Dog\0", "Tiger\0", "Chipmunk\0", "Leopard\0", "Monkey\0"},
	slova2[20][n] = {"Berlin\0", "Paris\0", "Baku\0", "Brest\0", "Minsk\0", "Cairo\0", "Dubai\0", "Lima\0", "Rome\0", "Cuba\0", "Athens\0", "Kiev\0", "Seoul\0", "Riga\0",
	"Cairo\0", "Dublin\0", "Lisbon\0", "Prague\0", "Tunis\0", "Lima\0"},
	slova3[20][n] = {"Red\0", "Orange\0", "Black\0", "Ruby\0", "Blue\0", "Azure\0", "Crimson\0", "Peach\0", "Gray\0", "White\0", "Pink\0", "Silver\0", "Golden\0", "Brown\0",
	"Koshtan\0", "Amber\0", "Marsh\0", "Olive\0", "Scarlet\0", "Violet\0"},
	slova4[20][n] = {"Bed\0", "Sofa\0", "Blanket\0", "Tap\0", "Vase\0", "Table\0", "Chair\0", "Stand\0", "Bar\0", "Iron\0", "Stove\0", "Fridge\0", "Oven\0",
	"Cot\0", "Carpet\0", "Blinds\0", "Desk\0", "Coupe\0", "Rug\0", "Lamp\0"},
	slova5[20][n] = {"Emily\0", "Andrew\0", "Jack\0", "James\0", "Wilson\0", "Dima\0", "Julia\0", "Ksenia\0", "Roman\0", "Fedor\0", "Max\0", "Egor\0", "Oleg\0",
	"Wandy\0", "Alice\0", "Grisha\0", "Joe\0", "Colin\0", "Isabel\0", "Alex\0"};

	RenderWindow window(sf::VideoMode(1150, 640), "HUNGMAN");

	Hungman base("hungman1.png",700, 400, 0, 0, 0, 0);
	Hungman base2("hungman1.png",780, 159, 0, 0, 0, 0);
	Hungman base3("hungman1.png",740, 170, 0, 0, 0, 0);
	Hungman base4("hungman1.png", 920, 185, 0, 0, 0, 0);
	Hungman head("hungman1.png", 890, 213, 0, 0, 0, 0);
	Hungman body("hungman1.png", 923, 267, 0, 0, 0, 0);
	Hungman lefthand("hungman1.png", 897, 277, 0, 0, 0, 0);
	Hungman righthand("hungman1.png", 925, 278, 0, 0, 0, 0);
	Hungman leftleg("hungman1.png", 905, 323, 0, 0, 0, 0);
	Hungman rightleg("hungman1.png", 927, 321, 0, 0, 0, 0);
	Hungman face("hungman1.png", 910, 230, 0, 0, 0, 0);

	Hungman tries("hungman1.png", 775, 542, 4, 237, 212, 65);
	Hungman loose("hungman1.png", 400, 250, 0, 0, 0, 0);
	Hungman win("hungman1.png", 401, 250, 0, 0, 0, 0);
	Hungman texture("texture1.png", 0, 0, 0, 0, 1150, 640);
	Hungman letters("hungman1.png", 40, 350, 44, 384, 416, 40);
	Hungman number("hungman1.png", 290, 355, 55, 493, 42, 40);
	Hungman cell("hungman1.png", 40, 500, 39, 713, 533, 53);

	Hungman animals("hungman1.png", 340, 200, 51, 542, 168, 38);
	Hungman city("hungman1.png", 670, 200, 51, 592, 118, 38);
	Hungman color("hungman1.png", 340, 280, 57, 638, 118, 38);
	Hungman furniture("hungman1.png", 670, 280, 51, 676, 209, 38);
	Hungman name("hungman1.png", 530, 360, 215, 545, 144, 38);
	Hungman enter("hungman1.png", 380, 80, 168, 590, 416, 55);
	Hungman restart("hungman1.png", 350, 320, 190, 644, 406, 0);

	Simbols trys("hungman1.png", 970, 555, 0, 175);
	Simbols A("hungman1.png", 25, 25, 0, 0);
	Simbols B("hungman1.png", 85, 25, 60, 0);
	Simbols C("hungman1.png", 145, 25, 120, 0);
	Simbols D("hungman1.png", 205, 25, 180, 0);
	Simbols E("hungman1.png", 265, 25, 240, 0);
	Simbols F("hungman1.png", 325, 25, 300, 0);
	Simbols G("hungman1.png", 385, 25, 360, 0);
	Simbols H("hungman1.png", 445, 25, 420, 0);
	Simbols I("hungman1.png", 505, 25, 480, 0);
	Simbols J("hungman1.png", 565, 25, 540, 0);
	Simbols K("hungman1.png", 25, 83, 0, 58);
	Simbols L("hungman1.png", 85, 83, 60, 58);
	Simbols M("hungman1.png", 145, 83, 120, 58);
	Simbols N("hungman1.png", 205, 83, 180, 58);
	Simbols O("hungman1.png", 265, 83, 240, 58);
	Simbols P("hungman1.png", 325, 83, 300, 58);
	Simbols Q("hungman1.png", 385, 83, 360, 58);
	Simbols R("hungman1.png", 445, 83, 420, 58);
	Simbols S("hungman1.png", 505, 83, 480, 58);
	Simbols T("hungman1.png", 565, 83, 540, 58);
	Simbols U("hungman1.png", 25, 141, 0, 116);
	Simbols V("hungman1.png", 85, 141, 60, 116);
	Simbols W("hungman1.png", 145, 141, 120, 116);
	Simbols X("hungman1.png", 205, 141, 180, 116);
	Simbols Y("hungman1.png", 265, 141, 240, 116);
	Simbols Z("hungman1.png", 325, 141, 300, 116);

	while (window.isOpen()) {
		sf::Event event;
		while (!window.pollEvent(event)) {}

		if (event.type == sf::Event::Closed)
			window.close();

		window.clear();
		window.draw(trys.sprite);

		window.draw(cell.sprite);
		window.draw(A.sprite);
		window.draw(B.sprite);
		window.draw(C.sprite);
		window.draw(D.sprite);
		window.draw(E.sprite);
		window.draw(F.sprite);
		window.draw(G.sprite);
		window.draw(H.sprite);
		window.draw(I.sprite);
		window.draw(J.sprite);
		window.draw(K.sprite);
		window.draw(L.sprite);
		window.draw(M.sprite);
		window.draw(N.sprite);
		window.draw(O.sprite);
		window.draw(P.sprite);
		window.draw(Q.sprite);
		window.draw(R.sprite);
		window.draw(S.sprite);
		window.draw(T.sprite);
		window.draw(U.sprite);
		window.draw(V.sprite);
		window.draw(W.sprite);
		window.draw(X.sprite);
		window.draw(Y.sprite);
		window.draw(Z.sprite);

		window.draw(base.sprite);
		window.draw(base2.sprite);
		window.draw(base3.sprite);
		window.draw(base4.sprite);
		window.draw(head.sprite);
		window.draw(body.sprite);
		window.draw(lefthand.sprite);
		window.draw(righthand.sprite);
		window.draw(leftleg.sprite);
		window.draw(rightleg.sprite);
		window.draw(face.sprite);

		window.draw(letters.sprite);
		window.draw(loose.sprite);
		window.draw(win.sprite);
		window.draw(tries.sprite);
		window.draw(number.sprite);
		window.draw(restart.sprite);

		window.draw(texture.sprite);
		window.draw(animals.sprite);
		window.draw(city.sprite);
		window.draw(color.sprite);
		window.draw(furniture.sprite);
		window.draw(name.sprite);
		window.draw(enter.sprite);
		window.display();
        }
	return 0;
}
