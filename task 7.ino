int trigger = 5;
int echo = 6;
int led1 = 1;
int led2 = 2; 
int led3 = 3;
int led4 = 4;

long duration = 0;
int cm = 0;
int inch = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  
}

void loop()
{ 
  
  digitalWrite(trigger, LOW);
  digitalWrite(trigger, HIGH);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  cm = duration*0.034/2;
  inch = duration*0.0133/2;

  if (cm < 100){
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  
    if (cm > 100){
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
    }
        if (cm > 100){
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
          
        }
    if (cm > 100){
    digitalWrite(led4, HIGH);
  } else {
    digitalWrite(led4, LOW);   
  }

  if (cm < 100 ) {
    Serial.print("Cm: ");
    Serial.println(cm);
  }
delay(500); 
}
    


