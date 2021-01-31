/*
 * GPIO_int.h
 *
 *  Created on   : Jan 27, 2021
 *  Version        : 1.0.0
 *  Author         : Ahmed El-Gaafarwy
 */


#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_



#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/BIT_MATH.h"
#include "../../LIBRARIES/errorStates.h"
#include "../../LIBRARIES/AVR_REG.h"
#include "GPIO_priv.h"

extern GPIO_strPins_Info GPIO_strPinsStates;

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuInit.                                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pointer to GPIO_strPins_Info struct.                  **/
/** Functionality   : Setting the initial direction and Value of GPIO pins. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuInit(GPIO_strPins_Info * Copy_Pstrnit);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuSetPinDirection.                             **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pin Number and its Direction(Input or Output).        **/
/** Functionality   : Setting the direction of specific pin at run time.    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuSetPinDirection(uint_8 Copy_u8PinID, uint_8 Copy_u8PinDirection);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuSetPinValue.                                 **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pin number and its Value(High or Low).                **/
/** Functionality   : Setting the value of specific pin at run time.        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuSetPinValue(uint_8 Copy_u8PinID, uint_8 Copy_u8PinValue);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuTogglePinValue.                              **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pin number.                                           **/
/** Functionality   : Toggling the value of specific pin at run time.       **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuTogglePinValue(uint_8 Copy_u8PinID);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuGetPinValue.                                 **/
/** Return Type     : ERROR_STATES enum and The the pin value as a pointer. **/
/** Arguments       : Pin number, pointer to var will contain the pin value.**/
/** Functionality   : Getting the value of specific pin at run time.        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuGetPinValue(uint_8 Copy_u8PinID, uint_8 * Copy_Pu8PinValue);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



typedef enum
{
	PIN0,			PIN1,			PIN2,			PIN3,
	PIN4,			PIN5,			PIN6,			PIN7,
	PIN8,			PIN9,			PIN10,			PIN11,
	PIN12,			PIN13,			PIN14,			PIN15,
	PIN16,			PIN17,			PIN18,			PIN19,
	PIN20,			PIN21,			PIN22,			PIN23,
	PIN24,			PIN25,			PIN26,			PIN27,
	PIN28,			PIN29,			PIN30,			PIN31,

	PIN_INPUT=0,			PIN_OUTPUT,
	PIN_LOW=0,				PIN_HIGH,
	PIN_PULLUP=1,
}GPIO_info_enu_ForApp;

#endif /* MCAL_GPIO_GPIO_INT_H_ */
