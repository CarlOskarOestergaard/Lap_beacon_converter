void beaconOutput()
{

  if (msg0 != msg0_old)                  // Everytime the signal changes state LAP 1,2,3,4...
  {
    msg0_old = msg0;                     // Save the new message
    digitalWrite(beaconPin, LOW);        // Turn on beacon pin OFF
    beaconPinStatus = 0;                 // Save the status of the beacon pin
    previousMillis_beacon = millis();    // Save the current timestamp ()

    /// Print status
    if (CSV == 1)
    {
      Serial.println("beaconPinStatus: LOW");
    }

  }


  if (beaconPinStatus == 1)
  {
    if (millis() - previousMillis_beacon > interval_beacon )
    {
      digitalWrite(beaconPin, HIGH);  // Turn on beacon pin ON
      beaconPinStatus = 1;            // Save the new status of the beacon pin

      /// Print status
      if (CSV == 1)
      {
        Serial.println("beaconPinStatus: 0");
      }
    }
  }
}
