const int LED = 13; //because the LED anode is connected to digital pin 13

void setup()
{
  pinMode(LED, OUTPUT); //sets pin 13 to OUTPUT mode
}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
