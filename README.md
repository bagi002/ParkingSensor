PARKING SENZOR

Sistem obrade koji je implementiran u sistemu zasnovan je na sihronizaciji preko tajmera
jedan interval tajmera traje 10 000 mikro sekundi

Sve operacije izvrsavaju se sihrnizovano nakon odredjenog broja intervala
ocitavanje senzora vrsi se na svaki drugi prekid tajmera
azuriranje interfejsa svaki 8
a zvuka svaki 10 ti

na tom principu zasniva RT sistem , mana sistema je sto nije u stanuju da prekidne beskonacu petlju ili funkcije koje se mozda iz nekog razloga previse dugo izvrsavaju


Sam interfejs se sastoji iz
Ultra Sonicnog senzora
Zujalice
te indikiatora blizine koji se sastoji iz 4 diode

Implementirane se dvije mini Biblioteke i to
ParkingSE.h
    Ona implementira rad sa senzorom u svrhu integrisanja u parkin senzor omogucavajuci inicijalizaciju senozra
    Ocitavanje senszora , gdje se posebna paznja posvecuje odbacivanju losih i laznih mjerenja 
    te omogucava da drugom djelu sistema vrati tacnu i stabilnu udaljenost senzora od prepreke 

ParkingIN.h
    Ova biblioteka zaduzena je za implementiranje sqamog interfejsa 
        Indikacija blizine prepreci se prikazuje putem 4 led diode
        Takodje zvucni signal upozorava na blizinu prepreke
        Ovaj dio biblioteke podatke preuzima od senzorskog djela