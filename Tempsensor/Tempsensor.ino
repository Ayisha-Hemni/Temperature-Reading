#define BLYNK_TEMPLATE_ID "TMPL3MphlnjSl"
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor"
#define BLYNK_AUTH_TOKEN "uXpGQvfx_QkhBPJ2voYmHTJNNkx1Dwp6"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>


#define DHTPIN 4 //Data pin is connected to D2
#define DHTTYPE DHT11 //Name the sensor

char auth[]="uXpGQvfx_QkhBPJ2voYmHTJNNkx1Dwp6";
char ssid[]="Hemz";
char pass[]="00000000";

DHT dht(DHTPIN,DHTTYPE);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successfully!");
  Blynk.begin(auth,ssid,pass);
  Serial.println("Blynk is Connected!!");
  dht.begin();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);
  if (isnan(h)||isnan(t)||isnan(f))
  {
    Serial.println("Something is not working as intended");
    return;
  }
  Serial.println("Humditiy:");
  Serial.print(h);
  Serial.println("Temperature:");
  Serial.print(t);
  Serial.print("Degree celsius.");
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  delay(1000);
}
