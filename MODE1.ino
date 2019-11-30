void ProcessMode1(byte PID)
{
  OBDIImsg[0] = 4;
  OBDIImsg[1] = 65;
  if (IsSweep)
  {
    Load = 0;
    TPS = 0;
    TA = 0;
    O2 = 0;
    ECT = 0;
    IAT = 0;
    MAP = 0;
    RPM = 0;
    VSS = 0;
    FP = 0;
    sweep++;
  }
  else
  {
    sweep = 0;
  }
  if (PID == 0x00) //PID list 1
  {
    OBDIImsg[0] = 6;
    OBDIImsg[3] = 0xFF;
    OBDIImsg[4] = 0xFF;
    OBDIImsg[5] = 0xFF;
    OBDIImsg[6] = 0xFF;
  }
  if (PID == 0x03) //Fuel system status
  {
    OBDIImsg[2] = PID;
    OBDIImsg[3] = 2;
  }
  if (PID == 0x04) //Engine Load
  {
    OBDIImsg[2] = PID;
    OBDIImsg[3] = (((Load + sweep) * 255) / 100);
  }
  if (PID == 0x05) //ECT
  {
    OBDIImsg[2] = PID;
    OBDIImsg[3] = ((ECT + sweep) + 40);
  }
  if (PID == 0x0A) //Fuel Pressure
  {
    OBDIImsg[2] = PID;
    OBDIImsg[3] = ((FP + sweep) * 3);
  }
  if (PID == 0x0B) //MAP
  {
    OBDIImsg[2] = PID;
    OBDIImsg[3] = MAP + sweep;
  }
  if (PID == 0x0C) //RPM
  {
    int TRPM = RPM + (sweep * 20);
    TRPM = TRPM * 4;
    OBDIImsg[2] = PID;
    OBDIImsg[3] = TRPM / 256;
    OBDIImsg[4] = TRPM & 0xFF;
  }
  if (PID == 0x0D) //Speed
  {
    OBDIImsg[2] = PID;
    OBDIImsg[3] = VSS + sweep;
  }
  if (PID == 0x0E) //Timing Advance
  {
    OBDIImsg[2] = PID;
    OBDIImsg[3] = (((TA + sweep) * 2) + 128);
  }
  if (PID == 0x0F) //IAT
  {
    OBDIImsg[2] = PID;
    OBDIImsg[3] = (IAT + sweep) + 40;
  }
  if (PID == 0x11) //TPS
  {
    TPS = (TPS + sweep);
    OBDIImsg[2] = PID;
    OBDIImsg[3] = TPS;
  }
  if (PID == 0x14) //O2
  {
    OBDIImsg[2] = PID;
    if (IsSweep)
    {
      O2 = random(80, 120);
      O2 = O2 / 100;
    }
    OBDIImsg[3] = O2 * 200;
  }
  CAN.sendMsgBuf(0x7E8, 0, 8, OBDIImsg);
}
