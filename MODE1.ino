bool ProcessMode1(byte PID)
{
  OBDIImsg[0] = 4;
  OBDIImsg[1] = 65;
  OBDIImsg[2] = PID;
  if (IsSweep)
  {
    sweep++;
  }
  else
  {
    sweep = 0;
  }
  if (PID == 0x00) //PID list 1   387F9000
  {
    OBDIImsg[0] = 6;
    OBDIImsg[3] = 0x38;
    OBDIImsg[4] = 0x7F;
    OBDIImsg[5] = 0x90;
    OBDIImsg[6] = 0x00;
    OBDIImsg[7] = 0x00;
    return true;
  }
  if (PID == 0x03) //Fuel system status
  {
    OBDIImsg[3] = 2;
    return true;
  }
  if (PID == 0x04) //Engine Load
  {
    OBDIImsg[3] = (((Load + sweep) * 255) / 100);
    return true;
  }
  if (PID == 0x05) //ECT
  {
    OBDIImsg[3] = ((ECT + sweep) + 40);
    return true;
  }
  if (PID == 0x0A) //Fuel Pressure
  {
    OBDIImsg[3] = ((FP + sweep) * 3);
    return true;
  }
  if (PID == 0x0B) //MAP
  {
    OBDIImsg[3] = MAP + sweep;
    return true;
  }
  if (PID == 0x0C) //RPM
  {
    int TRPM = RPM + (sweep * 20);
    TRPM = TRPM * 4;
    OBDIImsg[3] = TRPM / 256;
    OBDIImsg[4] = TRPM & 0xFF;
    return true;
  }
  if (PID == 0x0D) //Speed
  {
    OBDIImsg[3] = VSS + sweep;
    return true;
  }
  if (PID == 0x0E) //Timing Advance
  {
    OBDIImsg[3] = (((TA + sweep) * 2) + 128);
    return true;
  }
  if (PID == 0x0F) //IAT
  {
    OBDIImsg[3] = (IAT + sweep) + 40;
    return true;
  }
    if (PID == 0x10) //MAF
  {
    int TMAF = MAF + (sweep * 20);
    TMAF = MAF * 100;
    OBDIImsg[3] = TMAF / 256;
    OBDIImsg[4] = TMAF & 0xFF;
    return true;
  }
  if (PID == 0x11) //TPS
  {
    OBDIImsg[3] = (TPS + sweep);
    return true;
  }
  if (PID == 0x14) //O2
  {
    if (IsSweep)
    {
      O2 = random(80, 120);
      O2 = O2 / 100;
    }
    OBDIImsg[3] = O2 * 200;
    return true;
  }
    if (PID == 0x42) //Control module voltage 
  {
    OBDIImsg[3] = sweep;
    return true;
  }
      if (PID == 0x2F) //Fuel Tank Level 
  {
    OBDIImsg[3] = sweep;
    return true;
  }
        if (PID == 0x4D) //Time run with MIL on  
  {
    OBDIImsg[3] = sweep;
    return true;
  }
return false;
}
