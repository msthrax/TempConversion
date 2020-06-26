/*
Fahrenheit	[°F] = [°C]  × 9/5     + 32           	[°C]   = ([°F] - 32) × ?5/9
Kelvin			[K]  = [°C]  + 273.15                   [°C]         = [K] - 273.15
Rankine			[°R] = ([°C] + 273.15) × ?9/5           [°C] = ([°R] - 491.67) × ?5/9
*/

float ConvertFromCelcius(float value, TemperatureUnitTypedef destinationType) {
	float res = 0 ;
	switch(destinationType)
	{
		case TemperatureUnit_Fahrenheit: {res = value * ((float)9/5) + 32			  ; break; }
		case TemperatureUnit_Kelvin    : {res = value + 273.15F                 ; break; }
		case TemperatureUnit_Rankine   : {res = (value + 273.15F) * ((float)9/5); break; }
		default: {break;}
	}
	return res;
}

/*
Celsius	[°C] = ([°F] - 32)     × 5/9	[°F] = [°C] × 9/5 + 32
Kelvin	[K]  = ([°F] + 459.67) × 5/9	[°F] = [K]  × 9/5 - 459.67
Rankine	[°R] = [°F]  + 459.67	        [°F] = [°R] - 459.67
*/
float ConvertFromFahrenheit(float value, TemperatureUnitTypedef destinationType) {
	float res = 0 ;
	switch(destinationType)
	{
		case TemperatureUnit_Celcius	 : {res = (value - 32) * ((float)5/9)     ; break; }
		case TemperatureUnit_Kelvin    : {res = (value + 459.67F) * ((float)5/9);	break; }
		case TemperatureUnit_Rankine   : {res = value + 459.67F                 ; break; }
		default: {break;}
	}
	return res;
}

/*
Celsius			[°C] = [K] - 273.15						[K] = [°C] + 273.15
Fahrenheit	[°F] = [K] × 9/5 - 459.67			[K] = ([°F] + 459.67) × ?5/9
Rankine			[°R] = [K] × 9/5							[K] = [°R] × ?5/9
*/

float ConvertFromKelvin(float value, TemperatureUnitTypedef destinationType) {
	float res = 0 ;
	switch(destinationType)
	{
		case TemperatureUnit_Celcius	 : {res = value - 273.15F	              ; break; }
		case TemperatureUnit_Fahrenheit: {res = value * (float)(9/5) - 459.67F;	break; }
		case TemperatureUnit_Rankine   : {res = value * ((float)9/5)          ; break; }
		default: {break;}
	}
	return res;
}

/*
Celsius			[°C] = ([°R] - 491.67) × 5/9			[°R] = ([°C] + 273.15) × 9/5
Fahrenheit	[°F] = [°R] - 459.67							[°R] = [°F] + 459.67
Kelvin			[K]  = [°R] × 5/9									[°R] = [K] × 9/5
*/

float ConvertFromRankine(float value, TemperatureUnitTypedef destinationType) {
	float res = 0 ;
	switch(destinationType)
	{
		case TemperatureUnit_Celcius	 : {res = (value - 491.67F) * ((float)5/9); break; }
		case TemperatureUnit_Fahrenheit: {res = value -  459.67F								;	break; }
		case TemperatureUnit_Kelvin    : {res = value * ((float)5/9)            ; break; }
		default: {break;}
	}
	return res;
}

float Temperature_Convert(float val, TemperatureUnitTypedef SourceType, TemperatureUnitTypedef DestinationType) {
	float result = 0;
	switch(SourceType)
	{
		case TemperatureUnit_Celcius	 : {result = ConvertFromCelcius   (val, DestinationType); break; }
		case TemperatureUnit_Fahrenheit: {result = ConvertFromFahrenheit(val, DestinationType); break; }
		case TemperatureUnit_Kelvin    : {result = ConvertFromKelvin		(val, DestinationType); break; }
		case TemperatureUnit_Rankine   : {result = ConvertFromRankine 	(val, DestinationType); break; }
	}
	return result;
}
