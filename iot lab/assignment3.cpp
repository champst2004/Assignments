const int buzzerPin = 8;
const int ledPin = 5;
const int analogPin = A0;
float voltage;
int temp;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorVal = analogRead(analogPin);
  voltage = sensorVal * (5.0 / 1024.0);
  temp = (voltage - 0.5) * 100;

  if(temp > 25){
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  }
  else{
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  delay(500);
}
