void setup() {
    pinMode(A0, INPUT); 
    pinMode(A1, INPUT);
   
Serial.begin(9600);
}

void loop() {

  int L = digitalRead(A0);
  int R = digitalRead(A1);
  

  delay(100);


  Serial.println("RIGHT");
  Serial.println(R);
  Serial.println("LEFT");
  Serial.println(L);
delay(1000);

/*if(R2==1) {
  Serial.println("done");
 
}else{
    Serial.println("notdone");

}
*/
}
