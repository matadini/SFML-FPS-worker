/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   FPS_Manager.h
* Author: madmatt
*
* Created on 18 listopad 2015, 22:58
*/

#ifndef FPS_MANAGER_H
#define FPS_MANAGER_H

#include <SFML/System.hpp>
#include <iostream>

/* Klasa sluzy do stabilizacji fps dla aplikacji SFML */
class FPS_Manager
{
public:
	FPS_Manager(int obj);

	/* On/off fps log in console */
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

#endif /* FPS_MANAGER_H */
