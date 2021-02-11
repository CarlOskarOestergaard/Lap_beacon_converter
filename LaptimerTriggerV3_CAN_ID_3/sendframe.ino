void sendframe()
{
  CAN_message_t msg1;
  msg1.id = 0x500;
  msg1.buf[0] = highByte(can500Byte0_1);
  msg1.buf[1] = lowByte (can500Byte0_1);
  msg1.buf[2] = highByte(can500Byte2_3);
  msg1.buf[3] = lowByte (can500Byte2_3);
  msg1.buf[4] = highByte(can500Byte4_5);
  msg1.buf[5] = lowByte (can500Byte4_5);
  msg1.buf[6] = highByte(can500Byte6_7);
  msg1.buf[7] = lowByte (can500Byte6_7);
  can1.write(msg1);       // write to can1
}
