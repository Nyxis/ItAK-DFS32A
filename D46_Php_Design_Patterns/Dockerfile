# Utiliser l'image PHP 8.2
FROM php:8.2-cli

# Installer les dépendances de Composer
COPY --from=composer:2 /usr/bin/composer /usr/bin/composer

# Définir le répertoire de travail
WORKDIR /app

# Copier tous les fichiers du projet dans le conteneur
COPY . .

# Installer les dépendances PHP du projet
RUN composer install

# Exposer le port si nécessaire (ex: port 80 ou autre)
EXPOSE 80

# Commande par défaut
CMD ["php", "src/Application/main.php"]
