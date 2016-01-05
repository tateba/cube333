/**
 * @file		cube333.ino
 * @brief	Programmation d'un cube 3 * 3 * 3 pour faire des jeu de limiere.
 * @author	Theodore ATEBA
 * @version	1.0.
 * @date		29 Mai 2015
 */

#include "ledCubeLib.h"

/**
 * @fn		setup
 * @brief	Point d'entree de l'application et fonction principal.
 */
void setup(){
	for(int cubePin = 2; cubePin <= 13; cubePin++){
		pinMode(cubePin, OUTPUT);
	}
}
	
/**
 * @fn		loop
 * @brief	Fonction principale du programme.
 */
void loop() 
{
	cubeBlink(50, 10); // Clignoter 10 fois avec un delay de 50ms entre les on - off des leds
	cubeOn(200);

	cubeTopOff(200);
	
	cubeMidleOff(200);
	cubeBottomOff(200);
	cubeTopOn(200);
	cubeMidleOn(200);
	cubeBottomOn(200);
	
	cubeOn(200);
	cubeOff(200);
	
	cubeFace1On(200);
	cubeFace2On(200);
	cubeFace3On(200);
	cubeFace4On(200);

	while(1){
		for(int i = 0; i<10; i++)
			testCubeFace(200);
		
		for(int i = 0; i < 10; i++){
			shadowOff(80);
			shadowOn(80);
		}
		
		for(int i = 0; i < 10; i++)
			cubeCircularDemo(50);
		
		for(int i = 0; i < 10; i++)
			rotation(200);
		
		effect(300, 10);
	}
}
