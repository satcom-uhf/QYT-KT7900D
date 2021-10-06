#define VALCODER_UP 12
#define VALCODER_DOWN 10
#define MENU 8
#define ABCD 6
#define PTT 9
#define SQUELCH_OPEN 3
#define EXTERNAL_PTT 7
bool valcoderState = false;
bool extPttState = false;
void setup(void)
{
   pinMode(PTT, OUTPUT);
   digitalWrite(PTT, LOW);
   pinMode(VALCODER_UP, OUTPUT);
   pinMode(VALCODER_DOWN, OUTPUT);
   pinMode(MENU, OUTPUT);
   pinMode(ABCD, OUTPUT);
   Serial.begin(9600);
   pinMode(SQUELCH_OPEN, INPUT);
   pinMode(EXTERNAL_PTT, INPUT);
   attachInterrupt(digitalPinToInterrupt(SQUELCH_OPEN), monitorActivity, CHANGE);
}

void monitorActivity()
{
   if (digitalRead(SQUELCH_OPEN) == LOW)
   {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("activity");
   }
   else
   {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("silence");
   }
}

void clickButton(int pin)
{
   digitalWrite(pin, HIGH);
   delay(15);
   digitalWrite(pin, LOW);
}

void valCoderTick(int pin1, int pin2)
{
   valcoderState = !valcoderState;
   digitalWrite(pin1, valcoderState);
   delay(5);
   digitalWrite(pin2, valcoderState);
}

void up()
{
   valCoderTick(VALCODER_DOWN, VALCODER_UP);
}
void down()
{
   valCoderTick(VALCODER_UP, VALCODER_DOWN);
}

void ptt()
{
   digitalWrite(PTT, HIGH);
   Serial.println("PTT");
}
void stopPtt()
{

   digitalWrite(PTT, LOW);
   Serial.println("PTTSTOP");
}

void loop()
{
   byte ch;
   bool extPtt = digitalRead(EXTERNAL_PTT);
   if (extPtt != extPttState)
   {
      extPttState = extPtt;
      if (extPtt)
      {
         ptt();
      }
      else
      {
         stopPtt();
      }
   }

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
         clickButton(ABCD);
         Serial.println("ABCD");
         break;
      case 'm':
         clickButton(MENU);
         Serial.println("MENU");
         break;
      case 't':
         ptt();
         break;
      case 's':
         stopPtt();
         break;
      }
   }
}
