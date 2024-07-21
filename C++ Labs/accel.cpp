#include <LSM6DS3.h>
#include <Wire.h>
#include <SD.h>
#include <RTCZero.h>
/* importing the necessary libraries */

/* Create an rtc object */

RTCZero CLOCK;
/* Change these values to set the current initial time */
const byte seconds = 00;
const byte minutes = 00;
const byte hours = 00;

/* Change these values to set the current initial date */
const byte day = 02;
const byte month = 03;
const byte year = 22;

// Create a instance of class LSM6DS3 (6-Axis Accelerometer/Gyroscope)
LSM6DS3 myIMU(I2C_MODE, 0x6A); // I2C device address 0x6A
float aX, aY, aZ, gX, gY, gZ;
/* Setting SD card up */
const int chipSelect = SDCARD_SS_PIN;

File myFile;

unsigned long myTime;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    // Visual Indicator initialized (LED)

    Serial.begin(9600);

    while (!Serial)
    {
        // initialized RTC and setting time and date
        CLOCK.begin();
        CLOCK.setTime(hours, minutes, seconds);
        CLOCK.setDate(day, month, year);
    };
    Serial.print("Initializing SD card...");

    // see if the card is present and can be initialized:
    if (!SD.begin(chipSelect))
    {
        Serial.println("Card failed, or not present");
        // don't do anything more:
        while (1)
            ;
    }
    Serial.println("card initialized.");
    Serial.println("Sensor is warming up. Calibration will start in 5 sec...");

    delay(1000); // wait 5sec for the SENSOR to start warming up

    Serial.println("System ready...");

    // Call .begin() to configure the IMUs
    if (myIMU.begin() != 0)
    {
        Serial.println("Device error");
    }
    else
    {
        Serial.println("aX,aY,aZ,gX,gY,gZ");
    }
}

void loop()
{
    // creation of variables
    float sumaX, sumaY, sumaZ;
    float sumgX, sumgY, sumgZ;
    // using a for loop to produce averages out of 100 iterations
    for (int x = 0; x < 100; x++)
    {
        aX = myIMU.readFloatAccelX();
        aY = myIMU.readFloatAccelY();
        aZ = myIMU.readFloatAccelZ();

        gX = myIMU.readFloatGyroX();
        gY = myIMU.readFloatGyroY();
        gZ = myIMU.readFloatGyroZ();

        sumaX += aX;
        sumaY += aY;
        sumaZ += aZ;

        sumgX += gX;
        sumgY += gY;
        sumgZ += gZ;
    }
    sumaX = sumaX / 100;
    sumaY = sumaY / 100;
    sumaZ = sumaZ / 100;

    sumgX = sumgX / 100;
    sumgY = sumgY / 100;
    sumgZ = sumgZ / 100;

    // print the data in CSV format to Serial Monitor
    Serial.print("sumaX = ");
    Serial.print(sumaX, 2);
    Serial.print(", sumaY = ");
    Serial.print(sumaY, 2);
    Serial.print(", sumaZ = ");
    Serial.print(sumaZ, 2);

    Serial.print("\n");
    Serial.print("sumgX = ");
    Serial.print(sumgX, 2);
    Serial.print(", sumgY = ");
    Serial.print(sumgY, 2);
    Serial.print(", sumgZ = ");
    Serial.print(sumgZ, 2);
    Serial.print("\n");
    Serial.print("Time Elapsed from Program start= ");
    myTime = millis();
    Serial.println(myTime);

    // Creation of Strings to print to both sd_card file and serial monitor
    String dataStringAccel = "";
    dataStringAccel += "Date: " + getDate() + "\t" + "Time: " + getTime() + "\t" + "Acceleration values" + "\t" + "X-direction (g): " + String(sumaX, 2) + "\t" + "Y-direction (g): " + String(sumaY, 2) + "\t" + "Z-direction (g): " + String(sumaZ, 2);

    String dataStringGyro = "";
    dataStringGyro += "Date: " + getDate() + "\t" + "Time: " + getTime() + "\t" + "Angle rate values" + "\t" + "Y-direction (degrees per second): " + String(sumgX, 2) + "\t" + "Y-direction: (degrees per second) " + String(sumgY, 2) + "\t" + "Z-direction (degrees per second): " + String(sumgZ, 2);
    // Creation of txt file
    Serial.println("Creating AG_data.txt...");
    myFile = SD.open("AG_Data.txt", FILE_WRITE);

    if (SD.exists("AG_Data.txt"))
    {
        myFile.print("Time elapsed from Program start: ");
        myFile.println(myTime);
        myFile.println(dataStringAccel);
        // myFile.println();
        myFile.println(dataStringGyro);
        // myFile.println(); hw
        // Close the file so that the DATA can be saved to the SD card
        myFile.close();
        Serial.println("Data successfully written into txt file");

        // print to the serial port too:
        Serial.println(dataStringAccel);
        // Serial.println();
        Serial.println(dataStringGyro);
        // Serial.println();
        Serial.println();

        // LED INDICATOR to confirm a DATA WRITE TO LOG FILE
        digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
        delay(100);                      // wait for a bit
        digitalWrite(LED_BUILTIN, LOW);  // turn the LED off
    }
    // if the file isn't open, pop up an error:
    else
    {
        Serial.println("error opening AG_data.txt");
    }
    // Serial.println(getTime());
    delay(400); // 400msec sampling frequency
                // Serial.println(getTime());
}
// functions used to retrieve hour, minute, and day data
String getTime(void)
{
    String returnString = "";

    if (CLOCK.getHours() < 10)
        returnString += "0" + String(CLOCK.getHours());
    else
        returnString += String(CLOCK.getHours());

    returnString += ":";

    if (CLOCK.getMinutes() < 10)
        returnString += "0" + String(CLOCK.getMinutes());
    else
        returnString += String(CLOCK.getMinutes());

    returnString += ":";

    if (CLOCK.getSeconds() < 10)
        returnString += "0" + String(CLOCK.getSeconds());
    else
        returnString += String(CLOCK.getSeconds());

    return returnString;
}
String getDate(void)
{
    String returnString = "";

    returnString += String(CLOCK.getDay());

    returnString += ":";

    returnString += String(CLOCK.getMonth());

    returnString += ":";

    returnString += String(CLOCK.getYear());

    return returnString;
}
