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
	int h = 0, num, flg = 0, i = 0, wins = 0, bravo, size, pos, a = 0;
        int flgA = 0, flgB = 0, flgC = 0, flgD = 0, flgE = 0, flgF = 0, flgG = 0, flgH = 0, flgI = 0, flgJ = 0, flgK = 0, flgL = 0, 
        flgM = 0, flgN = 0, flgO = 0, flgP = 0, flgQ = 0, flgR = 0, flgS = 0, flgT = 0, flgU = 0, flgV = 0, flgW = 0, flgX = 0, flgY = 0, flgZ = 0,
        flgchoise = 0;
        char letter = 0, slovo[n], word[n];


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

	int chaslo;
	srand(time(NULL));

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

		if(wins || h > 9) {
                        restart.sprite.setTextureRect(IntRect(190, 644, 406, 40));
                        if (event.type == sf::Event::KeyPressed) {      
                                if (event.key.code == sf::Keyboard::Y) {
                                        wins = 0; h = 0; flg = 0; i = 0; a = 0;
                                        flgA = 0; flgB = 0; flgC = 0; flgD = 0; flgE = 0; flgF = 0; flgG = 0; flgH = 0; flgI = 0; flgJ = 0; flgK = 0; flgL = 0;
                                        flgM = 0; flgN = 0; flgO = 0; flgP = 0; flgQ = 0; flgR = 0; flgS = 0; flgT = 0; flgU = 0; flgV = 0; flgW = 0; flgX = 0; flgY = 0; flgZ =$
                                        flgchoise = 0;
                                        letter = 0;

                                        trys.sprite.setTextureRect(IntRect(0, 175, 53, 55));
                                        base.sprite.setTextureRect(IntRect(230,253, 160, 0)); 
                                        base2.sprite.setTextureRect(IntRect(12, 321, 25, 0));
                                        base3.sprite.setTextureRect(IntRect(393,250, 205, 0));
                                        base4.sprite.setTextureRect(IntRect(399, 272, 23, 0));
					base4.sprite.setTextureRect(IntRect(399, 272, 23, 0));
                                        head.sprite.setTextureRect(IntRect(48, 320, 80, 0));
                                        body.sprite.setTextureRect(IntRect(160, 320, 16, 0));
                                        lefthand.sprite.setTextureRect(IntRect(215, 338, 35, 0));
                                        righthand.sprite.setTextureRect(IntRect(277, 338, 35, 0));
                                        leftleg.sprite.setTextureRect(IntRect(320, 335, 26, 0)); 
                                        rightleg.sprite.setTextureRect(IntRect(347, 335, 23, 0));
                                        face.sprite.setTextureRect(IntRect(423, 273, 43, 0));
                                        loose.sprite.setTextureRect(IntRect(41, 426, 272, 0));
                                        win.sprite.setTextureRect(IntRect(385, 309, 212, 0));
                                        A.sprite.setPosition(25, 25);  A.sprite.setTextureRect(IntRect(0, 0, 53, 54));
                                        B.sprite.setPosition(85, 25); B.sprite.setTextureRect(IntRect(60, 0, 53, 54));
                                        C.sprite.setPosition(145, 25); C.sprite.setTextureRect(IntRect(120, 0, 53, 54));
                                        D.sprite.setPosition(205, 25); D.sprite.setTextureRect(IntRect(180, 0, 53, 54));
                                        E.sprite.setPosition(265, 25); E.sprite.setTextureRect(IntRect(240, 0, 53, 54)); 
                                        F.sprite.setPosition(325, 25); F.sprite.setTextureRect(IntRect(300, 0, 53, 54));
                                        G.sprite.setPosition(385, 25); G.sprite.setTextureRect(IntRect(360, 0, 53, 54));
                                        H.sprite.setPosition(445, 25); H.sprite.setTextureRect(IntRect(420, 0, 53, 54));
                                        I.sprite.setPosition(505, 25); I.sprite.setTextureRect(IntRect(480, 0, 53, 54));
                                        J.sprite.setPosition(565, 25); J.sprite.setTextureRect(IntRect(540, 0, 53, 54));
                                        K.sprite.setPosition(25, 83); K.sprite.setTextureRect(IntRect(0, 58, 53, 54));
                                        L.sprite.setPosition(85, 83); L.sprite.setTextureRect(IntRect(60, 58, 53, 54));
                                        M.sprite.setPosition(145, 83); M.sprite.setTextureRect(IntRect(120, 58, 53, 54));
                                        N.sprite.setPosition(205, 83); N.sprite.setTextureRect(IntRect(180, 58, 53, 54));
                                        O.sprite.setPosition(265, 83); O.sprite.setTextureRect(IntRect(240, 58, 53, 54));
                                        P.sprite.setPosition(325, 83); P.sprite.setTextureRect(IntRect(300, 58, 53, 54));
                                        Q.sprite.setPosition(385, 83); Q.sprite.setTextureRect(IntRect(360, 58, 53, 54));
                                        R.sprite.setPosition(445, 83); R.sprite.setTextureRect(IntRect(420, 58, 53, 54));
                                        S.sprite.setPosition(505, 83); S.sprite.setTextureRect(IntRect(480, 58, 53, 54));
                                        T.sprite.setPosition(565, 83); T.sprite.setTextureRect(IntRect(540, 58, 53, 54));
                                        U.sprite.setPosition(25, 141); U.sprite.setTextureRect(IntRect(0, 116, 53, 54));
                                        V.sprite.setPosition(85, 141); V.sprite.setTextureRect(IntRect(60, 116, 53, 54));
                                        W.sprite.setPosition(145, 141); W.sprite.setTextureRect(IntRect(120, 116, 53, 54));
                                        X.sprite.setPosition(205, 141); X.sprite.setTextureRect(IntRect(180, 116, 53, 54));
                                        Y.sprite.setPosition(265, 141); Y.sprite.setTextureRect(IntRect(240, 116, 53, 54));
                                        Z.sprite.setPosition(325, 141); Z.sprite.setTextureRect(IntRect(300, 116, 53, 54));
                                        restart.sprite.setTextureRect(IntRect(190, 644, 406, 0));
                                        texture.sprite.setTextureRect(IntRect(0, 0, 1150, 640));
                                        animals.sprite.setTextureRect(IntRect(51, 542, 168, 38));
                                        city.sprite.setTextureRect(IntRect(51, 592, 118, 38));
                                        color.sprite.setTextureRect(IntRect(57, 638, 118, 38));
                                        furniture.sprite.setTextureRect(IntRect( 51, 676, 209, 38));
                                         name.sprite.setTextureRect(IntRect(215, 545, 144, 38));
                                        enter.sprite.setTextureRect(IntRect(168, 590, 416, 55)); 
                                }
                        }
                }


		bravo = 0;

		if(h <= 10 && !wins) {
			if (event.type == sf::Event::KeyPressed && flg) {
				if (event.key.code == sf::Keyboard::A && !flgA) {letter = 'a';
					for (int i = 0; i < a; i++)
						if(slovo[i] == letter) {
							word[i] = letter;
							pos = i;
							A.sprite.move(15, 475);
							A.sprite.move(68*pos, 0);
							bravo = 1;
						}
					if (bravo == 0) {
						A.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
					}
					flgA = 1;
				}

				if (event.key.code == sf::Keyboard::B  && !flgB) {letter = 'b';
					for (int i = 0; i < a; i++)
						if(slovo[i] == letter) {
							word[i] = letter;
							pos = i;
							B.sprite.move(-45, 475);
							B.sprite.move(68*pos, 0);
							bravo = 1;
					}
					if (bravo == 0) {
						B.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
					}
					flgB = 1;
				}

				 if (event.key.code == sf::Keyboard::C  && !flgC) {letter = 'c';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        C.sprite.move(-105, 475);       
                                                        C.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                C.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgC = 1;
                                }    

                                if (event.key.code == sf::Keyboard::D  && !flgD) {letter = 'd';
                                        for (int i = 0; i < a; i++)
						if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        D.sprite.move(-165, 475);       
                                                        D.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                D.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgD = 1;
                                }    
				
				if (event.key.code == sf::Keyboard::E  && !flgE) {letter = 'e';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        E.sprite.move(-225, 475);       
                                                        E.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                E.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgE = 1;
                                }   

				if (event.key.code == sf::Keyboard::F  && !flgF) {letter = 'f';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        F.sprite.move(-285, 475);       
                                                        F.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                F.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgF = 1;
                                }   

				 if (event.key.code == sf::Keyboard::G  && !flgG) {letter = 'g'; 
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        G.sprite.move(-345, 475);       
                                                        G.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                G.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgG = 1;
                                }   

				 if (event.key.code == sf::Keyboard::H && !flgH) {letter = 'h';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        H.sprite.move(-405, 475);       
                                                        H.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                H.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgH = 1;
                                }    

				if (event.key.code == sf::Keyboard::I && !flgI) {letter = 'i';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        I.sprite.move(-465, 475);       
                                                        I.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                I.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgI = 1;
                                }   

				if (event.key.code == sf::Keyboard::J  && !flgJ) {letter = 'j';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        J.sprite.move(-525, 475);       
                                                        J.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                J.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgJ = 1;
                                }   


				 if (event.key.code == sf::Keyboard::K  && !flgK) {letter = 'k';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        K.sprite.move(15, 417); 
                                                        K.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                K.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgK = 1;
                                }   

				if (event.key.code == sf::Keyboard::L  && !flgL) {letter = 'l';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        L.sprite.move(-45, 417);        
                                                        L.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                L.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgL = 1;
                                }    

				 if (event.key.code == sf::Keyboard::M && !flgM) {letter = 'm';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        M.sprite.move(-105, 417);       
                                                        M.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                M.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgM = 1;
                                }   

				 if (event.key.code == sf::Keyboard::N && !flgN) {letter = 'n';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        N.sprite.move(-165, 417);       
                                                        N.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                N.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgN = 1;
                                }   

				if (event.key.code == sf::Keyboard::O && !flgO) {letter = 'o';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        O.sprite.move(-225, 417);       
                                                        O.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                O.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgO = 1;
                                }    

				if (event.key.code == sf::Keyboard::P && !flgP) {letter = 'p';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        P.sprite.move(-285, 417);       
                                                        P.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                P.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgP = 1;
                                }    

				 if (event.key.code == sf::Keyboard::Q && !flgQ) {letter = 'q';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        Q.sprite.move(-345, 417);       
                                                        Q.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                Q.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgQ = 1;
                                }    

				 if (event.key.code == sf::Keyboard::R && !flgR) {letter = 'r';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        R.sprite.move(-405, 417);       
                                                        R.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                R.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgR = 1;
                                }    

				if (event.key.code == sf::Keyboard::S && !flgS) {letter = 's';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        S.sprite.move(-465, 417);       
                                                        S.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                S.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgS = 1;
                                }    


				if (event.key.code == sf::Keyboard::T && !flgT) {letter = 't';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        T.sprite.move(-525, 417);       
                                                        T.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                T.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgT = 1;
                                }    
				
				if (event.key.code == sf::Keyboard::U && !flgU) {letter = 'u';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        U.sprite.move(15, 357); 
                                                        U.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                U.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgU = 1;
                                }   

				if (event.key.code == sf::Keyboard::V && !flgV) {letter = 'v';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        V.sprite.move(-45, 357);        
                                                        V.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                V.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgV = 1;
                                }    

				if (event.key.code == sf::Keyboard::W && !flgW) {letter = 'w';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        W.sprite.move(-105, 357);       
                                                        W.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                W.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgW = 1;
                                }   

                                if (event.key.code == sf::Keyboard::X && !flgX) {letter = 'x';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        X.sprite.move(-165, 357);       
                                                        X.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                X.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgX = 1;
                                }   

                                if (event.key.code == sf::Keyboard::Y && !flgY) {letter = 'y';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        Y.sprite.move(-225, 357);       
                                                        Y.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                       if (bravo == 0) {
                                        Y.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgY = 1;
                                }    

                                if (event.key.code == sf::Keyboard::Z  && !flgZ) {letter = 'z';
                                        for (int i = 0; i < a; i++)
                                                if(slovo[i] == letter) {
                                                        word[i] = letter;
                                                        pos = i;
                                                        Z.sprite.move(-285, 357);
                                                        Z.sprite.move(68*pos, 0);
                                                        bravo = 1;
                                                }
                                        if (bravo == 0) {
                                                Z.sprite.setTextureRect(IntRect(0, 175, 0, 0)); 
                                        }
                                        flgZ = 1;
                                }

                                if (bravo == 0) {  
                                        h++;
                                }


                                if (h == 1) {
					trys.sprite.setTextureRect(IntRect(60, 175, 53, 55));
                                        base.sprite.setTextureRect(IntRect(230,253, 160, 47)); }
                                if (h > 1) {
                                        trys.sprite.setTextureRect(IntRect(120, 175, 53, 55));
                                        base2.sprite.setTextureRect(IntRect(12, 321, 25, 245)); }
                                if (h > 2) {
                                        trys.sprite.setTextureRect(IntRect(180, 175, 53, 55));
                                        base3.sprite.setTextureRect(IntRect(393,250, 205, 20)); }
                                if (h > 3) {
                                        trys.sprite.setTextureRect(IntRect(240, 175, 53, 55));
                                        base4.sprite.setTextureRect(IntRect(399, 272, 23, 30)); }
                                if (h > 4) {
					trys.sprite.setTextureRect(IntRect(300, 175, 53, 55));
                                        head.sprite.setTextureRect(IntRect(48, 320, 80, 55); }			
                                if (h > 5) {
                                        trys.sprite.setTextureRect(IntRect(360, 175, 53, 55));
                                        body.sprite.setTextureRect(IntRect(160, 320, 16, 65)); }
                                if (h > 6) {
                                        trys.sprite.setTextureRect(IntRect(420, 175, 53, 55));
                                        lefthand.sprite.setTextureRect(IntRect(215, 338, 35, 30)); }
                                if (h > 7) {
                                        trys.sprite.setTextureRect(IntRect(480, 175, 53, 55));
                                        righthand.sprite.setTextureRect(IntRect(277, 338, 35, 30)); }
                                if (h > 8) {
                                        trys.sprite.setTextureRect(IntRect(540, 175, 53, 55));
                                        leftleg.sprite.setTextureRect(IntRect(320, 335, 26, 30)); }
                                if (h > 9) {
                                        trys.sprite.setTextureRect(IntRect(600, 175, 53, 55));
                                        rightleg.sprite.setTextureRect(IntRect(347, 335, 23, 33));
                                        face.sprite.setTextureRect(IntRect(423, 273, 43, 30));
                                        loose.sprite.setTextureRect(IntRect(41, 426, 272, 66));
                                }
                                wins = 1;
                                for (int i = 0; i < a; i++)
                                        if(word[i] == '_')
                                                wins = 0;
                                if (wins == 1)
                                        win.sprite.setTextureRect(IntRect(385, 309, 212, 68));
                        } 
                }

		if ((event.type == sf::Event::KeyPressed)) {
			if (!flg) {
				if (event.key.code == sf::Keyboard::A) {
					num = 1;
					flgchoise = 1;
				}

				if (event.key.code == sf::Keyboard::B) {
					num = 2;
					flgchoise = 1;
				}

				if (event.key.code == sf::Keyboard::C) {
					num = 3;
					flgchoise = 1;

				if (event.key.code == sf::Keyboard::D) {
					num = 4;
					flgchoise = 1;
				}

				if (event.key.code == sf::Keyboard::E) {
					num = 5;
					flgchoise = 1;
				}

				if (flgchoise) {
					chaslo = 0 + rand() % 19;
					texture.sprite.setTextureRect(IntRect(0, 175, 0, 0));
					animals.sprite.setTextureRect(IntRect(0, 175, 0, 0);
					city.sprite.setTextureRect(IntRect(0, 175, 0, 0));
					color.sprite.setTextureRect(IntRect(0, 175, 0, 0));
					furniture.sprite.setTextureRect(IntRect(0, 175, 0, 0));
					name.sprite.setTextureRect(IntRect(0, 175, 0, 0));
					enter.sprite.setTextureRect(IntRect(0, 175, 0, 0));
					if (num == 1) {
						for (int i = 0; i < n; i++)
						slovo[i] = slova1[chaslo][i];
					}
					if (num == 2) {
						for (int i = 0; i < n; i++)
						slovo[i] = slova2[chaslo][i];
					}

					if (num == 3){
						for (int i = 0; i < n; i++)
							slovo[i] = slova3[chaslo][i];
					}

					if (num == 4){
						for (int i = 0; i < n; i++)
							slovo[i] = slova4[chaslo][i];
					}

					if (num == 5){
						for (int i = 0; i < n; i++)
						slovo[i] = slova5[chaslo][i];
					}

					while(slovo[a] != '\0')
						a++;
					size = a - 3;
					number.sprite.setTextureRect(IntRect(55 + (44*size), 493, 42, 40));
					cell.sprite.setTextureRect(IntRect(39, 713, 68*a, 53));
					for (int i = 0; i < a; i++){
						word[i] = '_';
					}
					if (slovo[0] >= 65 && slovo[0] <= 90) {
						slovo[0] += 32; }
					flg = 1;
				}
			}
		}

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
