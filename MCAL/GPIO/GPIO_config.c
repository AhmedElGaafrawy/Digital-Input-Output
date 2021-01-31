/*
 * GPIO_config.h
 *
 *  Created on: Jan 27, 2021
 *      Author: hp
 */

#ifndef MCAL_GPIO_GPIO_CONFIG_C_
#define MCAL_GPIO_GPIO_CONFIG_C_


#include "../../LIBRARIES/stdTypes.h"

#include "GPIO_priv.h"
#include "GPIO_config.h"



/********************************************************************************************/
/****                                 !!!!!Attention!!!!!                                ****/
/****                                                                                    ****/
/****       You must not repeat pin written in group into another To avoid Confusion     ****/
/********************************************************************************************/





/********************************************************************************************/
/********************************************************************************************/
/****                            Write Here Your Pins States                             ****/
/****                             As the following Example:                              ****/
/**** GPIO_strPins_Info GPIO_strPinsStates=
          {
              GPIO_PIN0  | GPIO_PIN10 | ... for output high pins   ,
              GPIO_PIN9  | GPIO_PIN17 | ... for output low pins    ,
              GPIO_PIN13 | GPIO_PIN3  | ... for input pull-up pins ,
              GPIO_PIN21 | GPIO_PIN29 | ... for input float pins
          }                                                                              ****/
/****                                 <<<<  NOTE  >>>>                                   ****/
/****    if you do not want to add any pin to any category, you can put its value By:    ****/
/****                                                                                    ****/
/****                                   GPIO_NO_PINS                                     ****/
/********************************************************************************************/
/********************************************************************************************/

GPIO_strPins_Info GPIO_strPinsStates=
	{
		GPIO_PIN0  | GPIO_PIN6 | GPIO_PIN31 | GPIO_PIN25 ,   /* for output high pins   */
	    GPIO_PIN8  | GPIO_PIN10,   /* for output low pins    */
	    GPIO_PIN9  | GPIO_PIN17,   /* for input pull-up pins */
	    GPIO_NO_PINS               /* for input float pins   */

	};

/********************************************************************************************/


#endif /* MCAL_GPIO_GPIO_CONFIG_C_ */
