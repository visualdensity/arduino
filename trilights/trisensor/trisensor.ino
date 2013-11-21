int lightA = A0; //675, 250
int lightB = A1; //220, 45
int lightC = A2; //780, 330

int outputR = 9;
int outputG = 10;
int outputB = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(outputR, OUTPUT);
  pinMode(outputG, OUTPUT);
  pinMode(outputB, OUTPUT);
}

void loop() {
  
  int valueA = analogRead(lightA);
  int valueB = analogRead(lightB);
  int valueC = analogRead(lightC);
  
  int valueR = map( valueA, 155, 600, 10, 220 );
  int valueG = map( valueB, 40, 182, 10, 220 );
  int valueBb = map( valueC, 220, 720, 10, 220 );
  
  analogWrite( outputR, valueR );
  analogWrite( outputG, valueG );
  analogWrite( outputB, valueBb );
  
  // put your main code here, to run repeatedly: 
  Serial.print( "A0: " + String( valueA ) + " " );
  Serial.print( "A1: " + String( valueB ) + " " );  
  Serial.print( "A2: " + String( valueC ) + " --- " );

  Serial.print( "R: " + String( valueR ) + " " );
  Serial.print( "G: " + String( valueG ) + " " );  
  Serial.println( "B: " + String( valueBb ) + " " );
  
  delay(20);
}
