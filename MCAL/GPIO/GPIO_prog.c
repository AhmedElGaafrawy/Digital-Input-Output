/*
 * GPIO_prog.c
 *
 *  Created on   : Jan 27, 2021
 *  Version        : 1.0.5
 *  Author         : Ahmed El-Gaafarwy
 */
/*****************************************************************************/
/**                                                                         **/
/**                                                                         **/
/**************              Libraries Inclusion                **************/
/**                                                                         **/
/**                                                                         **/
/*****************************************************************************/
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/BIT_MATH.h"
#include "../../LIBRARIES/errorStates.h"
#include "../../LIBRARIES/AVR_REG.h"
/*****************************************************************************/



/*****************************************************************************/
/**                                                                         **/
/**                                                                         **/
/**************           GPIO Libraries Inclusion              **************/
/**                                                                         **/
/**                                                                         **/
/*****************************************************************************/
#include "GPIO_config.h"
#include "GPIO_priv.h"
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuInit.                                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pointer to GPIO_strPins_Info struct.                  **/
/** Functionality   : Setting the initial direction and Value of GPIO pins. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuInit(GPIO_strPins_Info * Copy_Pstrnit)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	uint_8 Local_u8Iterator=0;

	uint_8 Local_u8PinID =0;
	/*		Set Output and High to selected Pins */
	if (Copy_Pstrnit -> GPIO_u32OutputHighPins != GPIO_NO_PINS)
	{
		for (Local_u8Iterator=0; Local_u8Iterator <GPIO_THIRTY_TWO; Local_u8Iterator++)
		{
			Local_u8PinID=( (Copy_Pstrnit -> GPIO_u32OutputHighPins>>Local_u8Iterator) &GPIO_ONE);
			if (Local_u8PinID)
			{
				if (Local_u8Iterator>=GPIO_ZERO && Local_u8Iterator <GPIO_EIGHT)
				{
					DIO->DDRA  |= (GPIO_ONE<<Local_u8Iterator);
					DIO->PORTA |= (GPIO_ONE<<Local_u8Iterator);
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_EIGHT && Local_u8Iterator <GPIO_SIXTEEN)
				{
					DIO->DDRB  |= (GPIO_ONE<<(Local_u8Iterator-GPIO_EIGHT));
					DIO->PORTB |= (GPIO_ONE<<(Local_u8Iterator-GPIO_EIGHT));
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_SIXTEEN && Local_u8Iterator <GPIO_TWENTY_FOUR)
				{
					DIO->DDRC  |= (GPIO_ONE<<(Local_u8Iterator-GPIO_SIXTEEN));
					DIO->PORTC |= (GPIO_ONE<<(Local_u8Iterator-GPIO_SIXTEEN));
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_TWENTY_FOUR && Local_u8Iterator <GPIO_THIRTY_TWO)
				{
					DIO->DDRD  |= (GPIO_ONE<<(Local_u8Iterator-GPIO_TWENTY_FOUR));
					DIO->PORTD |= (GPIO_ONE<<(Local_u8Iterator-GPIO_TWENTY_FOUR));
					Local_enuErrorState = ES_OK;
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;
				}
			}
		}
	}

	Local_u8PinID =0;
	/*		Set Output and Low to selected Pins */
	if (Copy_Pstrnit -> GPIO_u32OutputLowPins != GPIO_NO_PINS)
	{
		for (Local_u8Iterator=0; Local_u8Iterator <GPIO_THIRTY_TWO; Local_u8Iterator++)
		{
			Local_u8PinID=( (Copy_Pstrnit -> GPIO_u32OutputLowPins>>Local_u8Iterator) &GPIO_ONE);
			if (Local_u8PinID)
			{
				if (Local_u8Iterator>=GPIO_ZERO && Local_u8Iterator <GPIO_EIGHT)
				{
					DIO->DDRA  |= (GPIO_ONE<<Local_u8Iterator);
					DIO->PORTA &=~(GPIO_ONE<<Local_u8Iterator);
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_EIGHT && Local_u8Iterator <GPIO_SIXTEEN)
				{
					DIO->DDRB  |= (GPIO_ONE<<(Local_u8Iterator-GPIO_EIGHT));
					DIO->PORTB &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_EIGHT));
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_SIXTEEN && Local_u8Iterator <GPIO_TWENTY_FOUR)
				{
					DIO->DDRC  |= (GPIO_ONE<<(Local_u8Iterator-GPIO_SIXTEEN));
					DIO->PORTC &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_SIXTEEN));
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_TWENTY_FOUR && Local_u8Iterator <GPIO_THIRTY_TWO)
				{
					DIO->DDRD  |= (GPIO_ONE<<(Local_u8Iterator-GPIO_TWENTY_FOUR));
					DIO->PORTD &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_TWENTY_FOUR));
					Local_enuErrorState = ES_OK;
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;
				}
			}
		}
	}


	Local_u8PinID =0;
	/*		Set Input and Pull-up to selected Pins */
	if (Copy_Pstrnit -> GPIO_u32InputPullupPins != GPIO_NO_PINS)
	{
		for (Local_u8Iterator=0; Local_u8Iterator <GPIO_THIRTY_TWO; Local_u8Iterator++)
		{
			Local_u8PinID=( (Copy_Pstrnit -> GPIO_u32InputPullupPins>>Local_u8Iterator) &GPIO_ONE);
			if (Local_u8PinID)
			{
				if (Local_u8Iterator>=GPIO_ZERO && Local_u8Iterator <GPIO_EIGHT)
				{
					DIO->DDRA  &=~(GPIO_ONE<<Local_u8Iterator);
					DIO->PORTA |= (GPIO_ONE<<Local_u8Iterator);
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_EIGHT && Local_u8Iterator <GPIO_SIXTEEN)
				{
					DIO->DDRB  &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_EIGHT));
					DIO->PORTB |= (GPIO_ONE<<(Local_u8Iterator-GPIO_EIGHT));
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_SIXTEEN && Local_u8Iterator <GPIO_TWENTY_FOUR)
				{
					DIO->DDRC  &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_SIXTEEN));
					DIO->PORTC |= (GPIO_ONE<<(Local_u8Iterator-GPIO_SIXTEEN));
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_TWENTY_FOUR && Local_u8Iterator <GPIO_THIRTY_TWO)
				{
					DIO->DDRD  &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_TWENTY_FOUR));
					DIO->PORTD |= (GPIO_ONE<<(Local_u8Iterator-GPIO_TWENTY_FOUR));
					Local_enuErrorState = ES_OK;
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;
				}
			}
		}
	}


	Local_u8PinID =0;
	/*		Set Input and Float to selected Pins */
	if (Copy_Pstrnit -> GPIO_u32InputFloatPins != GPIO_NO_PINS)
	{
		for (Local_u8Iterator=0; Local_u8Iterator <GPIO_THIRTY_TWO; Local_u8Iterator++)
		{
			Local_u8PinID=( (Copy_Pstrnit -> GPIO_u32InputFloatPins>>Local_u8Iterator) &GPIO_ONE);
			if (Local_u8PinID)
			{
				if (Local_u8Iterator>=GPIO_ZERO && Local_u8Iterator <GPIO_EIGHT)
				{
					DIO->DDRA  &=~(GPIO_ONE<<Local_u8Iterator);
					DIO->PORTA &=~(GPIO_ONE<<Local_u8Iterator);
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_EIGHT && Local_u8Iterator <GPIO_SIXTEEN)
				{
					DIO->DDRB  &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_EIGHT));
					DIO->PORTB &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_EIGHT));
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_SIXTEEN && Local_u8Iterator <GPIO_TWENTY_FOUR)
				{
					DIO->DDRC  &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_SIXTEEN));
					DIO->PORTC &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_SIXTEEN));
					Local_enuErrorState = ES_OK;
				}
				else if (Local_u8Iterator>=GPIO_TWENTY_FOUR && Local_u8Iterator <GPIO_THIRTY_TWO)
				{
					DIO->DDRD  &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_TWENTY_FOUR));
					DIO->PORTD &=~(GPIO_ONE<<(Local_u8Iterator-GPIO_TWENTY_FOUR));
					Local_enuErrorState = ES_OK;
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;
				}
			}
		}
	}


	return Local_enuErrorState;
}
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
ERROR_STATES MGPIO_enuSetPinDirection(uint_8 Copy_u8PinID, uint_8 Copy_u8PinDirection)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8PinID>=GPIO_ZERO && Copy_u8PinID <GPIO_THIRTY_TWO
	   && Copy_u8PinDirection>=GPIO_GROUP_PIN_INPUT && Copy_u8PinDirection<=GPIO_GROUP_PIN_OUTPUT)
	{
		if (Copy_u8PinID>=GPIO_ZERO && Copy_u8PinID <GPIO_EIGHT)
		{
			/*		Clear then set to Direct assign the value into DDRA*/
			DIO->DDRA  &=~(GPIO_ONE           <<Copy_u8PinID);
			DIO->DDRA  |= (Copy_u8PinDirection<<Copy_u8PinID);
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_EIGHT && Copy_u8PinID <GPIO_SIXTEEN)
		{
			/*		Clear then set to Direct assign the value into DDRB		*/
			DIO->DDRB  &=~(GPIO_ONE           <<(Copy_u8PinID-GPIO_EIGHT));
			DIO->DDRB  |= (Copy_u8PinDirection<<(Copy_u8PinID-GPIO_EIGHT));
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_SIXTEEN && Copy_u8PinID <GPIO_TWENTY_FOUR)
		{
			/*		Clear then set to Direct assign the value into DDRC		*/
			DIO->DDRC  &=~(GPIO_ONE           <<(Copy_u8PinID-GPIO_SIXTEEN));
			DIO->DDRC  |= (Copy_u8PinDirection<<(Copy_u8PinID-GPIO_SIXTEEN));
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_TWENTY_FOUR && Copy_u8PinID <GPIO_THIRTY_TWO)
		{
			/*		Clear then set to Direct assign the value into DDRD		*/
			DIO->DDRD  &=~(GPIO_ONE           <<(Copy_u8PinID-GPIO_TWENTY_FOUR));
			DIO->DDRD  |= (Copy_u8PinDirection<<(Copy_u8PinID-GPIO_TWENTY_FOUR));
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}
	return Local_enuErrorState;
}
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
ERROR_STATES MGPIO_enuSetPinValue(uint_8 Copy_u8PinID, uint_8 Copy_u8PinValue)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8PinID>=GPIO_ZERO && Copy_u8PinID <GPIO_THIRTY_TWO
	   && Copy_u8PinValue>=GPIO_GROUP_PIN_LOW && Copy_u8PinValue<=GPIO_GROUP_PIN_HIGH)
	{
		if (Copy_u8PinID>=GPIO_ZERO && Copy_u8PinID <GPIO_EIGHT)
		{
			/*		Clear then set to Direct assign the value into DDRA*/
			DIO->PORTA  &=~(GPIO_ONE       <<Copy_u8PinID);
			DIO->PORTA  |= (Copy_u8PinValue<<Copy_u8PinID);
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_EIGHT && Copy_u8PinID <GPIO_SIXTEEN)
		{
			/*		Clear then set to Direct assign the value into DDRB		*/
			DIO->PORTB  &=~(GPIO_ONE       <<(Copy_u8PinID-GPIO_EIGHT));
			DIO->PORTB  |= (Copy_u8PinValue<<(Copy_u8PinID-GPIO_EIGHT));
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_SIXTEEN && Copy_u8PinID <GPIO_TWENTY_FOUR)
		{
			/*		Clear then set to Direct assign the value into DDRC		*/
			DIO->PORTC  &=~(GPIO_ONE       <<(Copy_u8PinID-GPIO_SIXTEEN));
			DIO->PORTC  |= (Copy_u8PinValue<<(Copy_u8PinID-GPIO_SIXTEEN));
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_TWENTY_FOUR && Copy_u8PinID <GPIO_THIRTY_TWO)
		{
			/*		Clear then set to Direct assign the value into DDRD		*/
			DIO->PORTD  &=~(GPIO_ONE       <<(Copy_u8PinID-GPIO_TWENTY_FOUR));
			DIO->PORTD  |= (Copy_u8PinValue<<(Copy_u8PinID-GPIO_TWENTY_FOUR));
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}

	return Local_enuErrorState;
}
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
ERROR_STATES MGPIO_enuTogglePinValue(uint_8 Copy_u8PinID)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8PinID>=GPIO_ZERO && Copy_u8PinID <GPIO_THIRTY_TWO)
	{
		if (Copy_u8PinID>=GPIO_ZERO && Copy_u8PinID <GPIO_EIGHT)
		{
			/*		Clear then set to Direct assign the value into DDRA*/
			DIO->PORTA  ^= (GPIO_ONE<<Copy_u8PinID);
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_EIGHT && Copy_u8PinID <GPIO_SIXTEEN)
		{
			/*		Clear then set to Direct assign the value into DDRB		*/
			DIO->PORTB  ^= (GPIO_ONE<<(Copy_u8PinID-GPIO_EIGHT));
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_SIXTEEN && Copy_u8PinID <GPIO_TWENTY_FOUR)
		{
			/*		Clear then set to Direct assign the value into DDRC		*/
			DIO->PORTC  ^= (GPIO_ONE<<(Copy_u8PinID-GPIO_SIXTEEN));
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_TWENTY_FOUR && Copy_u8PinID <GPIO_THIRTY_TWO)
		{
			/*		Clear then set to Direct assign the value into DDRD		*/
			DIO->PORTD  ^= (GPIO_ONE<<(Copy_u8PinID-GPIO_TWENTY_FOUR));
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}

	return Local_enuErrorState;
}
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
ERROR_STATES MGPIO_enuGetPinValue(uint_8 Copy_u8PinID, uint_8 * Copy_Pu8PinValue)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8PinID>=GPIO_ZERO && Copy_u8PinID <GPIO_THIRTY_TWO && Copy_Pu8PinValue != NULL)
	{
		if (Copy_u8PinID>=GPIO_ZERO && Copy_u8PinID <GPIO_EIGHT)
		{
			/*		Clear then set to Direct assign the value into DDRA*/
			*Copy_Pu8PinValue= ((DIO->PINA >> Copy_u8PinID) & GPIO_ONE);
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_EIGHT && Copy_u8PinID <GPIO_SIXTEEN)
		{
			/*		Clear then set to Direct assign the value into DDRB		*/
			*Copy_Pu8PinValue= ((DIO->PINB >> (Copy_u8PinID-GPIO_EIGHT)) & GPIO_ONE);
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_SIXTEEN && Copy_u8PinID <GPIO_TWENTY_FOUR)
		{
			/*		Clear then set to Direct assign the value into DDRC		*/
			*Copy_Pu8PinValue= ((DIO->PINC >> (Copy_u8PinID-GPIO_SIXTEEN)) & GPIO_ONE);
			Local_enuErrorState = ES_OK;
		}
		else if (Copy_u8PinID>=GPIO_TWENTY_FOUR && Copy_u8PinID <GPIO_THIRTY_TWO)
		{
			/*		Clear then set to Direct assign the value into DDRD		*/
			*Copy_Pu8PinValue= ((DIO->PIND >> (Copy_u8PinID-GPIO_TWENTY_FOUR)) & GPIO_ONE);
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}

	return Local_enuErrorState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


