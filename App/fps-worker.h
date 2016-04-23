#ifndef FPS_MANAGER_H
#define FPS_MANAGER_H

#include <SFML/System.hpp>

class FpsWorker
{
public:
	FpsWorker(int obj);

	void setLog(bool obj);
	void work();

private:
	sf::Clock m_clockBuffer;
	sf::Time m_timeBuffer;

	double m_sleepValue;

	int m_miniFPS;
	int m_maxFPS;

	float m_currentFPS;
	float getFPS();

	bool m_showLog; 
};

#endif
