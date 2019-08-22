# Installatie Erik Priolt

Hoe zou ik dit aanpakken
Ik zou een pomp gebruiken en die aansluiten op een oogdetectie systeem die is geplaatst op de waterdichte tank. Hiervoor gebruik ik een afstandsmeter; wanneer er mensen 2 seconden lang binnen de 1 meter zijn en voor het beeld staan, begint te pomp te spuiten. Het beeld en pomp zit samengevoegd in een waterdichte ‘tank’. Voor het beeld zou ik siliconen gieten waarin de elektronica zit opgelost. De aansluiting voor de afstandssensor zit weggewerkt in de naad van het glas. Zo is alles waterdicht. De pomp kan mooi geplaatst worden onder de opvangbak van het water en worden weggewerkt in het voetstuk van het beeld. Om de opvangbak en het water te verbergen gebruik ik een raster waar het water doorheen kan lopen.

Ik heb hiervoor nodig. 
230v aansluiting voor pomp.
Splitter + Slangen naar beide ogen.
Pomp
Water
Arduino > mogelijk met extra transistor voor het aanzetten van pomp.
Afstandssensor op de waterdichte kap
Siliconen beeld
Raster
Kap
Opvangbak voor het water aangesloten op de pomp.


Arduino Code: 

#include <Servo.h> Servo servo;
const int trigPin = 3; const int echoPin = 7;
    void setup() {
    Serial.begin(9600); servo.attach(10);
    }
    void loop() {
        long duration, cm; pinMode(trigPin, OUTPUT); digitalWrite(trigPin, LOW); delayMicroseconds(2); digitalWrite(trigPin, HIGH); delayMicroseconds(20); digitalWrite(trigPin, LOW); pinMode(echoPin, INPUT); duration = pulseIn(echoPin, HIGH);
        cm = microsecondsToCentimeters(duration); 
        if ( cm < 10)
        {
            myservo.write(140);
            delay(4000); 
            
    }
        else
        { 
            myservo.write(0); delay(100);
        }
            Serial.print(cm); Serial.print("cm");
            Serial.println();
            delay(100);
    }
            long microsecondsToCentimeters(long microseconds) { return microseconds / 29 / 2;
}
