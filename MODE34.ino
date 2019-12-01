void ProcessMode3()
{
      OBDIImsg[0] = 6;
      OBDIImsg[1] = 67;
      OBDIImsg[2] = 1;
      OBDIImsg[3] = 2; 
      OBDIImsg[4] = 23; 
      CAN.sendMsgBuf(0x7E8, 0, 8, OBDIImsg);
}
void ProcessMode4()
{
      OBDIImsg[0] = 4;
      OBDIImsg[1] = 65;
      OBDIImsg[2] = 04;
      OBDIImsg[3] = 44; 
      OBDIImsg[4] = 00; 
      CAN.sendMsgBuf(0x7E8, 0, 8, OBDIImsg);
}
