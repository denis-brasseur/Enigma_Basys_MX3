# Enigma_Basys_MX3

A implementation of the Enigma machine using the Basys MX3 of Diligent as the machine and communicating with the computer via UART.


## Fonctionnement de la machine :
Lorsque l'opérateur tape une lettre sur le clavier, un signal électrique est envoyé sur le circuit correspondant à la lettre.
1. Ce signal passe par un tableau de connexions, et la lettre est éventuellement changée selon un ensemble de paires connectées par l'opérateur.
2. Le signal passe par une série de rotors.
3. Chaque rotor peut éventuellement bouger avant de traiter le signal.
4.Chaque rotor décale le signal d'une valeur indiquée par la lettre visible par une petite fenetre au dessus du rotor.
5. Chaque rotor substitue la valeur de la lettre par une autre selon un schéma de cablage propre à chaque type de rotor.
6. Le signal passe par un réflecteur qui substitue la lettre par une autre, selon un ensemble de paires fixes.
7. Le signal repasse alors par les rotors en sens inverse, cette fois-ci sans mouvement des rotors, à chaque fois substitué et décalé de façon inverse par rapport au sens initial.
8. Le signal repasse alors par le tableau de connexions, et est éventuellement transformé par les mêmes connexions.
9. Le signal allume une ampoule correspondant à une lettre, celle du message chiffré correspondant au message clair que l'on cherche à envoyer.
