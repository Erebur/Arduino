# ZumoShield

- [ZumoShield](#zumoshield)
  - [Ziel](#ziel)
  - [Features](#features)
    - [Fahren](#fahren)
    - [Musik spielen](#musik-spielen)
  - [Code snippets](#code-snippets)
  - [Gelöste Probleme](#gelöste-probleme)
    - [Async stuff](#async-stuff)
    - [Buzzer & Bluetooth pins haben sich berührt](#buzzer--bluetooth-pins-haben-sich-berührt)
    - [Input & Output Bluetooth pins oder so.... PIN 6 & 7?](#input--output-bluetooth-pins-oder-so-pin-6--7)
  - [Nicht gelöste Probleme](#nicht-gelöste-probleme)
    - [Name & Password](#name--password)
  - [Mögliche weitere Features](#mögliche-weitere-features)
    - [Selbst fahren](#selbst-fahren)
    - [Kurvenradius verstellen](#kurvenradius-verstellen)

## Ziel

Unser Ziel war, ein kleiner Sumoroboter, über eine Handyapp zu steuern.

## Features

Muster:
- {Feature} : {Button}

### Fahren

- Richtung
  - Vorne : `w`
  - Hinten : `s`
  - Rechts vorne : `d`
  - Links vorne : `a`
  - Rechts hinten : `x`
  - Links hinten : `z`

- Fahrverhalten
  - Stoppen : `q`
  - Schneller : `+`
  - Langsamer : `-`

### Musik spielen

Mehrere Songs von [hier](https://github.com/robsoncouto/arduino-songs) über Buzzer

- play music : `m`
- pause music : `p`
- next song : `n`

## Code snippets

Fahren:

  - Gerade
    ```c

    ```

  - Kurven
    ```c

    ```

Musik spielen:
```c

```

Bluetooth Connection:
```c

```

## Gelöste Probleme

### Async stuff

Das zweit Größte Problem war, dass man während das Musikspielen, keine andere Aktionen ausfuhren konnte.

Leider gibt es bei ein Mikrocontroller keine Möglichkeit, mehrere Threads zu erstellen oder Code async laufen zu lassen.

Um das Problem umzugehen, haben wir anstatt einen `delay()` eine if Abfrage erstellt, die bei jeden Durchlauf prüft, ob die Benötigte Zeit schon vergangen ist.

```c
 if (noteDuration + lastNote < currentTime){
      ...
      lastNote = currentTime;
      ...
    }
```


### Buzzer & Bluetooth pins haben sich berührt

Bei jeden Einschalten des Boards, hat man festgestellt, dass der Buzzer kurz angeht.

Grund war, eine Berührung zwischen den Pins am Bluetoothboard & die Pins des Buzzers.

Das Problem wurde gelöst, indem man noch eine Reihe am {Pins?} installiert hat, die den ganzen Bluetoothmodul höher gestellt hat.

[](BILD)


### Input & Output Bluetooth pins oder so.... PIN 6 & 7?

Lorem ipsum ich habe kein Plan bro.
Ullamco eu occaecat cillum esse laborum sint deserunt labore dolor non labore fugiat ex magna.


## Nicht gelöste Probleme

### Name & Password


## Mögliche weitere Features

### Selbst fahren

### Kurvenradius verstellen
