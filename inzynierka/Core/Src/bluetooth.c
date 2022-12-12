/*
 * bluetooth.c
 *
 *  Created on: 4 Dec 2022
 *      Author: natal
 */

#include "bluetooth.h"
#include <string.h>

uint8_t receivedColours[6];
uint8_t receivedBasicMenu;
uint8_t receivedImage;

void bluetooth_sendStartMessage()
{
	HAL_Delay(100);
	printf("Menu komend:\r\n1 - zmiana koloru\r\n2 - zmiana wzoru\r\n");

}

void bluetooth_sendNotKnowMessage()
{
	printf("Niepoprawnie wprowadzona komenda!\r\n");


}
void bluetooth_reciveBasicMenu()
{
	HAL_UART_Receive_IT(&huart2, receivedBasicMenu, 1);

}
void bluetooth_reciveExpandedMenu_Coulors()
{
	HAL_UART_Receive_IT(&huart2, receivedColours, 6);

}
void bluetooth_reciveExpandedMenu_Images()
{

	HAL_UART_Receive_IT(&huart2, receivedImage, 1);


}
void bluetooth_sendExpandedMenu(uint8_t menuOption)
{
	switch(menuOption)
	{
		case 1:
			printf("Podaj kolor uzywajac RGB kodow, za pomoca wartosci hex\r\nWartosci nie oddzielaj pojedycza spacja np FF99CC\r\n");
			break;
		case 2:
			printf("Menu wzorow:\r\nA - slonce\r\nB - kwiatek\r\nC - kregi\r\n");
			break;
		case 3:
			bluetooth_sendStartMessage();
			break;
		default:
			break;
	}

}
int __io_putchar(int ch)
{
	if (ch == '\n') {
	    __io_putchar('\r');
	}

    HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    return 1;
}
