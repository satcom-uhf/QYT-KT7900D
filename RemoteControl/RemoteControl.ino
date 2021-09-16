int valcoderUp = 12;
int valcoderDown = 10;
int menu = 8;
int abcd = 6;
bool valcoderState = false;
void setup(void)
{
   Serial.begin(9600);
   pinMode(valcoderUp, OUTPUT);
   pinMode(valcoderDown, OUTPUT);
   pinMode(menu, OUTPUT);
   pinMode(abcd, OUTPUT);
}

void clickButton(int pin)
{
   digitalWrite(pin, HIGH);
   delay(10);
   digitalWrite(pin, LOW);
}

void valCoderTick(int pin1, int pin2)
{
   valcoderState = !valcoderState;
   digitalWrite(pin1, valcoderState);
   delay(3);
   digitalWrite(pin2, valcoderState);
}

void up()
{   
   valCoderTick(valcoderDown, valcoderUp);
}
void down()
{
   valCoderTick(valcoderUp, valcoderDown);
}

void loop()
{
   byte ch;

   if (Serial.available())
   {
      ch = Serial.read();
      switch (ch)
      {
      case '+':
         up();
         Serial.println("Up");
         break;
      case '-':
         down();
         Serial.println("Down");
         break;
      case 'e':
         clickButton(abcd);
         Serial.println("ABCD");
         break;
      case 'm':
         clickButton(menu);
         Serial.println("MENU");
         break;
      }
   }
}
