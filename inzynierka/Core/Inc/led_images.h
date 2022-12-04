/*
 * led_images.h
 *
 *  Created on: Dec 3, 2022
 *      Author: natal
 */

#ifndef INC_LED_IMAGES_H_
#define INC_LED_IMAGES_H_

#include "main.h"

enum imagesNumbers{
	sun,
	flower,
	cirlces
};

extern UART_HandleTypeDef huart2;

void led_images_changeImageCoulor(uint8_t green, uint8_t red, uint8_t blue);
void led_images_changeLedImage(uint8_t numberImage);
int led_images_checkIfImageExist(uint8_t numberImage);

#endif /* INC_LED_IMAGES_H_ */
