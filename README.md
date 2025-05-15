# push\_swap

**push\_swap** est un programme en C qui trie une liste d'entiers avec le moins d'opérations possible, en utilisant uniquement deux piles et un ensemble d'instructions limitées. Il met en œuvre des algorithmes de tri optimisés pour différents scénarios de données.

---

## 📦 Contenu

* `push_swap/` : source principale du programme.
* `checker/` : vérifie que les instructions triées sont valides.
* `libft/` : bibliothèque utilitaire personnalisée de fonctions C.
* `Makefile` : compilation des programmes (`push_swap`, `checker`).

---

## 🧠 Objectif

* Trier une pile d'entiers donnée en utilisant les opérations autorisées.
* Produire une suite d'instructions minimale pour effectuer ce tri.
* Optimiser le nombre d'opérations selon la taille de l'entrée :

  * 100 nombres : < 700 opérations
  * 500 nombres : < 5 500 opérations

---

## ⚙️ Instructions disponibles

* `sa`, `sb`, `ss` : swaps
* `pa`, `pb` : pushes
* `ra`, `rb`, `rr` : rotations
* `rra`, `rrb`, `rrr` : rotations inversées

---

## 🚀 Utilisation

```bash
$ make
$ ./push_swap 4 3 2 1
sa
pb
ra
...
```

### ✔️ Vérification

```bash
$ ARG="4 3 2 1"
$ ./push_swap $ARG | ./checker $ARG
OK
```

---

## ⚠️ Gestion des erreurs

Le programme doit afficher `Error` en cas de :

* Paramètres non numériques
* Nombres hors `int`
* Doublons

## 📚 Compétences développées

* Algorithmes de tri et complexité algorithmique
* Manipulation de piles
* Gestion fine de la mémoire
* Optimisation de code C
