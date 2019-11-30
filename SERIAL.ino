void DOSERIAL()
{
  if (GETCMD())
  {
    int tempvalue = getValue(CMD, ':', 1).toInt();

    if (CMD.indexOf("SW") == 0)
    {
      if (tempvalue == 1)
      {
        IsSweep = true;
      }
      else
      {
        IsSweep = false;
      }
      Serial.println(String("Sweep " + String(IsSweep)));
    }


    if (CMD.indexOf("RPM") == 0)
    {
      if (tempvalue <= 10000 && tempvalue > 0)
      {
        RPM = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(RPM));
      }
    }

    if (CMD.indexOf("FP") == 0)
    {
      if (tempvalue <= 255 && tempvalue > 0)
      {
        FP = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(FP));
      }
    }

    if (CMD.indexOf("VSS") == 0)
    {
      if (tempvalue <= 255 && tempvalue > 0)
      {
        VSS = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(VSS));
      }
    }

    if (CMD.indexOf("EL") == 0)
    {
      if (tempvalue <= 100 && tempvalue > 0)
      {
        Load = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(Load));
      }
    }
    if (CMD.indexOf("TPS") == 0)
    {
      if (tempvalue <= 255 && tempvalue > 0)
      {
        TPS = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(TPS));
      }
    }

    if (CMD.indexOf("TA") == 0)
    {
      if (tempvalue <= 63 && tempvalue > -64)
      {
        TA = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(TA));
      }
    }

    if (CMD.indexOf("O2") == 0)
    {
      if (getValue(CMD, ':', 1).toFloat() <= 5 && getValue(CMD, ':', 1).toFloat() > 0)
      {
        O2 = getValue(CMD, ':', 1).toFloat();
        Serial.println("S");
      } else {
        Serial.println(String(O2));
      }
    }
    if (CMD.indexOf("ECT") == 0)
    {
      if (tempvalue <= 215 && tempvalue > -40)
      {
        ECT = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(ECT));
      }
    }
    if (CMD.indexOf("IAT") == 0)
    {
      if (tempvalue <= 215 && tempvalue > -40)
      {
        IAT = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(IAT));
      }
    }
    if (CMD.indexOf("MAP") == 0)
    {
      if (tempvalue <= 255 && tempvalue > 0)
      {
        MAP = tempvalue;
        Serial.println("S");
      } else {
        Serial.println(String(MAP));
      }
    }

  }

}

bool GETCMD() {
  if (Serial.available() > 0) {
    CMD = Serial.readString();
    CMD.trim();
    return true;
  }
  else
  {
    return false;
  }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
