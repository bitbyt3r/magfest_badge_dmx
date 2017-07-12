
#include <DMXSerial.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

void setup () {
  DMXSerial.init(DMXReceiver);
  mySerial.begin(115200);
}


char tohex1( int c )
{
    c &= 0x0f;
   if( c >= 0 && c <= 9 ) return c + '0';
    else if( c >= 10 && c <= 15 ) return c - 10 + 'a';
     else return '0';
}

char mbuff[3];

char * hethex(int a) {
    mbuff[0] = tohex1( a >> 4 );
     mbuff[1] = tohex1( a );
     mbuff[2] = 0;
     return mbuff;
}



void loop() {
  mySerial.print("02000000");
 
  mySerial.print(hethex(DMXSerial.read(3)));
  mySerial.print(hethex(DMXSerial.read(2)));
  mySerial.print(hethex(DMXSerial.read(4)));
  mySerial.print(hethex(DMXSerial.read(3)));
  mySerial.print(hethex(DMXSerial.read(2)));
  mySerial.print(hethex(DMXSerial.read(4)));
  mySerial.print(hethex(DMXSerial.read(3)));
  mySerial.print(hethex(DMXSerial.read(2)));
  mySerial.print(hethex(DMXSerial.read(4)));
  mySerial.print(hethex(DMXSerial.read(3)));
  mySerial.print(hethex(DMXSerial.read(2)));
  mySerial.println(hethex(DMXSerial.read(4)));
}
