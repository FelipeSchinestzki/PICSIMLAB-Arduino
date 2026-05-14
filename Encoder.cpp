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

#include "Encoder.h"

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
void encoder_init(int ENC_A,int ENC_B){
  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);
}

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
int encoder(int ENC_A,int ENC_B){

  int MSB = digitalRead(ENC_A);
  int LSB = digitalRead(ENC_B);

  static int lastEncoded = 0;
  static int encoderPos = 0;

  int encoded = (MSB << 1) | LSB;
  int sum = (lastEncoded << 2) | encoded;

  if (sum == 0b1101 || sum == 0b0100 ||
      sum == 0b0010 || sum == 0b1011)
    encoderPos++;

  if (sum == 0b1110 || sum == 0b0111 ||
      sum == 0b0001 || sum == 0b1000)
    encoderPos--;

  lastEncoded = encoded;

  return encoderPos;
}
