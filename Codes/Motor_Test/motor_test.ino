#define in1 8//right
#define in2 9///right
#define in3 6//left
#define in4 7//left
#define enA 10//right
#define enB 5//left

int M1_Speed = 200; // speed of motor right
int M2_Speed = 220; // speed of motor left

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
}

void loop() {
forward();
}
void forward()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

              analogWrite(enB, M2_Speed);
              analogWrite(enA, M1_Speed);

}