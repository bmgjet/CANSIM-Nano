void DOCAN()
{
 if (!digitalRead(CAN0_INT))                     
  {
    CAN.readMsgBuf(&canId, &len, buf);
    MODE = buf[1];
    PID = buf[2];
    if (MODE == 1)
    {
    ProcessMode1(PID);
    }
    else if (MODE == 3) 
    {
    ProcessMode3();
    }
    else if (MODE == 4) 
    {
    //ProcessMode4();
    }
    else if (MODE == 9) 
    {
    //ProcessMode9();
    }
  }
}
