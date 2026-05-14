/*
**************************
* @file    NTC.cpp
* @brief   Functions for NTC thermistor temperature measurement.
**************************
* @attention
*
* This file contains the temperature measurement
* function for an NTC thermistor using the Beta
* parameter equation.
*
* Date: 13/05/2026
* Author: Luiz Fernando Marquez Arruda
* email : eng.luizarruda@gmail.com
* Project: ATV_1305
* Version: 1.0
**************************
*/

#include "NTC.h"

/*
**********************
* @name  NTC
* @brief This function performs the temperature
*        measurement of an NTC thermistor using
*        the ADC conversion and Beta equation.
*
*********************
* @input:   pin   - analog input pin connected to
*                   the NTC voltage divider
*           Beta  - Beta coefficient of the NTC
*           R0    - nominal resistance of the NTC
*                   at reference temperature
*           Rd    - fixed resistor value used in
*                   the voltage divider
*           T0    - reference temperature in Kelvin
*           vmax  - maximum ADC reference voltage
*
* @return:  measured temperature in Celsius
*
*/
float NTC(int pin,int Beta, float R0, float Rd, float T0, float vmax){

    int adc = analogRead(pin);

    // ADC to voltage conversion
    float V = adc * vmax / 1023.0;

    // Prevent division by zero
    if(V <= 0.0 || V >= vmax)
        return -999.0;

    // Calculate NTC resistance
    float R = (V * Rd) / (vmax - V);

    // Beta equation
    float Tk =

        1.0 /

        (

            (1.0 / T0) +

            (1.0 / Beta) * log(R / R0)

        );

    // Kelvin to Celsius conversion
    float Tc = Tk - 273.15;

    return Tc;
}
