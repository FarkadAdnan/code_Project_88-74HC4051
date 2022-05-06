/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
const int selectPins[3] = {2, 3, 4}; 
const int zOutput = 5; 
const int LED_ON_TIME = 500; 
const int DELAY_TIME = ((float)LED_ON_TIME/512.0)*1000;
void setup() {
  for (int i=0; i<3; i++)  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], LOW);
  }
  pinMode(zOutput, OUTPUT); 
}

void loop() {
  for (int pin=0; pin<=7; pin++)  {
    selectMuxPin(pin);
    for (int intensity=0; intensity<=255; intensity++)    {
      analogWrite(zOutput, intensity);
      delayMicroseconds(DELAY_TIME);
    }
    for (int intensity=255; intensity>=0; intensity--)    {
      analogWrite(zOutput, intensity);
      delayMicroseconds(DELAY_TIME);
    }
  }
  for (int pin=6; pin>=1; pin--)  {
    selectMuxPin(pin); 
    for (int intensity=0; intensity<=255; intensity++){
      analogWrite(zOutput, intensity);
      delayMicroseconds(DELAY_TIME);
    }
    for (int intensity=255; intensity>=0; intensity--)    {
      analogWrite(zOutput, intensity);
      delayMicroseconds(DELAY_TIME);
    }
  }
}
void selectMuxPin(byte pin){
  if (pin > 7) return; 
  for (int i=0; i<3; i++){
    if (pin & (1<<i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}
