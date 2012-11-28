// Multi servo test

// Setting up Pots

const int POT_VERT = 0;
const int POT_HORZ = 2;

const int SERV_VERT = 10;
const int SERV_HORZ = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(SERV_VERT, OUTPUT);
  pinMode(SERV_HORZ, OUTPUT);
}

void loop()
{
  int vertical   = analogRead(POT_VERT);
  int horizontal = analogRead(POT_HORZ);
  
  Serial.println(vertical);
  Serial.println(horizontal);
  
  analogWrite(SERV_VERT, map(vertical, 0,700, 0, 180) );
  analogWrite(SERV_HORZ, map(horizontal, 0,700, 0, 180) );

}
