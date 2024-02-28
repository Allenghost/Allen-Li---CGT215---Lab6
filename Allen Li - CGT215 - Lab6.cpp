// Allen Li - CGT215 - Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main() {
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Winter Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Yoda Image" << endl;
		exit(1);
	}
	Image bgImage;
	bgImage = backgroundTex.copyToImage();
	Image fgImage;
	fgImage = foregroundTex.copyToImage();
	Vector2u sz = bgImage.getSize();
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			// These two loops will run the code inside for each pixel in
			Color winterC = bgImage.getPixel(x, y);
			// You can access the current pixel at x,y like so:
			Color yodaC = fgImage.getPixel(x, y);
			// Color objects store the individual channel values like example.r example.g and example.b
			if ((yodaC.r == 32) && (yodaC.g == 214) && (yodaC.b == 23)) {
				fgImage.setPixel(x, y, winterC);
			}
		}
	}
	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(fgImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
