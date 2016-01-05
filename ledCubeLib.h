/**
 * @file	cubeLib.ino
 * @brief	Definition des fonctions permettant de tester le Cube a LED3x3x3.
 * @author	Theodore ATEBA
 * @version	1.0.
 * @date	29 Mai 2015
 */

//============================================================================
//	Branchement du Cube a l'Arduino Uno
//============================================================================
#define PLAN0  13
#define PLAN1  12
#define PLAN2  11
#define LINE_0  2
#define LINE_1  3
#define LINE_2  4
#define LINE_3  5
#define LINE_4  6
#define LINE_5  7
#define LINE_6  8
#define LINE_7  9
#define LINE_8  10

//============================================================================
//	Prototypes des fonctions
//============================================================================

/**
 * @fn				cubeOn
 * @brief			Allumer toutes les leds du cube.
 * @param[in]		tempo temps d'allumage du cube.
 */
void cubeOn(long tempo);
	
/**
 * @fn				cubeOff
 * @brief			Eteindre toutes les leds du cube
 * @param[in]		tempo temps d'extinction du cube.
 */
void cubeOff(long tempo);

/**
 * @fn				shadowOn
 * @brief			Allumage aleatoire.
 * @param[in]		tempo temps entre l'allumage de deux LEDs, en milli-seconde
 */
void shadowOn(long tempo);
	
/**
 * @fn				shadowOff
 * @brief			Eteindre aleatoirement les Leds du cube.
 * @param[in]		tempo temps entre l'extinction de deux LEDs, en milli-seconde
 */
	void shadowOff(long tempo);

/**
 * @fn				lineWrite
 * @brief			piloter les Leds des plans du cube qui sont actifs.
 * @param[in]		lineState
 */
void lineWrite( int lineState[9]);

/**
 * @fn				layerWrite
 * @brief			Selection d'un des trois plans du cube.
 * @param[in]		lineState
 */
void layerWrite(int layerState[3]);

/**
 * @fn				cubeTopOff
 * @brief			Eteindre le plan 1 du cube.
 * @param[in]		tempo temps d'extinction du dessus du cube.
 */
void cubeTopOff(long tempo);
	
/**
 * @fn				cubeTopOn
 * @brief			Allumer le plan 1 du cube.
 * @param[in]		tempo temps d'allumage du dessus du cube.
 */
void cubeTopOn(long tempo);
	
/**
* @fn				cubeMidleOff
* @brief			Eteindre le plan 2 du cube.
* @param[in]		tempo temps d'extinction du plan 2 du cube.
*/
void cubeMidleOff(long tempo);
	
/**
 * @fn				cubeMidleOn
 * @brief			Allumer le Plan 2 du cube.
 * @param[in]		tempo temps d'allumage du plan 2 du cube.
 */
void cubeMidleOn(long tempo);

/**
 * @fn				cubeBottomOff
 * @brief			Eteindre le plan 3 du cube.
 * @param[in]		tempo temps d'extinction du plan 3 du cube.	
 */
void cubeBottomOff(long tempo);
	
/**
 * @fn				cubeBottomOn
 * @brief			Allumer le plan 3 du cube.
 * @param[in]		tempo temps d'allumage du plan 3 du cube.
 */
void cubeBottomOn(long tempo);
	
/**
 * @fn				cubeBlink
 * @brief			Faire clignoter le cube de leds.
 * @param[in]		tempo le temps de clignotement en milli seconde
 * @param[in]		blinkNbr le nombre de clignotement souhaite
 */
void cubeBlink(long tempo, char blinkNbr);

/**
 * @fn				cubeCircularDemo
 * @brief			Faire une demonstareation d'alumage circulaire.
 * @param[in]		tempo temps de l'effet de rotation.
 */
void cubeCircularDemo(long tempo);

/**
 * @fn				cubeFace1On
 * @brief			Allumer la face numero 1 du cube.
 * @param[in]		tempo temps d'allumage de la face 1 du cube.
 */
void cubeFace1On(long tempo);

/**
 * @fn				cubeFace2On
 * @brief			Allumer la face numero 2 du cube.
 * @param[in]		tempo temps d'allumage de la face 2 du cube.
 */
void cubeFace2On(long tempo);

/**
 * @fn				cubeFace3On
 * @brief			Allumer la face numero 3 du cube.
 * @param[in]		tempo temps d'allumage de la face 3 du cube.
 */
void cubeFace3On(long tempo);

/**
 * @fn				cubeFace4On
 * @brief			Allumer la face numero 4 du cube.
 */
void cubeFace4On(long tempo);

/**
 * @fn				cubeAllFaceOn
 * @brief			Allumer toutes les faces du cube.
 * @param[in]		tempo temps d'attente entre allumage de chaque face.
 */
void cubeAllFaceOn(long tempo);

/**
 * @fn				testCubeFace
 * @brief			Allumer les face de facon circulaire
 * @param[in]		tempo temps entre l'allumage de chaque face du cube.
 */
void testCubeFace(long tempo);

/**
 * @fn				rotation
 * @brief			Faire une demonstareation d'alumage circulaire.
 * @param[in]		tempo temps d'allumage entre les LEDs des plans du cube.
 */
void rotation(long tempo);

/**
 * @fn				effect
 * @brief			Effet d'allumage du bas vers le haut et vis vers ca.
 * @param[in]		tempo temps  entre les transition de niveaux
 * @param[in]		nbr nobre de fois que l'on veut voir l'effet
 */
void effect(long tempo, char nbr);
