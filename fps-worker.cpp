#include "fps-worker.h"
#include <iostream>

FpsWorker::FpsWorker(int obj) :
	m_sleepValue(0.0),
	m_miniFPS(obj-m_errorMargin),
	m_maxFPS(obj+ m_errorMargin),
	m_currentFPS(0.f),
	m_showLog(false){ 
}


void FpsWorker::setLog(bool obj){
	m_showLog = obj;
}


/* Use this function in main sfml-app loop */
void FpsWorker::work(){

	/* Get current app FPS */
	m_timeBuffer = m_clockBuffer.restart();
	m_currentFPS = getFPS();

	/* Change sleep value */
	if (m_currentFPS < m_miniFPS || m_currentFPS > m_maxFPS)
	{
		if (m_currentFPS < m_miniFPS){
			m_sleepValue -= 0.001;
		}

		if (m_currentFPS > m_maxFPS){
			m_sleepValue += 0.001;
		}
	}

	/* If log is on, show it in console */
	if (m_showLog){
		std::cout << "FPS: " << m_currentFPS << std::endl;
	}

	/* Sleep theard */
	sf::sleep(sf::seconds((float)m_sleepValue));
}

float FpsWorker::getFPS(){

	return (1000000.0f / m_timeBuffer.asMicroseconds());
}