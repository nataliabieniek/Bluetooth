/*
 * bluetooth.c
 *
 *  Created on: 4 Dec 2022
 *      Author: natal
 */

#include "bluetooth.h"
#include <string.h>

void bluetooth_sendStartMessage()
{
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
	const char message[] = "Menu komend:\r\n1 - zmiana koloru\r\n2 - zmiana wzoru\r\n";
	HAL_UART_Transmit(&huart2, message, strlen(message), HAL_MAX_DELAY);
}

void bluetooth_sendNotKnowMessage()
{
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
	const char message[] = "Niepoprawnie wprowadzona komenda!\r\n";
	HAL_UART_Transmit(&huart2, message, strlen(message), HAL_MAX_DELAY);

}
uint8_t bluetooth_reciveBasicMenu()
{
	uint8_t recivedMenu=0;
	while(1)
	{
		HAL_UART_Receive_IT(&huart2, recivedMenu, 1);
		if((recivedMenu!= 1) && (recivedMenu!= 2))
		{
			bluetooth_sendNotKnowMessage();
			HAL_Delay(5000);
		}
		else
			return recivedMenu;
	}
}
void bluetooth_reciveExpandedMenu_Coulors(uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t Received[10];


}
uint8_t bluetooth_reciveExpandedMenu_Images()
{
	uint8_t recivedMenu=0;
	HAL_UART_Receive_IT(&huart2, recivedMenu, 1);
	if (recivedMenu == 65)
	{
		const char message[] = "\t[LED] slonce wyswietlenie\r\n";
		HAL_UART_Transmit(&huart2, message, strlen(message), HAL_MAX_DELAY);
	}
	else if (recivedMenu == 66)
	{
		const char message[] = "\t[LED] kwiatek wyswietlenie\r\n";
		HAL_UART_Transmit(&huart2, message, strlen(message), HAL_MAX_DELAY);
	}
	else if (recivedMenu == 67)
	{
		const char message[] = "\t[LED] okregi wyswietlenie\r\n";
		HAL_UART_Transmit(&huart2, message, strlen(message), HAL_MAX_DELAY);
	}
	else if((recivedMenu!= 65) && (recivedMenu!= 66) && (recivedMenu!= 67) )
	{
			bluetooth_sendNotKnowMessage();
	}
	return recivedMenu;


}
void bluetooth_sendExpandedMenu(uint8_t menuOption)
{
	const char message1[] = "Podaj kolor uzywajac RGB kodow, czyli np 255 255 255\r\nWartosci oddziel pojedycza spacja\r\n";
	const char message2[] = "Menu wzorow:\r\nA - slonce\r\nB - kwiatek\r\nC - kregi\r\n";
	switch(menuOption)
	{
		case 1:
			HAL_UART_Transmit(&huart2, message1, strlen(message1), HAL_MAX_DELAY);
			break;
		case 2:
			HAL_UART_Transmit(&huart2, message2, strlen(message2), HAL_MAX_DELAY);
			break;
		case 3:
			bluetooth_sendStartMessage();
			break;
		default:
			HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 1);
			break;
	}

}
