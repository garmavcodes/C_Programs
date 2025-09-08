#include <stdio.h>

// Convert Celsius to Fahrenheit
void celsius_to_fahrenheit(float val) {
    float f = (val*(9.0/5)) + 32;  // Formula to convert
    printf("the value of %.2f celsius in fahrenheit is : %.2f\n", val, f);
}

// Convert Celsius to Kelvin
void celsius_to_kelvin(float val) {
    float k = val + 273.15;  // Formula to convert
    printf("the value of %.2f celsius in kelvin is : %.2f\n", val, k);
}

// Convert Fahrenheit to Celsius
void fahrenheit_to_celsius(float val) {
    float c = (val-32)*(5.0/9);  // Formula to convert
    printf("the value of %.2f fahrenheit in celsius is:%.2f\n", val, c);
}

// Convert Fahrenheit to Kelvin
void fahrenheit_to_kelvin(float val) {
    float k = (val-32)*(5.0/9) + 273.15;  // Formula to convert
    printf("the value of %.2f fahrenheit in kelvin is:%.2f\n", val, k);
}

// Convert Kelvin to Celsius
void kelvin_to_celsius(float val) {
    float c = val - 273.15;  // Formula to convert
    printf("the value of %.2f kelvin in celsius is:%.2f\n", val, c);
}

// Convert Kelvin to Fahrenheit
void kelvin_to_fahrenheit(float val) {
    float f = (val-273.15)*(9.0/5) + 32;  // Formula to convert
    printf("the value of %.2f kelvin in fahrenheit is:%.2f\n", val, f);
}

int main() {
    float val;
    int option;

    // Show menu for conversion options
    printf("welcome,enter the option number based on which temperature conversion you want\n");
    printf("1.Celsius --> Fahrenheit\n");
    printf("2.Celsius --> Kelvin\n");
    printf("3.Fahrenheit --> Celsius\n");
    printf("4.Fahrenheit --> Kelvin\n");
    printf("5.Kelvin -->Celsius\n");
    printf("6.Kelvin --> Fahrenheit\n");

    scanf("%d",&option);  // Read user choice
    printf("enter the value to be converted:");
    scanf("%f",&val);  // Read temperature value

    // Call the correct function based on user input
    switch(option){
        case 1:
            celsius_to_fahrenheit(val);
            break;
        case 2:
            celsius_to_kelvin(val);
            break;
        case 3:
            fahrenheit_to_celsius(val);
            break;
        case 4:
            fahrenheit_to_kelvin(val);
            break;
        case 5:
            kelvin_to_celsius(val);
            break;
        case 6:
            kelvin_to_fahrenheit(val);
            break;
        default:
            printf("invalid option");  // If input is wrong
    }
    return 0;
}
