#include <iostream>
#include <assert.h>

#define SUCCESS 200
#define FAILURE 500
#define PRODUCTIONCODE 1
#define STUBCODE 2

int alertFailureCount = 0;
float threshold = 200;

int networkAlertProduction(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    int code = (celcius > threshold) ? FAILURE : SUCCESS;
    return code;
}

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // stub always succeeds and returns 200
    return SUCCESS;
}

float convertFahrenheitToCelcius(float fahrenheit)
{
    float celcius = (fahrenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit, int testEnvironment ) {
    int returnCode ;
    float celcius = convertFahrenheitToCelcius(farenheit);
    if(testEnvironment == PRODUCTIONCODE)
     returnCode = networkAlertProduction(celcius);
    else
     returnCode = networkAlertStub(celcius);
    
    if (returnCode != 200) {
        alertFailureCount = 1;
    }
    else
    {
        alertFailureCount = 0;
    }
}

int main() {
    alertInCelcius(400.5, PRODUCTIONCODE);
    assert(alertFailureCount==1);
    alertInCelcius(400.5, STUBCODE);
    assert(alertFailureCount==0);
    alertInCelcius(303.6, PRODUCTIONCODE);
    assert(alertFailureCount==1);
    alertInCelcius(303.6, STUBCODE);
    assert(alertFailureCount==0);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
