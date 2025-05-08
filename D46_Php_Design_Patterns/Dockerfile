# Utiliser l'image PHP 8.2
FROM php:8.2-cli

# Installer les dépendances de Composer
COPY --from=composer:2 /usr/bin/composer /usr/bin/composer

# Définir le répertoire de travail
WORKDIR /app

# Copier tous les fichiers du projet dans le conteneur
COPY . .

# Vérifier le contenu
RUN ls -la /app && ls -la /app/src/Application && ls -la /app/product.json || echo "product.json not found"

# Installer les dépendances PHP du projet et vérifier autoload.php
RUN composer install && ls -la vendor/ && test -f vendor/autoload.php && echo "vendor/autoload.php exists" || echo "vendor/autoload.php missing"

# Commande par défaut
CMD ["php", "src/Application/Main.php"]