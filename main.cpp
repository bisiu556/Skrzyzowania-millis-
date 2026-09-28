// ŒWIAT£A SKRZY¯OWANIA z funkcja millis()

// Skrzy¿owanie 1
const int Green1 = 13;
const int Red1   = 12;

// skrzy¿owanie 2
const int Green2 = 4;
const int Red2   = 2;

// skrzy¿owanie 3
const int Green3 = 8;
const int Red3   = 7;

// skrzy¿owanie 4
const int Green4 = 10;
const int Red4   = 9;


// czas
const unsigned long CZERWONE = 2000;
const unsigned long ZIELONE  = 5000;


// aktualny etap
int etap = 0;

//czas rozpoczêcia aktualnego etapu
unsigned long poprzedniCzas = 0;


void setup()
{

  pinMode(Green1, OUTPUT);
  pinMode(Red1, OUTPUT);

  pinMode(Green2, OUTPUT);
  pinMode(Red2, OUTPUT);

  pinMode(Green3, OUTPUT);
  pinMode(Red3, OUTPUT);

  pinMode(Green4, OUTPUT);
  pinMode(Red4, OUTPUT);

  // na pocz¹tku wszystkie czerwone
  wszystkieCzerwone();

  poprzedniCzas = millis();
}


void loop()
{

  unsigned long aktualnyCzas = millis();

  // ETAP 0 - wszystkie czerwone przez 2 s

  if (etap == 0) {

    if (aktualnyCzas - poprzedniCzas >= CZERWONE) {

      digitalWrite(Red1, LOW);
      digitalWrite(Green1, HIGH);

      poprzedniCzas = aktualnyCzas;
      etap = 1;
    }
  }


  // ETAP 1 - Green1 przez 5 s

  else if (etap == 1)
  {

    if (aktualnyCzas - poprzedniCzas >= ZIELONE)
    {

      wszystkieCzerwone();

      poprzedniCzas = aktualnyCzas;
      etap = 2;
    }
  }

  // ETAP 2 - wszystkie czerwone przez 2 s

  else if(etap == 2) {

    if(aktualnyCzas - poprzedniCzas >= CZERWONE)
    {

      digitalWrite(Red2, LOW);
      digitalWrite(Green2, HIGH);

      poprzedniCzas = aktualnyCzas;
      etap = 3;
    }
  }

  // ETAP 3 - Green2 przez 5 s

  else if(etap == 3)
  {

    if(aktualnyCzas - poprzedniCzas >= ZIELONE)
    {

      wszystkieCzerwone();

      poprzedniCzas = aktualnyCzas;
      etap = 4;
    }
  }


  // ETAP 4 - wszystkie czerwone przez 2 s

  else if(etap == 4)
  {

    if(aktualnyCzas - poprzedniCzas >= CZERWONE)
    {

      digitalWrite(Red3, LOW);
      digitalWrite(Green3, HIGH);

      poprzedniCzas = aktualnyCzas;
      etap = 5;
    }
  }

  // ETAP 5 - Green3 przez 5 s

  else if (etap == 5)
  {

    if (aktualnyCzas - poprzedniCzas >= ZIELONE)
    {

      wszystkieCzerwone();

      poprzedniCzas = aktualnyCzas;
      etap = 6;
    }
  }
  // ETAP 6 - wszystkie czerwone przez 2 s

  else if (etap == 6)
  {
    if (aktualnyCzas - poprzedniCzas >= CZERWONE)
    {

      digitalWrite(Red4, LOW);
      digitalWrite(Green4, HIGH);

      poprzedniCzas = aktualnyCzas;
      etap = 7;
    }
  }


  // ETAP 7 - Green4 przez 5 s

  else if(etap == 7)
  {

    if(aktualnyCzas - poprzedniCzas >= ZIELONE)
    {

      wszystkieCzerwone();

      poprzedniCzas = aktualnyCzas;
      etap = 0;
    }
  }
}

// WSZYSTKIE CZERWONE

void wszystkieCzerwone()
{

  // Wy³¹cz wszystkie zielone
  digitalWrite(Green1, LOW);
  digitalWrite(Green2, LOW);
  digitalWrite(Green3, LOW);
  digitalWrite(Green4, LOW);

  // W³¹cz wszystkie czerwone
  digitalWrite(Red1, HIGH);
  digitalWrite(Red2, HIGH);
  digitalWrite(Red3, HIGH);
  digitalWrite(Red4, HIGH);
}
