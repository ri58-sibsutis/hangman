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


	return 0;
}
