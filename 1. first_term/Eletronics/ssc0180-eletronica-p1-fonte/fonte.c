#include <math.h>
#include <stdio.h>

const double diode_voltage = 0.7;
const double m = 0.001;
const int max_voltage = 12;
const int min_voltage = 3;
const double potentiometer_min_resistance = 25;
const double input_voltage = 127;

const double zener_amps = 2.5 * m;
const double potentiometer_amps = 2.3 * m;

int main() {

	double useful_amperage = 100*m;
	double grounded_resistor = ( max_voltage / useful_amperage );
	printf("Resistência do resistor simulador da saida: %.2lf\n", grounded_resistor);
	printf("Amperagem e voltagem máxima: %.2lfmA, %dV\n", useful_amperage * 1000, max_voltage);
	printf("Amperagem e voltagem mínima: %.2lfmA, %dV\n", min_voltage / grounded_resistor * 1000, min_voltage);

	double max_network_voltage = input_voltage * sqrt(2);

}
