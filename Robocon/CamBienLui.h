
void doc_CBL()
{

  SSLui[0]  = analogRead(camBienLui1);
  SSLui[1]  = analogRead(camBienLui2);
  SSLui[2]  = analogRead(camBienLui3);
  SSLui[3]  = analogRead(camBienLui4);
  SSLui[4]  = analogRead(camBienLui5);
  SSLui[5]  = analogRead(camBienLui6);
  SSLui[6]  = analogRead(camBienLui7);
  SSLui[7]  = analogRead(camBienLui8);
  //GTlui[0] = 0;
  for (iLui = 0; iLui <= 7; iLui++)
  {
    if (SSLui[iLui] > tb)
    {
      GTlui[iLui] = 0;
    }
    else
    {
      GTlui[iLui] = 1;

    }
  }
  if (GTlui[3] == 1 && GTlui[4] == 1)
  {
    Errorl = 0;
  }
  else if (GTlui[3] == 1 || GTlui[4] == 1)
  {
    Errorl = 0;
  }
  else if (GTlui[2] == 1)
  {
    Errorl = 2;
  }
  else if (GTlui[5] == 1)
  {
    Errorl = -2;
  }
  else if (GTlui[1] == 1)
  {
    Errorl = 3;
  }
  else if (GTlui[6] == 1)
  {
    Errorl = -3;
  }
  else if (GTlui[0] == 1)
  {
    Errorl = 4;
  }
  else if (GTlui[7] == 1)
  {
    Errorl = -4;
  }

  Pl = Errorl;
  Il = Il + previous_Il;
  Dl = Errorl - previous_Errorl;

  PID_value_Lui = (Kp2 * Pl) + (Ki2 * Il) + (Kd2 * Dl);
  previous_Errorl = Errorl;
}

void DK_Lui(int tocDo)
{
  LSpeed = tocDo  + PID_value_Lui;
  RSpeed = tocDo - PID_value_Lui;
  LSpeed = constrain(LSpeed, 0, 255);
  RSpeed = constrain(RSpeed, 0, 255);

  if (Errorl == lostLineRight) {
    xoayTrai(TocDoXoay);
    delay(50);
    luiCham();
    delay(10);
  }
  else if (Errorl ==  lostLineLeft) {
    xoayPhai(TocDoXoay);
    delay(50);
    luiCham();
    delay(10);
  }
  else {
    lui();
  }

  //        Serial.println();
  //        Serial.print(PID_value_Lui);
  //        Serial.print("\t\t");
  //        Serial.print("\t");
  //        Serial.print(LSpeed);
  //
  //        Serial.print("\t");
  //        Serial.print(RSpeed);
  //        Serial.print("\n");
}
