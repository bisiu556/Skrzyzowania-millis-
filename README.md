🚦 Światła skrzyżowań z wykorzystaniem millis()

Projekt przedstawia prosty system sterowania czterema światłami sygnalizacyjnymi za pomocą Arduino. Każde skrzyżowanie posiada światło czerwone i zielone.

Program wykorzystuje funkcję millis() do odmierzania czasu, dzięki czemu nie jest używana funkcja delay().

📌 Opis działania

Program steruje kolejno czterema skrzyżowaniami:

Skrzyżowanie 1 otrzymuje światło zielone na 5 sekund.

Wszystkie światła zmieniają się na czerwone na 2 sekundy.

Skrzyżowanie 2 otrzymuje światło zielone na 5 sekund.

Wszystkie światła są czerwone przez 2 sekundy.

Skrzyżowanie 3 otrzymuje światło zielone na 5 sekund.

Wszystkie światła są czerwone przez 2 sekundy.

Skrzyżowanie 4 otrzymuje światło zielone na 5 sekund.

Wszystkie światła są czerwone przez 2 sekundy.

Cykl rozpoczyna się ponownie od skrzyżowania 1.

Schemat działania
Wszystkie czerwone
       │
       │ 2 s
       ▼
Skrzyżowanie 1
       │
       │ 5 s
       ▼
Wszystkie czerwone
       │
       │ 2 s
       ▼
Skrzyżowanie 2
       │
       │ 5 s
       ▼
Wszystkie czerwone
       │
       │ 2 s
       ▼
Skrzyżowanie 3
       │
       │ 5 s
       ▼
Wszystkie czerwone
       │
       │ 2 s
       ▼
Skrzyżowanie 4
       │
       │ 5 s
       ▼
Wszystkie czerwone
       │
       │ 2 s
       ▼
     POWRÓT
       │
       └──────────► Skrzyżowanie 1

🔌 Podłączenie
Skrzyżowanie	Zielone	Czerwone
1	Pin 13	Pin 12
2	Pin 4	Pin 2
3	Pin 8	Pin 7
4	Pin 10	Pin 9

Każda dioda LED powinna być podłączona przez odpowiedni rezystor ograniczający prąd.

⏱️ Czasy działania

Czasy są zdefiniowane na początku programu:

const unsigned long CZERWONE = 2000;
const unsigned long ZIELONE  = 5000;


Oznacza to:

CZERWONE = 2000 → 2000 ms = 2 sekundy

ZIELONE = 5000 → 5000 ms = 5 sekund

Zmiana tych wartości pozwala łatwo zmienić długość poszczególnych etapów.

🕐 Wykorzystanie millis()

Program nie korzysta z:

delay();


Zamiast tego wykorzystuje funkcję:

millis();


millis() zwraca liczbę milisekund, które upłynęły od uruchomienia Arduino.

Czas jest sprawdzany za pomocą działania:

if (aktualnyCzas - poprzedniCzas >= ZIELONE)


Program sprawdza więc, czy od rozpoczęcia aktualnego etapu minęło już 5 sekund.

Po zmianie etapu czas jest zapisywany ponownie:

poprzedniCzas = aktualnyCzas;


Dzięki temu każdy etap ma własny czas rozpoczęcia.

🔄 System etapów

Zmiennej:

int etap = 0;


używa się do określenia aktualnego etapu programu.

Etap	Stan	Czas
0	Wszystkie czerwone	2 s
1	Zielone 1	5 s
2	Wszystkie czerwone	2 s
3	Zielone 2	5 s
4	Wszystkie czerwone	2 s
5	Zielone 3	5 s
6	Wszystkie czerwone	2 s
7	Zielone 4	5 s

Po wykonaniu etapu 7:

etap = 0;


program wraca do początku cyklu.

🔴 Funkcja wszystkieCzerwone()

Program posiada osobną funkcję:

void wszystkieCzerwone()


Jej zadaniem jest wyłączenie wszystkich zielonych diod i włączenie wszystkich czerwonych.

void wszystkieCzerwone() 
{
  digitalWrite(Green1, LOW);
  digitalWrite(Green2, LOW);
  digitalWrite(Green3, LOW);
  digitalWrite(Green4, LOW);

  digitalWrite(Red1, HIGH);
  digitalWrite(Red2, HIGH);
  digitalWrite(Red3, HIGH);
  digitalWrite(Red4, HIGH);
}


Dzięki temu nie trzeba wielokrotnie wpisywać tych samych instrukcji w różnych miejscach programu.

🧠 Dlaczego millis() zamiast delay()?

Funkcja delay() zatrzymuje wykonywanie programu na określony czas. W przypadku millis() Arduino może w tym czasie wykonywać inne instrukcje.

Przykładowo:

delay(5000);


zatrzymałoby program na 5 sekund.

Natomiast:

if (millis() - poprzedniCzas >= 5000)


tylko sprawdza, czy upłynęło 5 sekund, bez zatrzymywania całej pętli loop().

Jest to szczególnie przydatne w większych projektach, w których w tym samym czasie trzeba obsługiwać przyciski, czujniki lub inne elementy.

🛠️ Wymagane elementy

Arduino

8 diod LED:

4 × zielona

4 × czerwona

8 rezystorów ograniczających prąd

płytka stykowa

przewody połączeniowe

kabel USB

▶️ Uruchomienie

Podłącz diody LED zgodnie z tabelą pinów.

Podłącz Arduino do komputera.

Otwórz kod w Arduino IDE.

Wybierz odpowiednią płytkę Arduino oraz port.

Wgraj program.

Po uruchomieniu wszystkie światła powinny być czerwone.

Po 2 sekundach pierwsze skrzyżowanie otrzyma światło zielone.

Program będzie wykonywał cykl automatycznie.

