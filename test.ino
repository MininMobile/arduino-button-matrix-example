// Get Button Values
const String buttons[][3] = {
{"1", "2", "3"},
{"4", "5", "6"}
};

// Get Pins
const int row1 = 2;
const int row2 = 3;

const int column1 = 4;
const int column2 = 5;
const int column3 = 6;

// Begin
void setup() {
  pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  
  pinMode(column1, INPUT);
  pinMode(column2, INPUT);
  pinMode(column3, INPUT);

  Serial.begin(9600);
  Serial.write("Hello World! \n");
}

// Check
void loop() {
  while (!checkForBtn()) {}
  
  Serial.print(buttons[getBtn()[1]][getBtn()[0]]);
  Serial.write("\n");
  
  while (checkForBtn()) {}
}

bool checkForBtn() {
  if (digitalRead(row1) == LOW) return false;
  if (digitalRead(row2) == LOW) return false;
  if (digitalRead(column1) == LOW) return false;
  if (digitalRead(column2) == LOW) return false;
  if (digitalRead(column3) == LOW) return false;

  return true;
}

int *getBtn() {
  int matrix[2];

  if (digitalRead(row1) == HIGH) matrix[0] = 0;
  if (digitalRead(row2) == HIGH) matrix[0] = 1;
  
  if (digitalRead(column1) == HIGH) matrix[1] = 0;
  if (digitalRead(column2) == HIGH) matrix[1] = 1;
  if (digitalRead(column3) == HIGH) matrix[1] = 2;

  return matrix;
}
