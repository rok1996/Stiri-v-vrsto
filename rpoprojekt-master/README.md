# Štiri v vrsto
Študentski projekt

Predmet: Razvoj programske opreme  
Študijski program: Računalništvo in Informacijske tehnologije 2. letnik  
Fakulteta za Elektrotehniko, Računalništvo in Informatiko  
Univerza v Mariboru  
2016/2017

## Avtori
Na projektu so sodelovali:
  - Rok Petrovič (vodja projekta)
  - Žan Petrovič
  - Vladimir Rujević

Asistent na predmetu: asist. Bojan Žlahtič

## Igra
###Pravila igre "Štiri v vrsto":
Igro igrajo dva igralca ki na smeno ustavljajo žetone v stolpce igralneg polja. Žetoni padaju na dno stolpca, če je stolpec poln se potez zavrne. Zmagovalec je prvi igralec ki poveže štiri susedna žetona v kateremkoli smeru, če je polje polno in ni zmagovalca je igra nedoločena.  
V primeru da je zmagovalec povezal več kot štiri susednih žetonov se šteje ena zmaga.  
V primeru napačneg poteza, obstaja možnost da se vrne poslednji potez.
Ko se igra zaključi se igralno polje zaklene, vsak poskus poteza se zavrne. Število zmag je zapomnjeno in se prenaša na naslednjo igro.

# Instalacija in zagon
## Windows
TODO: Kako se instalira Qt runtime na Windows?
## Linux
Program Štiri v vrsto uporablja Qt5, na veliko Linux distribucij je Qt5 že naložen na sistem.  
Če ni naložen, lahko se naloži na naslednji način:
### Ubuntu in Debian based
```bash
sudo apt update
sudo apt install qt5-default qttools5-dev-tools
```
### Arch Linux
```bash
pacman -Syy
pacman -S qt5-base qt5-tools
```
