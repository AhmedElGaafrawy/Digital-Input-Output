/*
 * main.c
 *
 *  Created on   : Jan 27, 2021
 *  Version        : 1.0.0
 *  Author         : Ahmed El-Gaafarwy
 */

#include "../MCAL/GPIO/GPIO_int.h"


#include <util/delay.h>


int
main(void)
{
	MGPIO_enuInit(&GPIO_strPinsStates);
	MGPIO_enuSetPinValue(PIN8,PIN_HIGH);
	MGPIO_enuTogglePinValue(PIN10);
	MGPIO_enuSetPinDirection(PIN9,PIN_OUTPUT);
	MGPIO_enuSetPinValue(PIN9,PIN_HIGH);


	return 0;
}


