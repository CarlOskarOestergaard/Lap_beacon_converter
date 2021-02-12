void PrintCSV()
{
  Serial.print(millis());
  Serial.print(",");
  Serial.print(msg0);
  Serial.print(",");
  Serial.print(ledpinStatus);
  Serial.print(",");
  Serial.println(beaconPinStatus);

}
