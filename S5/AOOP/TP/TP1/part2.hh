#pragma once
#include <iostream>
#include <array>

int nb_voyelles(std::string s); // compte le nombre de voyelles
bool est_Palindrome(std::string s); // verifie si la chaine en paramètre est un palindrome
void chiffrer( std::string &s); // chiffre la chaine en paramètre
unsigned int extract_number(std::string s); // extrait le nombre contenu dans la chaine
void dechiffrer( std::string &s); // déchiffre la chaine en paramètre
