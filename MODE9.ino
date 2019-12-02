bool ProcessMode9(byte PID)
{
  OBDIImsg[0] = 6;
  OBDIImsg[1] = 67;
  OBDIImsg[2] = PID;

  if (PID == 0x02) //VIN: XXXXXXXXXXXXXXXXX
  {
    OBDIImsg[3] = 0x20;
    OBDIImsg[4] = 0x04;
    OBDIImsg[5] = 0x21;
    OBDIImsg[6] = 0x21;
    OBDIImsg[7] = 0x21;
    OBDIImsg[8] = 0x21;
    OBDIImsg[9] = 0x21;
    OBDIImsg[10] = 0x21;
    OBDIImsg[11] = 0x21;
    OBDIImsg[12] = 0x21;
    OBDIImsg[13] = 0x21;
    OBDIImsg[14] = 0x21;
    OBDIImsg[15] = 0x21;
    OBDIImsg[16] = 0x21;
return true;
  }
    if (PID == 0x04) //CALID: XXXXXXXXXXXXXXXX
  {
    OBDIImsg[3] = 0x20;
    OBDIImsg[4] = 0x04;
    OBDIImsg[5] = 0x21;
    OBDIImsg[6] = 0x21;
    OBDIImsg[7] = 0x21;
    OBDIImsg[8] = 0x21;
    OBDIImsg[9] = 0x21;
    OBDIImsg[10] = 0x21;
    OBDIImsg[11] = 0x21;
    OBDIImsg[12] = 0x21;
    OBDIImsg[13] = 0x21;
    OBDIImsg[14] = 0x21;
    OBDIImsg[15] = 0x21;
    OBDIImsg[16] = 0x21;
return true;
  }
  return false;
}
