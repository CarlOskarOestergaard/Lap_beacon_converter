
void LED(String att)
{

  if (att == "flash")
  {
    if (currentMillis - previousMillis_LED > interval_LED )  // This will only run if 1000msec have passed since the last visit
    {
      previousMillis_LED = millis();

      if (ledpinStatus == 0)
      {
        digitalWrite(ledPin, HIGH);
        ledpinStatus = 1;
        if (CSV == 1)
        {
          Serial.println("LED ON");
        }
      }

      else if (ledpinStatus == 1)
      {
        digitalWrite(ledPin, LOW);
        ledpinStatus = 0;
        if (CSV == 1)
        {
          Serial.println("LED OFF");
        }
      }
    }

  }

  if (att == "on")
  {
    digitalWrite(ledPin, HIGH);
    ledpinStatus = 1;
  }
}
