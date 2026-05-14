/*
**************************
* @file    Encoder.cpp
* @brief   Functions for incremental rotary encoder reading.
**************************
* @attention
*
* This file contains the initialization and reading
* functions for a quadrature incremental encoder.
*
* Date: 13/05/2026
* Author: Felipe Schinestzki
* email : felipe.schinestzki@uniavan.edu.br
* Project: ATV_1305
* Version: 1.0
**************************
*/

#include <Arduino.h>

/*
**********************
* @name  encoder_init
* @brief This function performs the initial confi-
*        guration of the pins used by the incre-
*        mental rotary encoder.
*
*********************
* @input:   ENC_A - encoder channel A pin
*           ENC_B - encoder channel B pin
*
* @return:  no return
*
*/
void encoder_init(int ENC_A,int ENC_B);

/*
**********************
* @name  encoder
* @brief This function reads encoder channels A
*        and B in order to determine the rotation
*        direction and update the encoder posi-
*        tion count.
*
*********************
* @input:   ENC_A - encoder channel A pin
*           ENC_B - encoder channel B pin
*
* @return:  incremental encoder position
*
*/
int encoder(int ENC_A,int ENC_B);
