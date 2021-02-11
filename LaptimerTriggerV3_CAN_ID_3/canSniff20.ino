
void canSniff(const CAN_message_t &msg)
{
  if (msg.id == 0x303)
  {

    msg0 = msg.buf[0];
    msg1 = msg.buf[1];
    msg2 = msg.buf[2];
    msg3 = msg.buf[3];
    msg4 = msg.buf[4];
    msg5 = msg.buf[5];
    msg6 = msg.buf[6];
    msg7 = msg.buf[7];
    i = 0;
  }
}
