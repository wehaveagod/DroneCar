int in1 = 4; 
int in2 = 5;
int pwm1 = 9;

int in3 = 6; 
int in4= 7;
int pwm2 = 10;

double ch2;
double ch1;

void setup(){
  Serial.begin(9600);

  pinMode(1,INPUT);
  pinMode(4,OUTPUT); 
  pinMode(5,OUTPUT);
  
  pinMode(2,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop(){

  ch1 = pulseIn(1, HIGH);
  ch2 = pulseIn(2,HIGH);

  if(ch2 > 1510){ 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(pwm1, (double)255/442*(ch2-1510));
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(pwm2, (double)255/442*(ch2-1510));
  }else if(ch2 < 1470){  
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(pwm1, (double)-255/430*(ch2-1470));
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(pwm2, (double)-255/430*(ch2-1470));
  }else{     
    digitalWrite(in1,LOW); 
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  }

}
