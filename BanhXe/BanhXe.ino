#include <stdio.h>
#include "Chung.h"
#include "dieuKhienDongCo.h"
void setup()
{ 
  khoiTao();
}

void loop()
{
  LSpeed = 140;
  RSpeed = 140;
  tien();
  delay(5000);
  TocDoXoay =255;
  phai();
  delay(5000);
  trai();
  delay(5000);  
  lui();
  delay(5000);
  dung();
  delay(3000);
}
