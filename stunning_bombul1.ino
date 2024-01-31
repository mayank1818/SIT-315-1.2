int led = 13;
int motionSensor = 2;
volatile bool motionDetected = false;

void setup() {
  Serial.begin(9600);
  pinMode(motionSensor, INPUT);
  pinMode(led, OUTPUT);

  
  attachInterrupt(digitalPinToInterrupt(motionSensor), motionInterrupt, RISING);
}

void loop() {
  if (motionDetected) {
    digitalWrite(led, HIGH);
    Serial.println("Motion Detected");
    delay(2000);  
    digitalWrite(led, LOW);
    delay(500); 
    motionDetected = false;  
  } else {
    digitalWrite(led, LOW);
    Serial.println("NO MOTION");
    delay(2000);  
  }
 
}

void motionInterrupt() {

  motionDetected = true;  
}
