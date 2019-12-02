void DOCAN()
{
  if (!digitalRead(CAN0_INT))
  {
    CAN.readMsgBuf(&canId, &len, buf);
    MODE = buf[1];
    PID = buf[2];
    if (MODE == 1)
    {
      if (ProcessMode1(PID))
      {
        CAN.sendMsgBuf(0x7E8, 0, 8, OBDIImsg);
      }
    }
    else if (MODE == 3)
    {
      ProcessMode3();
    }
    else if (MODE == 4)
    {
      ProcessMode4();
    }
    else if (MODE == 9)
    {
      if (ProcessMode9(PID))
    {
      CAN.sendMsgBuf(0x7E8, 0, 17, OBDIImsg);
      }
    }
  }
}
