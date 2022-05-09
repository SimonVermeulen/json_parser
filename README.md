# json_parser
json parser in c

Simple parser de json réalisé en c.

Valeurs de chaque type :
    1- objets
    2- double
    3- int
    4- string
    Tableau : type * 10
    
Ce parser de json ne gêre pas les tableaux de tableaux.
Les objets sont gêrés sous forme de liste chaînées et les tableaux d'objets sont donc renvoyés sous forme de tableaux de liste chaînées

Ce parser de json gère les erreurs possibles pouvant être présentes dans un fichier json fourni par l'utilisateur et renverra une erreur si nécessaire.
