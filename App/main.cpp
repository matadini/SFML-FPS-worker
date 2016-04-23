#include <SFML/Graphics.hpp>
#include "fps-worker.h"

void main() {

	sf::RenderWindow app(sf::VideoMode(800, 600, 32), "FPS-worker-test", sf::Style::Default);

	FpsWorker myStabilizer(60);

	while (app.isOpen()) {
		
		/* Events */
		sf::Event myEvent;
		while (app.pollEvent(myEvent)) {
			if (myEvent.type == sf::Event::Closed) {
				app.close();
			}
		}

		/* Logic */
		myStabilizer.work();

		/* Render */
		app.clear(sf::Color::Green);

		app.display();
	}
}