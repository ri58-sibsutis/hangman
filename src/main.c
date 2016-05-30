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
	return 0;
}
