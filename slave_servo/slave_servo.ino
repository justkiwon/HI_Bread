#include <Servo.h>
#include <SPI.h>

char wd =0;
Servo sv1, sv2;

void svrs(){
  sv1.write(90);
  sv2.write(90);
}

void setup(){
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
  sv1.attach(6);
  sv2.attach(5);
  svrs();
  Serial.begin(9600);
}

ISR(SPI_STC_vect){
  byte c = SPDR;
  wd = c;
  }

void loop(){
  svrs();
  if(wd != 0){
    switch(wd) {
      case 'a':
      sv1.write(120);
     delay(500);
     sv1.write(60);
     sv2.write(160);
      break;
    }
  }
   wd =0;
    delay(2500);
}
