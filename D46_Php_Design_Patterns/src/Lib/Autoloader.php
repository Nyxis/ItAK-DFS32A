<?php

class Autoloader
{
    public function __construct(
        private ?string $dossierRacineProjet = null
    ) {
        $this->dossierRacineProjet = $this->dossierRacineProjet ?: realpath(__DIR__ . '/../src');

        spl_autoload_register(function ($nomClasse) {
            $cheminClasse = sprintf('%s%s%s.php',
                $this->dossierRacineProjet,
                DIRECTORY_SEPARATOR,
                str_replace('\\', DIRECTORY_SEPARATOR, $nomClasse)
            );

            foreach (glob($cheminClasse) as $fichierPhp) {
                require_once($fichierPhp);
            }
        });
    }
}