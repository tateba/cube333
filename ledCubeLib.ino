
/**
 * @file	cubeLib.ino
 * @brief	Definition des fonctions permettant de tester le Cube à LED3x3x3.
 * @author	Theodore ATEBA
 * @version	1.0.
 * @date	29 Mai 2015
 */

#include "ledCubeLib.h"

//=============================================================================
//	Les fonctions
//=============================================================================

/**
 * @fn			cubeOn
 * @brief		Allumer toutes les leds du cube.
 * @param[in]	tempo temps d'allumage du cube.
 */
void cubeOn(long tempo){
	for(int cubePin = 2; cubePin < 14; cubePin++)
		digitalWrite(cubePin, HIGH);
	delay(tempo);
}
	
/**
 * @fn			cubeOff
 * @brief		Eteindre toutes les leds du cube
 * @param[in]	tempo temps d'extinction du cube.
 */
void cubeOff(long tempo){
	for(int cubePin = 2; cubePin < 14; cubePin++)
		digitalWrite(cubePin, LOW);
	delay(tempo);
}

/**
 * @fn			shadowOn
 * @brief		Allumage aleatoire.
 * @param[in]	tempo temps entre l'allumage de deux LEDs, en milli-seconde
 */
void shadowOn(long tempo){
	for(int cubePin = 2; cubePin < 14; cubePin++){
		digitalWrite(cubePin, HIGH);
		delay(tempo);
	}
}
	
/**
 * @fn			shadowOff
 * @brief		Eteindre aleatoirement les Leds du cube.
 * @param[in]	tempo temps entre l'extinction de deux LEDs, en milli-seconde
 */
void shadowOff(long tempo){
	for(int cubePin = 2; cubePin < 14; cubePin++){
		digitalWrite(cubePin, LOW);
		delay(tempo);
	}
}

/**
 * @fn			lineWrite
 * @brief		piloter les Leds des plans du cube qui sont actifs.
 * @param[in]	lineState
 */
void lineWrite( int lineState[9]){
	for(int line = 0; line <= 8; line++)
		digitalWrite(line + 2, lineState[line]);	// On a un offset de 2 car on 
																							// commance a D2 la connection au cube.
}

/**
 * @fn			layerWrite
 * @brief		Selection d'un des trois plans du cube.
 * @param[in]	lineState
 */
void layerWrite(int layerState[3]){
	for(int layer = 0; layer <= 2; layer++)
		digitalWrite(layer+11, layerState[layer]);
}

/**
 * @fn			cubeTopOff
 * @brief		Eteindre le plan 1 du cube.
 * @param[in]	tempo temps d'extinction du dessus du cube.
 */
void cubeTopOff(long tempo){
	digitalWrite(PLAN2, LOW);
	delay(tempo);
}
	
/**
 * @fn			cubeTopOn
 * @brief		Allumer le plan 1 du cube.
 * @param[in]	tempo temps d'allumage du dessus du cube.
 */
void cubeTopOn(long tempo){
	int plan[3] = {1,0,0}; // top , midle, Bottom
	int lineState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
	delay(tempo);
}
	
/**
 * @fn			cubeMidleOff
 * @brief		Eteindre le plan 2 du cube.
 * @param[in]	tempo temps d'extinction du plan 2 du cube.
 */
void cubeMidleOff(long tempo){
	digitalWrite(PLAN1, LOW);
	delay(tempo);
}
	
/**
 * @fn			cubeMidleOn
 * @brief		Allumer le Plan 2 du cube.
 * @param[in]	tempo temps d'allumage du plan 2 du cube.
 */
void cubeMidleOn(long tempo){
	int plan[3] = {0,1,0}; // top , midle, Bottom
	int lineState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
	delay(tempo);
}

/**
 * @fn			cubeBottomOff
 * @brief		Eteindre le plan 3 du cube.
 * @param[in]	tempo temps d'extinction du plan 3 du cube.
 */
void cubeBottomOff(long tempo){
	digitalWrite(PLAN0, LOW);
	delay(tempo);
}
	
/**
 * @fn			cubeBottomOn
 * @brief		Allumer le plan 3 du cube.
 * @param[in]	tempo temps d'allumage du plan 3 du cube.
 */
void cubeBottomOn(long tempo){
	int plan[3] = {0,0,1}; // top , midle, Bottom
	int lineState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
	delay(tempo);
}
	
/**
 * @fn			cubeBlink
 * @brief		Faire clignoter le cube de leds.
 * @param[in]	tempo le temps de clignotement en milli seconde
 * @param[in]	blinkNbr le nombre de clignotement souhaite
 */
void cubeBlink(long tempo, char blinkNbr){
	for(int i = 0; i < blinkNbr; i++){
		cubeOn(tempo);
		cubeOff(tempo);
	}
}

/**
 * @fn			cubeCircularDemo
 * @brief		Faire une demonstareation d'alumage circulaire.
 * @param[in]	tempo temps de l'effet de rotation.
 */
void cubeCircularDemo(long tempo){
	int lineState1[9] = {1, 0, 0, 0, 0, 0, 0, 0, 0};
	int lineState2[9] = {0, 1, 0, 0, 0, 0, 0, 0, 0};
	int lineState3[9] = {0, 0, 1, 0, 0, 0, 0, 0, 0};
	int lineState4[9] = {0, 0, 0, 0, 0, 1, 0, 0, 0};
	int lineState5[9] = {0, 0, 0, 0, 0, 0, 0, 0, 1};
	int lineState6[9] = {0, 0, 0, 0, 0, 0, 0, 1, 0};
	int lineState7[9] = {0, 0, 0, 0, 0, 0, 1, 0, 0};
	int lineState8[9] = {0, 0, 0, 1, 0, 0, 0, 0, 0};
	
	for(int i=0; i<3; i++){
		if(i == 0){
			int plan[3] = {1,0,0};
			layerWrite(plan);
		}
			
		if(i == 1){
			int plan[3] = {0,1,0};
			layerWrite(plan);
		}
			
		if(i == 2){
			int plan[3] = {0,0,1};
			layerWrite(plan);
		}
			
		lineWrite(lineState1);delay(tempo);
		lineWrite(lineState2);delay(tempo);
		lineWrite(lineState3);delay(tempo);
		lineWrite(lineState4);delay(tempo);
		lineWrite(lineState5);delay(tempo);
		lineWrite(lineState6);delay(tempo);
		lineWrite(lineState7);delay(tempo);
		lineWrite(lineState8);delay(tempo);
	}
}

/**
 * @fn			cubeFace1On
 * @brief		Allumer la face numero 1 du cube.
 * @param[in]	tempo temps d'allumage de la face 1 du cube.
 */
void cubeFace1On(long tempo){
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0}; 
	layerWrite(plan);
	lineWrite(lineState);
	delay(tempo);
}

/**
 * @fn			cubeFace2On
 * @brief		Allumer la face numero 2 du cube.
 * @param[in]	tempo temps d'allumage de la face 2 du cube.
 */
void cubeFace2On(long tempo){
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState[9] = {1, 0, 0, 1, 0, 0, 1, 0, 0}; 
	layerWrite(plan);
	lineWrite(lineState);
	delay(tempo);
}

/**
 * @fn			cubeFace3On
 * @brief		Allumer la face numero 3 du cube.
 * @param[in]	tempo temps d'allumage de la face 3 du cube.
 */
void cubeFace3On(long tempo){
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState[9] = {0, 0, 0, 0, 0, 0, 1, 1, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
	delay(tempo);
}

/**
 * @fn		cubeFace4On
 * @brief	Allumer la face numero 4 du cube.
 */
void cubeFace4On(long tempo){
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState[9] = {0, 0, 1, 0, 0, 1, 0, 0, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
	delay(tempo);
}
	
/**
 * @fn			cubeAllFaceOn
 * @brief		Allumer toutes les faces du cube.
 * @param[in]	tempo temps d'attente entre allumage de chaque face.
 */
void cubeAllFaceOn(long tempo){
	cubeFace1On(tempo);
	cubeFace2On(tempo);
	cubeFace3On(tempo);
	cubeFace4On(tempo);
}

/**
 * @fn			testCubeFace
 * @brief		Allumer les face de facon circulaire
 * @param[in]	tempo temps entre l'allumage de chaque face du cube.
 */
void testCubeFace(long tempo){
	cubeFace1On(tempo);
	cubeFace2On(tempo);
	cubeFace3On(tempo);
	cubeFace4On(tempo);
}

/**
 * @fn			rotation
 * @brief		Faire une demonstareation d'alumage circulaire.
 * @param[in]	tempo temps d'allumage entre les LEDs des plans du cube.
 */
void rotation(long tempo){
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	int lineState2[9] = {0, 0, 0, 1, 1, 1, 0, 0, 0};
	int lineState3[9] = {0, 0, 1, 0, 1, 0, 1, 0, 0};
	int lineState4[9] = {0, 1, 0, 0, 1, 0, 0, 1, 0};
	
	layerWrite(plan);
	lineWrite(lineState1);delay(tempo);
	lineWrite(lineState2);delay(tempo);
	lineWrite(lineState3);delay(tempo);
	lineWrite(lineState4);delay(tempo);
}

/**
 * @fn			effect
 * @brief		Effet d'allumage du bas vers le haut et vis vers ca.
 * @param[in]	tempo temps  entre les transition de niveaux
 * @param[in]	nbr nobre de fois que l'on veut voir l'effet
 */
void effect(long tempo, char nbr){
	for(int i =0; i<nbr; i++){
		cubeTopOn(tempo);
		cubeMidleOn(tempo);
		cubeBottomOn(tempo);
		cubeMidleOn(tempo);
	}
}
