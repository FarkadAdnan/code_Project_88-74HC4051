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
const int zInput = A0; 
void setup() {
  Serial.begin(9600);
  for (int i=0; i<3; i++)  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], HIGH);
  }
  pinMode(zInput, INPUT);
 
  Serial.println("Y0\tY1\tY2\tY3\tY4\tY5\tY6\tY7");
  Serial.println("---\t---\t---\t---\t---\t---\t---\t---");
}
void loop() {
  for (byte pin=0; pin<=7; pin++)  {
    selectMuxPin(pin); 
    int inputValue = analogRead(A0); 
    Serial.print(String(inputValue) + "\t");
  }
  Serial.println();
  delay(1000);
}
void selectMuxPin(byte pin){
  for (int i=0; i<3; i++){
    if (pin & (1<<i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}
