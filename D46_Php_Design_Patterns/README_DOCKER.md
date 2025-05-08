Guide pour lancer le projet PHP Design Patterns avec Docker
 Le projet lit un fichier product.json et affiche une liste de produits avec un prix supérieur à 100 €. 
 Instructions pour Windows.
Ce projet utilise le langage PHP pour lire des données de produits (comme leur nom, type et prix) depuis un fichier JSON, puis affiche uniquement les produits coûtant plus de 100 €. Docker est utilisé pour exécuter le projet dans un environnement isolé.
(dsl j'ai mis php 8.2 et pas 8.4 ...)
Pré-requis:
Docker Desktop installé et lancé sur Windows 
Powershell lancé
Le projet situé dans le dossier :C:\Users\fLisowski\Desktop\fork\ItAK-DFS32A\D46_Php_Design_Patterns.
(Sinon modifier les chemins ou utiliser __DIR__)

Dans PowerShell, tapez la commande suivante pour aller dans le dossier du projet :
cd C:\Users\fLisowski\Desktop\fork\ItAK-DFS32A\D46_Php_Design_Patterns

composer update

vérifiez que le fichier vendor/autoload.php existe avec :
Get-ChildItem vendor/autoload.php

Vous devriez voir une ligne comme :
Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----        07/05/2025     18:49            748 autoload.php

docker compose build --no-cache
Vous devriez voir :
✔ Service php  Built

docker compose up --remove-orphans

Appuyez sur Entrée. Cette commande :

Affiche les produits de product.json ayant un prix supérieur à 100 €.

Pour arrêter le projet, appuyez sur Ctrl+C dans PowerShell. Cela arrête le conteneur. Si vous voulez supprimer le conteneur pour libérer de l’espace, tapez :
docker compose down

Date de test : 08/05/2025
Environnement : Windows, Docker Desktop, PowerShell
Dossier du projet : C:\Users\fLisowski\Desktop\fork\ItAK-DFS32A\D46_Php_Design_Patterns

