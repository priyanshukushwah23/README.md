// Smart Energy Meter Code
const int buzzerPin = 8; // Apne buzzer ki pin yahan likhe

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Yahan apne sensors (jaise ZMPT101B aur ACS712) ki readings ka code lagayein
  // Filhal testing ke liye hum dummy live values bhej rahe hain taaki dashboard check ho sake:
  float voltage = 220.50 + random(0, 100) / 10.0;
  float current = 0.25 + random(0, 50) / 100.0;
  float power = voltage * current;
  
  String switchStatus = "RELEASED";
  String buzzerStatus = "OFF";

  // Data ko CSV format mein print karein: Voltage,Current,Power,Switch,Buzzer
  Serial.print(voltage);
  Serial.print(",");
  Serial.print(current);
  Serial.print(",");
  Serial.print(power);
  Serial.print(",");
  Serial.print(switchStatus);
  Serial.print(",");
  Serial.println(buzzerStatus);

  delay(1000); // Har 1 second baad data update hoga
}