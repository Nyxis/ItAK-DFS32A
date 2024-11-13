FROM gcc:latest

# Arguments pour l'utilisateur
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID
ARG PW=docker

# Mettre à jour et installer les outils nécessaires
RUN apt update && apt install -y vim gdb nano sudo

# Créer l'utilisateur et configurer les alias et les permissions
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers \
    && echo 'alias ls="ls --color"' >> /root/.bashrc \
    && echo 'alias ls="ls --color"' >> "/home/${USERNAME}/.bashrc" \
    && echo 'alias gcc="gcc -W -Wextra -Wall -Werror -std=c99"' >> "/home/${USERNAME}/.bashrc" \
    && echo 'alias cc="gcc -W -Wextra -Wall -Werror -std=c99"' >> "/home/${USERNAME}/.bashrc"

# Copier les fichiers de l'utilisateur dans le dossier de travail
COPY . /workspaces/Cshell

# Changer de répertoire
WORKDIR /workspaces/Cshell

# Passer à l'utilisateur non-root
USER ${USER_UID}:${USER_GID}
