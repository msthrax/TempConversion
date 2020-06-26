#ifndef __TEMPCONVERSION_H
#define __TEMPCONVERSION_H

typedef enum {
	TemperatureUnit_Celcius 	 = 0,
	TemperatureUnit_Fahrenheit = 1,
	TemperatureUnit_Kelvin 		 = 2,
	TemperatureUnit_Rankine    = 3
}TemperatureUnitTypedef;

/*
Fahrenheit	[°F] = [°C]  × 9/5     + 32           	[°C]   = ([°F] - 32) × ?5/9
Kelvin			[K]  = [°C]  + 273.15                   [°C]         = [K] - 273.15
Rankine			[°R] = ([°C] + 273.15) × ?9/5           [°C] = ([°R] - 491.67) × ?5/9
*/
float ConvertFromCelcius(float value, TemperatureUnitTypedef destinationType);

/*
Celsius	[°C] = ([°F] - 32)     × 5/9	[°F] = [°C] × 9/5 + 32
Kelvin	[K]  = ([°F] + 459.67) × 5/9	[°F] = [K]  × 9/5 - 459.67
Rankine	[°R] = [°F]  + 459.67	        [°F] = [°R] - 459.67
*/
float ConvertFromFahrenheit(float value, TemperatureUnitTypedef destinationType);

/*
Celsius			[°C] = [K] - 273.15						[K] = [°C] + 273.15
Fahrenheit	[°F] = [K] × 9/5 - 459.67			[K] = ([°F] + 459.67) × ?5/9
Rankine			[°R] = [K] × 9/5							[K] = [°R] × ?5/9
*/
float ConvertFromKelvin(float value, TemperatureUnitTypedef destinationType);

/*
Celsius			[°C] = ([°R] - 491.67) × 5/9			[°R] = ([°C] + 273.15) × 9/5
Fahrenheit	[°F] = [°R] - 459.67							[°R] = [°F] + 459.67
Kelvin			[K]  = [°R] × 5/9									[°R] = [K] × 9/5
*/
float ConvertFromRankine(float value, TemperatureUnitTypedef destinationType);

float Temperature_Convert(float val, TemperatureUnitTypedef SourceType, TemperatureUnitTypedef DestinationType);

#endif /* __TEMPCONVERSION_H */
