void ProcessMode3()
{
      OBDIImsg[0] = 6;
      OBDIImsg[1] = 67;
      OBDIImsg[2] = 0x04;
      OBDIImsg[3] = 0x20; 
      OBDIImsg[4] = 0x04;
      OBDIImsg[5] = 0x21; 
      CAN.sendMsgBuf(0x7E8, 0, 6, OBDIImsg);
}
void ProcessMode4()
{
      OBDIImsg[0] = 4;
      OBDIImsg[1] = 65;
      OBDIImsg[2] = 0x44;
      OBDIImsg[3] = 0x00; 
      CAN.sendMsgBuf(0x7E8, 0, 4, OBDIImsg);
}
