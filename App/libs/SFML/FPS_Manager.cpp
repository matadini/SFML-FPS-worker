#include "FPS_Manager.h"


FPS_Manager::FPS_Manager(int obj) :
	m_sleepValue(0.0),
	m_miniFPS(obj-5),
	m_maxFPS(obj+5),
	m_currentFPS(0.f),
	m_showLog(false)
{ }


void FPS_Manager::setLog(bool obj)
{
	this->m_showLog = obj;
}


void FPS_Manager::work()
{
	/* Uaktoanienie zegara */
	this->m_timeBuffer = this->m_clockBuffer.restart();

	/* Wyliczenie fps */
	this->m_currentFPS = this->getFPS();

	/* Ewentualne operacje */
	if (this->m_currentFPS < this->m_miniFPS || m_currentFPS > this->m_maxFPS)
	{
		if (this->m_currentFPS < this->m_miniFPS){
			m_sleepValue -= 0.001;
		}

		if (this->m_currentFPS > this->m_maxFPS){
			m_sleepValue += 0.001;
		}

	}

	if (this->m_showLog){
		std::cout << "FPS: " << this->m_currentFPS << std::endl;
	}

	sf::sleep(sf::seconds((float)m_sleepValue));
}

float FPS_Manager::getFPS()
{
	return (1000000.0f / m_timeBuffer.asMicroseconds());
}