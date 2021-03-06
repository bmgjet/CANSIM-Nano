#include <SPI.h>
#include <mcp_can.h>
#define CAN0_INT 2
MCP_CAN CAN(10);
INT32U canId = 0x000;


unsigned char len = 0;
unsigned char OBDIImsg[8] = {4, 65, 0, 0, 0, 0, 0, 0};
byte buf[8];
String CMD = "";
char msgString[64];
byte PID = 0;
byte MODE = 0;
bool IsSweep = true;
byte sweep = 0;


//Adjustable values
byte Load = 5;
byte TPS = 15;
int TA = 10;
float O2 = 1;
int ECT = 0;
int IAT = 0;
byte MAP = 0;
int RPM = 1000;
int MAF = 10;
byte VSS = 25;
byte FP = 10;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(50);
    Serial.println(("HTS CAN SIM 01"));
  if (CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
  {
    CAN.setMode(MCP_NORMAL);
    pinMode(CAN0_INT, INPUT);
  }
  else
  {
    Serial.println("Setup Failed");
    ;
  }
}

void loop() {
  DOCAN();
  if (Serial)
  {
  DOSERIAL();
  }
}
