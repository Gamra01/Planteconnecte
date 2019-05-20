#include "DHT.h"
// PIN data du DHT
#define DHTPIN 2
// de-commenter le capteur utilise
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

// Déclaration du capteur DHT
DHT dht(DHTPIN, DHTTYPE);
 
void setup(){
 Serial.begin(9600);
 // Connexion au capteur
 dht.begin();
}

void loop(){
 delay(2000);
 // Lecture des valeurs:
 // Hygrometrie
 float h = dht.readHumidity();
 // temperature en celsius
 float t = dht.readTemperature();
 // temperature en farenheit
 float f = dht.readTemperature(true);
 
 //On verifie si la lecture a echoue, si oui on quitte la boucle pour recommencer.
 if (isnan(h) || isnan(t) || isnan(f)){
   Serial.println("Failed to read from DHT sensor!");
   return;
 }
 
 // Calcul de l'indice de temperature en Farenheit
 float hif = dht.computeHeatIndex(f, h);
 // Calcul de l'indice de temperature en Celsius
 float hic = dht.computeHeatIndex(t, h, false);
 
 //Affichages :
 Serial.print("Humidite: ");
 Serial.print(h);
 Serial.print(" %\t");
 Serial.print("Temperature: ");
 Serial.print(t);
 Serial.print(" *C ");
 Serial.print(f);
 Serial.print(" *F\t");
 Serial.print("Indice de temperature: ");
 Serial.print(hic);
 Serial.print(" *C ");
 Serial.print(hif);
 Serial.println(" *F");
}
