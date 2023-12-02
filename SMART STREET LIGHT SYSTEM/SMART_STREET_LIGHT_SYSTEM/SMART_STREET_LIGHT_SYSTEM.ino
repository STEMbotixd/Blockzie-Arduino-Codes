int IR1 = 2;
int IR2 = 3;
int IR3 = 4;

int l1 = 8;
int l2 = 9;
int l3 = 10;
void setup() {
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
}

void loop() {
  int t1 = digitalRead(IR1);
  int t2 = digitalRead(IR2);
  int t3 = digitalRead(IR3);

  if (t1 != 1) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, LOW);
    while (t2 != 1) {

      digitalWrite(l1, HIGH);
      digitalWrite(l2, HIGH);
      t2 = digitalRead(IR2);
    }

    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    delay(10);
  }

  if (t2 == 1) {
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
    while (t3 != 1) {
      digitalWrite(l2, HIGH);
      digitalWrite(l3, HIGH);
      t3 = digitalRead(IR3);
    }

    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);

    delay(10);
  }

  if (t3 == 1) {
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, HIGH);
    delay(2000);
  }

  else {

    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  }
  delay(1);
}
