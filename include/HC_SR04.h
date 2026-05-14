/*
**************************
* @file    HC_SR04.cpp
* @brief   Functions for HC-SR04 ultrasonic sensor.
**************************
* @attention
*
* This file contains the initialization and distance
* measurement functions for the HC-SR04 ultrasonic
* sensor module.
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
* @name  HC_SR04_init
* @brief This function performs the initial confi-
*        guration of the trigger and echo pins used
*        by the HC-SR04 ultrasonic sensor.
*
*********************
* @input:   TRIG - trigger pin of the HC-SR04
*           ECHO - echo pin of the HC-SR04
*
* @return:  no return
*
*/
void HC_SR04_init(int TRIG, int ECHO);

/*
**********************
* @name  HC_SR04
* @brief This function performs the distance mea-
*        surement using the HC-SR04 ultrasonic
*        sensor by calculating the propagation
*        time of the ultrasonic pulse.
*
*********************
* @input:   TRIG - trigger pin of the HC-SR04
*           ECHO - echo pin of the HC-SR04
*
* @return:  measured distance in centimeters
*
*/
float HC_SR04(int TRIG, int ECHO);
