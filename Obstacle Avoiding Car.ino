const int right_f=2,right_b=3;
const int left_f=4,left_b=5;

int tp=9;
int ep=10;
int  duration;
int  distance;

void setup()
{
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
  Serial.begin(9600);
  pinMode(right_f, OUTPUT);
  pinMode(right_b, OUTPUT);
  pinMode(left_f, OUTPUT);
  pinMode(left_b, OUTPUT);
  
  
}

void loop()
{
   digitalWrite(tp,0);
  delayMicroseconds(2); 
  digitalWrite(tp,1);
  delayMicroseconds(10);

  duration=pulseIn(ep,1);
  distance=duration/60;;
//distance=(duration*33)/200;
  delay(10);

  Serial.println(distance);
  
 if(distance>25)
 {
 forward();
 }
  else
  {
  stop();
    delay(200);
  backward();
    delay(300);
    stop();
    delay(200);
    left();
    delay(200);
    
  }
  /*delay(5000);
  left();
  delay(5000);
  right();
  delay(5000); 
  stop();
  delay(5000);
  */
  delay(5000);
}
  void forward(){
  digitalWrite(right_f, HIGH);
  digitalWrite(right_b, LOW);
  digitalWrite(left_f, HIGH);
  digitalWrite(left_b, LOW);
  
  }
  
  void backward()
  {
  digitalWrite(right_f, LOW);
  digitalWrite(right_b, HIGH);
  digitalWrite(left_f,LOW);
  digitalWrite(left_b, HIGH);
  
  
}
  
  void left()
  {
  digitalWrite(right_f,LOW );
  digitalWrite(right_b, HIGH);
  digitalWrite(left_f,HIGH);
  digitalWrite(left_b, LOW);
  
  
}
  
  
   void right()
  {
  digitalWrite(right_f, HIGH);
  digitalWrite(right_b, LOW);
  digitalWrite(left_f,LOW);
  digitalWrite(left_b, HIGH);
  
  
}

void stop(){
  
  digitalWrite(right_f, LOW);
  digitalWrite(right_b, LOW);
  digitalWrite(left_f,LOW);
  digitalWrite(left_b, LOW);
}
  